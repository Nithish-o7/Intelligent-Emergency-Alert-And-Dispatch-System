
## Overview

This repository implements the **Proactive IoT‑Based AI Framework for Real‑Time Public Safety Response**, integrating IoT telemetry, AI verification, and dispatch services to reduce incident response time and improve citizen safety. All contributions must preserve reliability, security, and sub‑second decision latency in production paths.

***

## 1. Project Setup

Follow these steps to bring the stack up locally with safe defaults.

- **Clone the repository**

  ```bash
  git clone https://github.com/your-org/public-safety-ai-framework.git
  cd public-safety-ai-framework
  ```

- **Install dependencies**

  - Node.js / JavaScript services (Core API, Dispatch Engine):

    ```bash
    npm install
    ```

  - Python services (AI Verification Model, Data Processing):

    ```bash
    pip install -r requirements.txt
    ```

- **Configure environment**

  - Create `.env` in the project root.
  - Copy from `.env.example` and update:
    - Database URL and credentials (use local/dev instances only).
    - IoT platform endpoints (brokers, MQTT/WebSocket, or HTTP gateways).
    - AI model endpoints (local model server or mock URL for development).
  - Never commit secrets; use `.env` only and keep it git‑ignored.

- **Run services and simulators**

  ```bash
  # Core API server
  npm run dev

  # IoT simulator for telemetry testing
  npm run iot:simulator
  ```

Ensure services start without errors and that simulated events flow end‑to‑end through verification and dispatch paths before you begin changes.

***

## 2. Code Contribution Workflow

This project uses a **Fork + Feature Branch + PR** workflow to keep the `main` branch stable.

1. **Fork and clone**

   - Fork the official repo to your GitHub account.
   - Clone your fork and add the upstream remote:

     ```bash
     git clone https://github.com/<your-username>/public-safety-ai-framework.git
     cd public-safety-ai-framework
     git remote add upstream https://github.com/your-org/public-safety-ai-framework.git
     ```

2. **Create a focused branch**

   Use purpose‑driven prefixes:

   - `feat/` for new capabilities
   - `fix/` for bug fixes
   - `refactor/` for internal code changes

   ```bash
   git checkout -b fix/dispatch-latency-optimization
   ```

3. **Develop and keep in sync**

   - Make small, logically grouped changes.
   - Periodically sync with `upstream/main`:

     ```bash
     git fetch upstream
     git rebase upstream/main
     ```

4. **Run tests locally**

   - For JS services:

     ```bash
     npm test
     ```

   - For Python services:

     ```bash
     pytest
     ```

   Changes that break tests, add failing linters, or degrade latency in critical loops will not be merged.

5. **Use conventional commits**

   Follow the Conventional Commits style for clarity and automation.

   Examples:

   - `feat(dispatch): support multi-agency routing`
   - `fix(alert-verification): use haversine for unit proximity`
   - `refactor(iot-ingest): simplify telemetry parser`

   ```bash
   git commit -m "fix(dispatch): calculate proximity using haversine formula to reduce latency"
   ```

6. **Push and open a PR**

   ```bash
   git push origin fix/dispatch-latency-optimization
   ```

   Then open a Pull Request to `your-org/public-safety-ai-framework:main`, filling in the PR template with:
   - Problem statement.
   - Scope of change.
   - Testing performed (including latency/throughput notes where relevant).

***

## 3. Code Standards

Reliability and security are non‑negotiable in a real‑time public safety context.

### Documentation

- Use **JSDoc** for TypeScript/JavaScript services and **docstrings** for Python.
- Document:
  - Public functions, classes, and modules.
  - Any non‑obvious algorithm (e.g., route scoring, deduplication logic, anomaly thresholds).
- Keep inline comments short and focused on *why*, not *what*.

### Security

- Sanitize and validate **all** external input (HTTP, MQTT, WebSockets, message queues).
- Enforce:
  - HTTPS/TLS for APIs and dashboards.
  - Authentication for internal control endpoints.
- Never log secrets or full tokens; redact sensitive fields.
- Treat IoT data as untrusted even from “internal” networks.

### Performance & Real‑Time Behavior

- Target **sub‑second latency** for:
  - Ingest → verify → dispatch decision loops.
  - Core alert routing and escalation paths.
- Prefer:
  - O(1)/O(log n) data structures in hot paths.
  - Streaming / incremental processing over large in‑memory batches.
- Measure impact when touching:
  - AI model invocation.
  - Geospatial calculations (distance, routing).
  - Database queries in dispatch or verification loops.

Add micro‑benchmarks or basic timing logs in dev when optimizing critical paths, then remove or guard them for production.

### Readability

- Favor clear, explicit code over clever one‑liners.
- Keep functions focused; extract helpers when logic grows beyond a few clearly related steps.
- Align with existing style (lint/format where configured) and keep service boundaries clean (e.g., no direct DB access from UI, no business logic in controllers).

***

## 4. Reporting Bugs

Use the repository **Issue Tracker** with the **Bug Report** template.

Include:

- **Title**: Clear and scoped, e.g., `High duplicate alerts from camera stream on region-3`.
- **Service**: Name the affected component, e.g., `alert-verification-service`, `dispatch-engine`, `iot-gateway`.
- **Environment**: Local, staging, or production; include versions/branches.
- **Steps to reproduce**:
  - Exact API calls or simulator commands.
  - Relevant payloads (scrub sensitive data).
  - Expected vs. actual behavior.
- **Impact on safety/performance**:
  - Does it delay dispatch?
  - Does it cause missed or false alerts?
  - Approximate frequency and severity.

Issues that clearly describe impact on response time or incident handling will be prioritized.

***

## 5. Suggesting Features

Use the **Feature Request** template in the Issue Tracker.

Describe:

- **Problem**: The operational gap (e.g., “False alarms from sensor X are consuming responder time”).
- **Proposed solution**: What you want to add or change (new endpoint, AI rule, dashboard view).
- **Why it matters**:
  - How it improves citizen safety or responder efficiency.
  - How it aligns with mission goals (fewer missed incidents, better triage, faster routing).
- **Real‑time impact**:
  - Expected effect on latency, throughput, and resource usage.
  - Any new external dependencies (e.g., external AI model, mapping API) and their failure modes.

If you plan to implement the feature yourself, state that in the issue so maintainers can coordinate scope and design with you before you start.

***
