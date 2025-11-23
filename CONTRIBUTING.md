Contributing Guide

Thank you for considering contributing to the Proactive IoT Based AI Framework for Real Time Public Safety Response! Your help is vital in making high-density tourist zones safer through intelligent, real-time response systems.

Getting Started

1. Project Setup

To get a development environment running:

Clone the Repository:

git clone [https://github.com/your-org/public-safety-ai-framework.git](https://github.com/your-org/public-safety-ai-framework.git)
cd public-safety-ai-framework


Install Dependencies:

# For backend services (Node.js, Python, etc.)
npm install
# or
pip install -r requirements.txt


Configure Environment Variables:

Create a file named .env in the root directory.

Copy the contents of the provided .env.example into your new .env file.

Fill in the necessary values for database connections, IoT broker endpoints, and AI model URLs. Note: For initial development, you may use placeholder values for external services like AI_VERIFICATION_ENDPOINT or mock them locally.

Start Services:

# Start the core API server
npm run dev
# or a separate IoT simulator for testing telemetry data
npm run iot:simulator


2. Reporting Bugs

If you find a bug in the code, please help us by submitting an issue in our issue tracker.

When submitting a bug, please include:

A clear and descriptive title.

The exact steps to reproduce the issue (the "bug reproduction steps").

The expected behavior.

The actual behavior observed.

Your operating system, environment versions (Node.js, Python, etc.), and which service (e.g., alert-verification-service, dispatch-engine) the bug affects.

3. Suggesting Enhancements and Features

We welcome ideas for new features or enhancements! This project involves complex components like AI model integration and proximity dispatch.

Check Existing Issues: Before submitting, please check if a similar suggestion already exists.

Create a Discussion/Issue: Use the issue tracker to suggest your idea.

Detailed Proposal: Provide details on:

What problem the feature solves (the "Why").

How the feature should work from a user/system perspective (the "What").

Any potential impact on existing data models or performance, especially related to real-time processing and dispatch latency.

4. Code Contribution Workflow

We follow a standard Fork & Pull Request workflow:

Fork the repository to your own GitHub account.

Create a new branch for your feature or fix. Use descriptive names like feat/add-new-sensor-type or fix/dispatch-bug.

git checkout -b your-new-branch-name


Make your changes. Ensure your code adheres to existing coding styles (e.g., linting rules).

Test your changes. All new code must have appropriate unit and integration tests. Run all tests locally before committing:

npm test
# or
pytest


Commit your changes with clear, descriptive commit messages.

git commit -m "fix(dispatch): Ensure correct geometry calculation for proximity"


Push your branch to your Fork.

Open a Pull Request (PR) against the main branch of the original repository.

5. Code Standards

Readability: Code should be easy to read and understand.

Documentation: Functions, classes, and complex logic must be documented using JSDoc (for JavaScript/TypeScript) or Python docstrings.

Security: Given the public safety nature of the project, prioritize secure coding practices, especially for API keys, user authentication, and data transmission (always use HTTPS/TLS).

Performance: Code must be optimized for real-time performance, minimizing latency in the AI verification and dispatch loops.
