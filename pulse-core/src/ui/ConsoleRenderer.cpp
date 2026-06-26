#include "pulse/ui/ConsoleRenderer.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

namespace
{

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

void printSection(const std::string& title)
{
    std::cout << '\n'
              << title
              << '\n'
              << "──────────────────────────────────────────────────────────────\n";
}

void printField(
    const std::string& label,
    const std::string& value)
{
    std::cout << std::left
              << std::setw(14)
              << label
              << value
              << '\n';
}

} // namespace

namespace pulse
{

void ConsoleRenderer::render(
    const SystemSnapshot& snapshot) const
{
    std::cout << std::fixed
              << std::setprecision(1);

    std::cout
        << "╔══════════════════════════════════════════════════════════════╗\n";
    std::cout
        << "║                        PulseOS v0.4.0                       ║\n";
    std::cout
        << "╚══════════════════════════════════════════════════════════════╝\n";

    // ================= SYSTEM =================

    printSection("SYSTEM");

    printField("Hostname", snapshot.hostname);
    printField("OS", snapshot.osName);
    printField("Kernel", snapshot.kernelVersion);

    // ================= CPU =================

    printSection("CPU");

    printField("Model", snapshot.cpuModel);

    printField(
        "Threads",
        std::to_string(snapshot.logicalCPUs));

    std::ostringstream cpuUsage;

    cpuUsage << std::fixed
             << std::setprecision(1)
             << snapshot.cpuUsagePercent
             << " %";

    printField(
        "Usage",
        cpuUsage.str());

    // ================= MEMORY =================

    printSection("MEMORY");

    std::ostringstream memoryInfo;

    memoryInfo << snapshot.usedMemoryMB
               << " MB / "
               << snapshot.totalMemoryMB
               << " MB";

    printField(
        "Used",
        memoryInfo.str());

    std::ostringstream memoryUsage;

    memoryUsage << std::fixed
                << std::setprecision(1)
                << snapshot.memoryUsagePercent
                << " %";

    printField(
        "Usage",
        memoryUsage.str());

    // ================= DISK =================

    printSection("DISK");

    std::ostringstream diskInfo;

    diskInfo << snapshot.usedDiskGB
             << " GB / "
             << snapshot.totalDiskGB
             << " GB";

    printField(
        "Used",
        diskInfo.str());

    std::ostringstream diskUsage;

    diskUsage << std::fixed
              << std::setprecision(1)
              << snapshot.diskUsagePercent
              << " %";

    printField(
        "Usage",
        diskUsage.str());

    // ================= UPTIME =================

    printSection("UPTIME");

    printField(
        "Running",
        formatUptime(snapshot.uptimeSeconds));
}

} // namespace pulse