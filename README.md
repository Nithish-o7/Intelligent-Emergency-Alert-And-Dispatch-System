<h1 align="center">🚨 Intelligent Emergency Alert and Dispatch System </h1>

<p align="center">
  Next-gen, real-time emergency alert system for crowded tourist zones.<br>  
  <b>Fast, reliable, AI-verified public safety response</b>
</p>
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">
<p align="center">
  <a href="LICENSE"><img src="https://img.shields.io/badge/License-MIT-green.svg" alt="MIT License"/></a>
  <img src="https://img.shields.io/badge/Node.js-Backend-blue.svg" alt="Node.js"/>
  <img src="https://img.shields.io/badge/Python-Backend-yellow.svg" alt="Python"/>
  <img src="https://img.shields.io/badge/React-Frontend-blue.svg" alt="React.js"/>
  <img src="https://img.shields.io/badge/ESP32-Hardware-lightgrey.svg" alt="ESP32"/>
</p>


<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

📖 Table of Contents

<a href="#Project-Demonstration"> Project Demonstration </a>

<a href="#summary"> Summary </a>

<a href="#project-overview"> Project Overview </a>

<a href="#key-features">Key Features</a>

<a href="#why-ieads"> Why IEADS ? </a>

<a href="#tech-stack"> Tech Stack </a>

<a href="#Road-map"> Roadmap </a>

<a href="#project-structure"> Project Structure </a>

<a href="#show-your-support"> Show Your Support </a>

<a href="#license"> License </a>

<a href="#project-admin"> Project Admin </a>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="Project-Demonstration">📚 Project Demonstration</h2>

