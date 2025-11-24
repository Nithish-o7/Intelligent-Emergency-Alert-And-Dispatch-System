#include <WiFi.h>
#include <Firebase_ESP_Client.h> // Firebase ESP32 client library
#include "addons/TokenHelper.h"   // Token helper for auth
#include "addons/RTDBHelper.h"    // Realtime database helper

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- Replace with your WiFi credentials ---
#define WIFI_SSID " "
#define WIFI_PASSWORD " "

// --- Firebase Project Configuration ---
#define API_KEY "AIzaSyCXZfxOxeR3QnFuybzTKTYnKmqKH5vUGDo"
#define DATABASE_URL "https://project-gaurdian-default-rtdb.asia-southeast1.firebasedatabase.app"

// --- Hardware & Device Definition ---
#define BUTTON_PIN 13 // GPIO 13 for button
#define BUZZER_PIN 12 // GPIO 12 for the Buzzer
#define DEVICE_ID "IEADS 01" 

// OLED Display Configuration
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// --- Firebase Global Objects ---
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// --- Global Variables ---
unsigned long buttonPressStartTime = 0;
bool isButtonPressed = false;
bool alertSent = false;
unsigned long buzzerStartTime = 0;
bool buzzerActive = false;

// --- Display Functions ---

void showReadyScreen() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 10);
    display.println("Device ID:");
    display.setTextSize(2);
    display.setCursor(0, 25);
    display.println(DEVICE_ID);
    display.setTextSize(1);
    display.setCursor(25, 52);
    display.println("SYSTEM READY");
    display.display();
}

// ✅ MODIFIED: This function now draws the loading bar animation
void showKeepHoldScreen(unsigned long elapsedTime) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 15);
    display.println("KEEP HOLD");

    // Draw the progress bar outline
    display.drawRect(0, 45, SCREEN_WIDTH, 10, SSD1306_WHITE);

    // Calculate and draw the filled part of the progress bar
    // It will take 3000ms to fill the whole bar
    int progress = map(elapsedTime, 0, 3000, 0, SCREEN_WIDTH);
    if (progress > 0) {
        display.fillRect(0, 45, progress, 10, SSD1306_WHITE);
    }
    
    display.display();
}


void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 28);
  display.println("Initializing...");
  display.display();
  delay(1000);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("\nConnected with IP: " + WiFi.localIP());

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  
  Serial.println("Signing in to Firebase...");
  while (auth.token.uid == "") {
    Firebase.signUp(&config, &auth, "", "");
    Serial.print(".");
    delay(1000); 
  }
  Serial.print("\nSigned in successfully. UID: ");
  Serial.println(auth.token.uid.c_str());

  if (Firebase.ready()) {
    if (Firebase.RTDB.setString(&fbdo, "/device/info/id", DEVICE_ID)) {
      Serial.println("Device ID registered successfully.");
    } else {
      Serial.println("Failed to register Device ID: " + fbdo.errorReason());
    }
  }

  showReadyScreen();
}

void loop() {
  if (Firebase.ready()) {

    if (buzzerActive && (millis() - buzzerStartTime >= 10000)) {
        digitalWrite(BUZZER_PIN, LOW);
        buzzerActive = false;
        Serial.println("Buzzer stopped.");
        showReadyScreen();
    }

    int buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == LOW) {
      if (!isButtonPressed) {
        isButtonPressed = true;
        buttonPressStartTime = millis();
        Serial.println("Button press detected. Hold for 3 seconds to send alert...");
      }

      // ✅ MODIFIED: Continuously update the loading animation while the button is held and no alert is sent
      if (isButtonPressed && !alertSent) {
          unsigned long elapsedTime = millis() - buttonPressStartTime;
          showKeepHoldScreen(elapsedTime);
      }
      
      // Check if the button has been held for 3 seconds AND an alert hasn't been sent yet.
      if (isButtonPressed && (millis() - buttonPressStartTime >= 3000) && !alertSent) {
        alertSent = true;

        // --- TRIGGER ALERT SEQUENCE ---
        
        String alertPath = "/panic_alerts/" + String(millis());
        FirebaseJson json;
        json.set("message", "Panic Button Activated!");
        json.set("deviceId", DEVICE_ID);
        Serial.println("Hold successful! Sending panic alert...");
        Firebase.RTDB.setJSON(&fbdo, alertPath, &json);
        
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 25);
        display.println("ALERT SENT");
        display.display();

        Serial.println("Activating buzzer for 10 seconds...");
        digitalWrite(BUZZER_PIN, HIGH);
        buzzerActive = true;
        buzzerStartTime = millis();
      }
    } 
    else { // buttonState is HIGH
      // If the button is released before an alert is sent, go back to the ready screen.
      if (isButtonPressed && !alertSent) {
        showReadyScreen();
      }
      isButtonPressed = false;
      alertSent = false;
    }
  }
}
