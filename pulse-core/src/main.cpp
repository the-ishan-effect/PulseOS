#include <iostream>
#include <iomanip>
#include "pulse/system/SystemInfo.hpp"

int main()
{
    pulse::SystemInfo system;

    const auto snapshot = system.collect();

    std::cout << "=============================\n";
    std::cout << " PulseOS v0.2.2\n";
    std::cout << "=============================\n\n";

    std::cout << "Hostname : "
              << snapshot.hostname
              << '\n';

    std::cout << "OS       : "
              << snapshot.osName
              << '\n';

    std::cout << "Kernel   : "
              << snapshot.kernelVersion
              << '\n';

    std::cout << "CPU      : "
              << snapshot.cpuModel
              << '\n';

    std::cout << "Threads  : "
              << snapshot.logicalCPUs
              << '\n';
    
    std::cout << "Memory   : "
          << snapshot.usedMemoryMB
          << " MB / "
          << snapshot.totalMemoryMB
          << " MB"
          << '\n';
std::cout << std::fixed
          << std::setprecision(1);
std::cout << "Usage    : "
          << snapshot.memoryUsagePercent
          << '%'
          << '\n';

    return 0;
}