[![Watch the video](https://img.youtube.com/vi/3-xu5Ft77Qk/maxresdefault.jpg)](https://youtu.be/3-xu5Ft77Qk)

### [View Project Demo](https://youtu.be/3-xu5Ft77Qk)

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="summary"> 📝 Summary </h2>

The Intelligent Emergency Alert Dispatch System (IEADS) is an advanced, end-to-end public safety infrastructure built specifically for dynamic, high-density environments like tourist attractions and crowded urban areas. It integrates physical IoT panic buttons with a robust AI Framework that analyzes alert veracity in real-time. By leveraging proximity-aware dispatch, the system ensures verified, geo-located alerts are routed instantly to the nearest first responders and informed civilians, drastically reducing response times and minimizing the impact of false alarms. IEADS offers a comprehensive solution for real-time public safety response, bridging the gap between incident detection and efficient resource allocation.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="project-overview"> 🚩 Project Overview </h2>

The IEADS project is a modular, open-source framework designed to create a resilient public safety network. It addresses the critical need for rapid and reliable emergency response in challenging environments where fragmented communication and high false alarm rates delay assistance.

The system operates across three core layers:

IoT Layer (Edge): Dedicated, physical panic buttons (using ESP32) are deployed strategically to ensure immediate, barrier-free alert activation. They are engineered for high-resilience communication, using redundant protocols like Wi-Fi and/or LoRaWAN for data transmission.

AI & Cloud Layer (Core): A centralized cloud backend responsible for ingesting, verifying, and prioritizing alerts. This layer utilizes Machine Learning models to analyze situational metadata and differentiate genuine crises from false or nuisance triggers.

Dispatch Layer (Action): The system uses real-time geospatial data to identify the closest authorized responders (Police, Fire) and initiates targeted, proximity-based notifications via external APIs (Twilio) and the web dashboard, ensuring optimal resource allocation.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="key-features">🏆 Key Features</h2>

🛠️ Instant Activation Nodes (IoT): Custom-designed, low-power ESP32-based devices that transmit highly accurate, geo-tagged emergency signals. The system supports multi-modal communication (Wi-Fi, LoRaWAN) for network resilience and guaranteed signal delivery.

🤖 AI-Driven Alert Verification: A critical Machine Learning component analyzes incident metadata (location, time, node usage history, co-occurrence with other data streams) to assign a Trust Score to each alert. This capability drastically reduces false alarms and conserves critical emergency service resources.

📍 Proximity-Aware Smart Dispatch: Automatically calculates the nearest available first responder (based on their real-time or last-known GPS location) and issues geo-fenced notifications via the Twilio API, providing precise coordinates and incident details for the fastest possible response route.

🌐 Unified Cloud Architecture (Firebase): Manages real-time data ingestion, status tracking, and stores comprehensive historical incident logs, providing the scalable backbone for all AI and dispatch services.

📊 Real-time Operations Dashboard: A dedicated React-based interface provides public safety officials with a live map view (integrating Google Maps API) of all active incidents, responder locations, alert verification scores, and response status tracking.

🔒 Secure & Modular Design: Built with a focus on data security, system resilience, and a modular code architecture to allow easy adaptation and deployment in diverse geographical and regulatory environments.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="why-ieads"> 💡 Why IEADS? </h2>

In densely populated public spaces, every second counts. Traditional emergency response systems often suffer from response delays due to manual communication, fragmented dispatch processes, and a high volume of false alarms that drain valuable resources. IEADS provides a solution by:

Eliminating Human Latency: Alerts are initiated physically and verified computationally, bypassing manual phone calls, language barriers, and location sharing struggles common in panic situations.

Optimized Resource Allocation: By filtering out non-critical alerts using the AI Trust Score, emergency services can dedicate their attention and resources only to verifiable, high-priority incidents, leading to higher success rates.

Accuracy and Speed: Ensuring that the closest available responder is notified immediately with precise GPS coordinates and a verified incident profile, transforming a fragmented manual process into a coordinated, real-time operation.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="tech-stack"> 📦 Tech Stack </h2>

| Hardware | Firebase | Node.js, Python | Notification Service API | React.js | Google Maps API |
|-------|----------|-----------------|------------|----------|-----------------|
| ESP32 DevKit C(C++), OLED Display, Solar Panel, Rechargeable Battery, Panic Button, Addressable LED Ring, Buzzer, LoRa Module  | Cloud backend, DB, Functions | Backend, ML verification | Real-Time Dispatch Notifications (SMS, Call, Push) | Web dashboard | Geofencing & Visualization |

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="Road-map"> 🚀 Roadmap </h2>

[x] Hardware prototype (panic button & firmware)

[x] Cloud alert endpoint & database

[ ] AI-based alert filtering (PoC)

[ ] Proximity SMS/Call integration

[ ] Real-time monitoring dashboard

[ ] Pilot deployment & feedback

See docs/roadmap.md for detailed info and to suggest improvements!

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="project-structure">🗂 Project Structure</h2>

<p>The IEADS repository is organized into five primary layers: Firmware, Backend, Frontend, Hardware, and Documentation to ensure modularity and scalability.</p>

<pre>
├── .gitignore                      # Files and folders to ignore in Git
├── .env.example                    # Template for required environment variables (DB, API Keys, etc.)
├── CONTRIBUTING.md                 # Internal Development Guide and Code Workflow
├── CODE_OF_CONDUCT.md              # Team Behavior Policy
├── README.md                       # High-level project description and Tech Stack
│
├── firmware/                       # Root for all ESP32/Arduino code (C/C++)
│   ├── main/                       # The production and current development firmware
│   │   ├── IEADS_Prototype_Base.ino    # BASE PROTOTYPE (Loading/Display/Connectivity test baseline)
│   │   ├── IEADS_Final_Integrated.ino  # FINAL Production Code (Full feature set: Button, MQTT, State Machine)
│   │   └── secrets.h                   # (Local, uncommitted configuration like Wi-Fi credentials)
│   │
│   ├── component_tests/            # Individual test sketches for hardware components
│   │   ├── sketch_ButtonCheck/     # Isolation test for the Panic Button
│   │   ├── sketch_BuzzerCheck/     # Isolation test for the Buzzer
│   │   ├── sketch_Display\_V1/      # Display library validation
│   │   ├── sketch_FirebaseConnectivity/ # MQTT/Cloud connection test
│   │   ├── sketch_GSM_Module/      # GSM/cellular connectivity test
│   │   └── ... (All other specific component test sketches)
│   │
│   └── libraries/                  # Custom or modified Arduino libraries (if needed)
│
├── frontend/                       # Root for the Web Dashboard and Visualization
│   ├── RealTimeDashboard.html      # (The single-file web dashboard for dispatchers)
│   └── assets/                     # Frontend resources (CSS, Icons, etc.)
│
├── backend/                        # Node.js/Python server-side services
│   ├── dispatch_engine/            # Service responsible for Proximity-Aware Dispatch
│   │   └── index.js (or .py)
│   └── ai_verification_service/    # Service for ML Alert Verification
│       └── model\_service.py
│
├── docs/                           # Primary folder for documentation
│   └── Technical_Design_Document.md
│   └── Project_Report.md
│   └── Deployment_Guide.md
</pre>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="suggestions-feedback">💡 Suggestions & Feedback</h2>

Feel free to open issues or discussions if you have any feedback, feature suggestions, or want to collaborate!

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="show-your-support">🙌 Show Your Support</h2>

If you find IEADS project helpful, give it a star! ⭐ to support more such educational initiatives:

⭐ Starring the repository

🐦 Sharing on social media

💬 Telling your friends and colleagues

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">

<h2 id="license">📄 License</h2>

This project is licensed under the MIT License - see the [`License`](https://github.com/Nithish-o7/Intelligent-Emergency-Alert-And-Dispatch-System/blob/Dev/LICENSE) file for details.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">




<h2 id="project-admin" align="center">🧑‍💻 Project Admin</h2>
<div align="center">
<table>
<tr>
<td align="center">
<a href="https://github.com/Nithish-o7"><img src="https://avatars.githubusercontent.com/u/206350645?v=4" height="140px" width="140px" alt="Nithish Kanna"></a>
<br />
<sub><b>Nithish Kanna</b></sub>
<br />
<a href="https://www.linkedin.com/in/nithish-kanna-d-292b98299/"><img src="https://github-production-user-asset-6210df.s3.amazonaws.com/73993775/278833250-adb040ea-e3ef-446e-bcd4-3e8d7d4c0176.png" width="45px" height="45px" alt="LinkedIn Profile Link"></a>
</td>
</tr>
</table>
</div>
<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%">
<h3 align="center">👨‍💻 Built with ❤️ by IEADS Team</h3>
<p align="center">
<a href="https://www.google.com/search?q=https://github.com/Nithish-o7/Intelligent-Emergency-Alert-and-Dispatch-System-SIH-25">🌟 Star on GitHub</a>
</p>

<!-- Optimized Footer: Back to Top link is part of the final wavy footer -->

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=65&section=footer"/>
<p align="center">
<a href="#top" style="font-size: 18px; padding: 8px 16px; display: inline-block; border: 1px solid #ccc; border-radius: 6px; text-decoration: none;">
⬆️ Back to Top
</a>
</p>
