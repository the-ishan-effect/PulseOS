# PulseOS

> **A modular Linux system monitoring tool built with modern C++, Linux, POSIX APIs, and CMake.**

PulseOS is a lightweight and extensible command-line application that provides real-time insights into Linux system resources. It interacts directly with the Linux `/proc` filesystem and POSIX APIs to collect information about the operating system, hardware, CPU, memory, disk, and system uptime without relying on external utilities.

The project follows a modular architecture where each subsystem is responsible for collecting a specific category of system information, while the presentation layer remains completely independent of the data collection layer. This separation improves maintainability, scalability, and ease of extension.

---

## Features

- Operating System Detection
- Kernel Version Detection
- Hostname Detection
- CPU Model & Logical Thread Information
- Real-Time CPU Utilization Monitoring
- Memory Usage Monitoring
- Disk Usage Monitoring
- System Uptime Monitoring
- Modular Console Renderer
- Reusable Parsing & File Utilities
- Feature-Based Git Workflow
- CMake Build System

---

## Architecture

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
      ┌───────────┬──────────┬──────────┬──────────┬────────────┐
      │           │          │          │          │
   CPUInfo   CPULoadInfo  MemoryInfo  DiskInfo  UptimeInfo
```

---

## Project Structure

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
├── LICENSE
└── README.md
```

---

## Technologies Used

- **Language:** Modern C++ (C++17)
- **Platform:** Linux
- **System APIs:** POSIX
- **Build System:** CMake
- **Version Control:** Git & GitHub

---

## Building PulseOS

### Clone the repository

```bash
git clone https://github.com/the-ishan-effect/PulseOS.git
```

### Navigate to the project

```bash
cd PulseOS
```

### Create a build directory

```bash
mkdir build
cd build
```

### Configure and build

```bash
cmake ..
cmake --build .
```

### Run

```bash
./pulse-core/pulseos
```

---

## Sample Output

```
╔══════════════════════════════════════════════════════════════╗
║                        PulseOS v0.4.0                       ║
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

## Roadmap

- [x] Operating System Detection
- [x] Kernel Version Detection
- [x] CPU Information
- [x] CPU Utilization Monitoring
- [x] Memory Monitoring
- [x] Disk Monitoring
- [x] System Uptime
- [x] Console Renderer
- [ ] Network Monitoring
- [ ] Watch Mode
- [ ] JSON Export
- [ ] Unit Testing
- [ ] GitHub Actions CI
- [ ] Release v1.0

---

## Design Principles

PulseOS is built around a modular architecture that separates data collection from presentation.

Each system component is responsible for collecting a single category of information, while the rendering layer formats and displays the collected data. This design improves maintainability, enables easier testing, and simplifies future feature additions.

---

## Future Improvements

- Network Interface Monitoring
- Process Information
- Battery Monitoring
- JSON Export
- Watch Mode (`--watch`)
- Configuration File Support
- Unit & Integration Tests
- Continuous Integration

---

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.