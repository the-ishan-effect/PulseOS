# PulseOS

> **A modular Linux system monitoring tool built with modern C++, POSIX APIs, and CMake.**

PulseOS is a lightweight and extensible command-line system monitoring tool that provides real-time insights into Linux system resources. It interacts directly with Linux kernel interfaces and POSIX APIs to collect information about the operating system, hardware, CPU, memory, disk, and system uptime without relying on external utilities.

The project is designed with a modular architecture where each subsystem is responsible for collecting a specific category of system information, while the presentation layer remains completely independent of the data collection layer. This separation makes PulseOS easy to maintain, extend, and test.

---

# Features

* Operating System Detection
* Kernel Version Detection
* Hostname Detection
* CPU Model & Logical Thread Information
* Real-Time CPU Utilization Monitoring
* Memory Usage Monitoring
* Disk Usage Monitoring
* System Uptime Monitoring
* Modular Console Renderer
* Reusable Parsing & File Utilities
* Modular CMake Build System
* Feature-Based Git Workflow

---

# Architecture

```
                    PulseOS

                    main.cpp
                         │
                         ▼
                ConsoleRenderer
                         ▲
                         │
                 SystemSnapshot
                         ▲
                         │
                    SystemInfo
      ┌───────────┬──────────┬──────────┬──────────┐
      │           │          │          │          │
   CPUInfo   CPULoadInfo  MemoryInfo  DiskInfo  UptimeInfo
```

---

# Project Structure

```
PulseOS/
│
├── pulse-core/
│   ├── include/
│   │   ├── common/
│   │   ├── system/
│   │   └── ui/
│   │
│   ├── src/
│   │   ├── common/
│   │   ├── system/
│   │   └── ui/
│   │
│   └── tests/
│
├── docs/
├── architecture/
├── screenshots/
├── CMakeLists.txt
└── README.md
```

---

# Technologies

* Modern C++ (C++17)
* Linux
* POSIX APIs
* CMake
* Git & GitHub

---

# Build Instructions

```bash
git clone https://github.com/<your-username>/PulseOS.git

cd PulseOS

mkdir build

cd build

cmake ..

cmake --build .

./pulse-core/pulseos
```

---

# Sample Output

```
╔══════════════════════════════════════════════════════════════╗
║                        PulseOS v0.4.0                        ║
╚══════════════════════════════════════════════════════════════╝

SYSTEM
──────────────────────────────────────────────────────────────
Hostname      LAPTOP-7OAH5S7A
OS            Ubuntu 26.04 LTS
Kernel        6.18.33.1-microsoft-standard-WSL2

CPU
──────────────────────────────────────────────────────────────
Model         12th Gen Intel(R) Core(TM) i5-1235U
Threads       12
Usage         9.1 %

MEMORY
──────────────────────────────────────────────────────────────
Used          542 MB / 7776 MB
Usage         7.0 %

DISK
──────────────────────────────────────────────────────────────
Used          53 GB / 1006 GB
Usage         5.3 %

UPTIME
──────────────────────────────────────────────────────────────
Running       15h 50m
```

---

# Roadmap

* [x] Operating System Detection
* [x] Kernel Version Detection
* [x] CPU Information
* [x] CPU Utilization
* [x] Memory Monitoring
* [x] Disk Monitoring
* [x] Uptime Monitoring
* [x] Console Renderer
* [ ] Network Monitoring
* [ ] Watch Mode
* [ ] JSON Export
* [ ] Unit Testing
* [ ] Continuous Integration

---

# License

This project is licensed under the MIT License.
