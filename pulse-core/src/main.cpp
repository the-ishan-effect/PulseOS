#include <iomanip>
#include <iostream>
#include <sstream>

#include "pulse/system/SystemInfo.hpp"

std::string formatUptime(double uptimeSeconds)
{
    const long totalSeconds =
        static_cast<long>(uptimeSeconds);

    const long days =
        totalSeconds / 86400;

    const long hours =
        (totalSeconds % 86400) / 3600;

    const long minutes =
        (totalSeconds % 3600) / 60;

    std::ostringstream output;

    if (days > 0)
    {
        output << days << "d ";
    }

    if (hours > 0 || days > 0)
    {
        output << hours << "h ";
    }

    output << minutes << "m";

    return output.str();
}

int main()
{
    pulse::SystemInfo system;

    const auto snapshot =
        system.collect();

    std::cout << "=============================\n";
    std::cout << " PulseOS v0.3.0\n";
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

    std::cout << std::fixed
              << std::setprecision(1);

    std::cout << "CPU Load : "
              << snapshot.cpuUsagePercent
              << "%\n";

    std::cout << "Memory   : "
              << snapshot.usedMemoryMB
              << " MB / "
              << snapshot.totalMemoryMB
              << " MB"
              << '\n';

    std::cout << "Usage    : "
              << snapshot.memoryUsagePercent
              << "%\n";

    std::cout << "Uptime   : "
              << formatUptime(
                     snapshot.uptimeSeconds)
              << '\n';

    return 0;
}