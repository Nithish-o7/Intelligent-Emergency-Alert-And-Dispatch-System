## 🚨 Overview

This repository implements the **Proactive IoT‑Based AI Framework for Real‑Time Public Safety Response**, integrating **IoT telemetry**, **AI verification**, and **intelligent dispatch services** to reduce incident response time and improve citizen safety. ⚙️📡🤖🚑  
All contributions must preserve **reliability**, **security**, and **sub‑second decision latency** in production paths to support real‑time public safety operations. ⏱️🛡️

***

## 🧩 1. Project Setup

Follow these steps to bring the stack up locally with safe defaults. 🧪💻

### 🔽 Clone the repository

```bash
git clone https://github.com/your-org/public-safety-ai-framework.git
cd public-safety-ai-framework
```

### 📦 Install dependencies

- **Node.js / JavaScript services** (Core API, Dispatch Engine):

  ```bash
  npm install
  ```

- **Python services** (AI Verification Model, Data Processing):

  ```bash
  pip install -r requirements.txt
  ```

### 🔐 Configure environment

- Create a `.env` file in the project root.  
- Copy from `.env.example` and update:
  - 🗄️ Database URL and credentials (use local/dev instances only).
  - 📡 IoT platform endpoints (brokers, MQTT/WebSocket, or HTTP gateways).
  - 🧠 AI model endpoints (local model server or mock URL for development).
- ❗ **Never commit secrets**; keep `.env` git‑ignored and local to your machine.

### ▶️ Run services and simulators

```bash
# Core API server
npm run dev

# IoT simulator for telemetry testing
npm run iot:simulator
```

✅ Ensure services start without errors and that simulated events flow end‑to‑end through **ingest → verification → dispatch** before you begin changes.

***

## 🔁 2. Code Contribution Workflow

This project uses a **Fork + Feature Branch + PR** workflow to keep the `main` branch stable and production‑ready. 🌳🚦

### 1️⃣ Fork and clone

- Fork the official repo to your GitHub account.  
- Clone your fork and add the upstream remote:

```bash
git clone https://github.com/<your-username>/public-safety-ai-framework.git
cd public-safety-ai-framework
git remote add upstream https://github.com/your-org/public-safety-ai-framework.git
```

### 2️⃣ Create a focused branch

Use purpose‑driven prefixes:

- ✨ `feat/` – new capabilities  
- 🐛 `fix/` – bug fixes  
- 🧼 `refactor/` – internal code changes  

```bash
git checkout -b fix/dispatch-latency-optimization
```

### 3️⃣ Develop and keep in sync

- Make **small, logically grouped** commits.  
- Regularly sync with `upstream/main` to avoid merge hell:

```bash
git fetch upstream
git rebase upstream/main
```

### 4️⃣ Run tests locally

- For JS services:

  ```bash
  npm test
  ```

- For Python services:

  ```bash
  pytest
  ```

❌ Changes that break tests, introduce lint errors, or **degrade latency in critical loops** will not be merged.

### 5️⃣ Use conventional commits

Follow **Conventional Commits** for clarity and tooling compatibility. 🧾

Examples:

- `feat(dispatch): support multi-agency routing`  
- `fix(alert-verification): use haversine for unit proximity`  
- `refactor(iot-ingest): simplify telemetry parser`  

```bash
git commit -m "fix(dispatch): calculate proximity using haversine formula to reduce latency"
```

### 6️⃣ Push and open a PR

```bash
git push origin fix/dispatch-latency-optimization
```

Then open a Pull Request to `your-org/public-safety-ai-framework:main`, and fill in the PR template with:

- 🧩 Problem statement  
- 📚 Scope of change  
- 🧪 Testing performed (include **latency/throughput notes** where relevant)

***

## 🧱 3. Code Standards

Reliability and security are **non‑negotiable** in a real‑time public safety context. 🚓🛡️

### 📘 Documentation

- Use **JSDoc** for TypeScript/JavaScript and **Python docstrings** for Python.  
- Document:
  - Public functions, classes, and modules.  
  - Non‑obvious algorithms (e.g., route scoring, deduplication logic, anomaly thresholds).  
- Keep inline comments focused on **why**, not just **what**. 💬

### 🔒 Security

- Sanitize and validate **all external input** (HTTP, MQTT, WebSockets, message queues).  
- Enforce:
  - 🔐 HTTPS/TLS for APIs and dashboards.  
  - 🔑 Authentication and authorization for internal control endpoints.  
- Never log secrets or full tokens; redact sensitive fields.  
- Treat **all IoT data as untrusted**, even on internal networks. 🛰️

### ⚡ Performance & Real‑Time Behavior

- Target **sub‑second latency** for:
  - Ingest → verify → dispatch decision loops.  
  - Core alert routing and escalation paths.  
- Prefer:
  - O(1)/O(log n) structures in hot paths.  
  - Streaming / incremental processing over large in‑memory batches.  
- Carefully measure impact when touching:
  - 🧠 AI model invocation.  
  - 🗺️ Geospatial calculations (distance, routing).  
  - 🗃️ Database queries in verification or dispatch loops.

You may add light **dev‑only** micro‑benchmarks or timing logs while optimizing, then remove or guard them for production. ⏱️

### 📖 Readability

- Favor **clear, explicit** code over clever one‑liners.  
- Keep functions focused; extract helpers for multi‑step or repeated logic.  
- Respect existing style (formatters/linters) and maintain clean service boundaries:
  - No direct DB access from UI.  
  - No complex business logic in controllers.

***

## 🐞 4. Reporting Bugs

Use the repository **Issue Tracker** with the **Bug Report** template. 🧾

Include:

- 🏷️ **Title**: Clear and scoped, e.g. `High duplicate alerts from camera stream on region-3`.  
- 🧩 **Service**: e.g. `alert-verification-service`, `dispatch-engine`, `iot-gateway`.  
- 🌐 **Environment**: Local, staging, or production; include versions/branches.  
- 🔁 **Steps to reproduce**:
  - Exact API calls or simulator commands.  
  - Relevant payloads (scrub sensitive data).  
  - Expected vs. actual behavior.  
- 🚑 **Impact on safety/performance**:
  - Does it delay dispatch?  
  - Does it cause missed or false alerts?  
  - Approximate frequency and severity.

🧊 Issues that clearly describe impact on **response time** or **incident handling** are prioritized.

***

## 💡 5. Suggesting Features

Use the **Feature Request** template in the Issue Tracker. 💬✨

Describe:

- ❓ **Problem**: The operational gap (e.g., “False alarms from sensor X are consuming responder time”).  
- 🛠️ **Proposed solution**: New endpoint, AI rule, dashboard view, workflow change, etc.  
- 🎯 **Why it matters**:
  - How it improves citizen safety or responder efficiency.  
  - How it supports mission goals (fewer missed incidents, better triage, faster routing).  
- ⚙️ **Real‑time impact**:
  - Expected effect on latency, throughput, and resource usage.  
  - Any new external dependencies (e.g., AI API, mapping service) and their failure modes.

If you plan to implement the feature yourself, mention it so maintainers can help refine scope and design before you start. 🤝


