#include "pulse/system/SystemInfo.hpp"
#include "pulse/system/CPUInfo.hpp"
#include "pulse/system/MemoryInfo.hpp"
#include "pulse/system/UptimeInfo.hpp"
#include "pulse/common/FileReader.hpp"
#include "pulse/common/KeyValueParser.hpp"
#include "pulse/system/DiskInfo.hpp"
#include "pulse/system/CPULoadInfo.hpp"
#include <sys/utsname.h>
#include <unistd.h>
namespace pulse
{

SystemSnapshot SystemInfo::collect() const
{
    SystemSnapshot snapshot;

    char hostname[256]{};

    if (gethostname(hostname, sizeof(hostname)) == 0)
    {
        snapshot.hostname = hostname;
    }
    else
    {
        snapshot.hostname = "Unknown";
    }
try
{
    const std::string osRelease =
        FileReader::read("/etc/os-release");

    auto document =
        KeyValueParser::parse(osRelease);

    snapshot.osName =
        document.get("PRETTY_NAME");

    // Remove surrounding quotes if present
    if (!snapshot.osName.empty() &&
        snapshot.osName.front() == '"' &&
        snapshot.osName.back() == '"')
    {
        snapshot.osName =
            snapshot.osName.substr(
                1,
                snapshot.osName.size() - 2);
    }
}
catch (...)
{
    snapshot.osName = "Unknown";
}
struct utsname kernelInfo{};

if (uname(&kernelInfo) == 0)
{
    snapshot.kernelVersion = kernelInfo.release;
}
else
{
    snapshot.kernelVersion = "Unknown";
}
CPUInfo cpuInfo;

const auto cpuSnapshot =
    cpuInfo.collect();

snapshot.cpuModel =
    cpuSnapshot.model;

snapshot.logicalCPUs =
    cpuSnapshot.logicalThreads;
CPULoadInfo cpuLoadInfo;

const auto cpuLoadSnapshot =
    cpuLoadInfo.collect();

snapshot.cpuUsagePercent =
    cpuLoadSnapshot.usagePercent;
MemoryInfo memoryInfo;

const auto memorySnapshot =
    memoryInfo.collect();

snapshot.totalMemoryMB =
    memorySnapshot.totalMemoryMB;

snapshot.availableMemoryMB =
    memorySnapshot.availableMemoryMB;

snapshot.usedMemoryMB =
    memorySnapshot.usedMemoryMB;

snapshot.memoryUsagePercent =
    memorySnapshot.usagePercent;
DiskInfo diskInfo;

const auto diskSnapshot =
    diskInfo.collect();

snapshot.totalDiskGB =
    diskSnapshot.totalSpaceGB;

snapshot.usedDiskGB =
    diskSnapshot.usedSpaceGB;

snapshot.freeDiskGB =
    diskSnapshot.freeSpaceGB;

snapshot.diskUsagePercent =
    diskSnapshot.usagePercent;
UptimeInfo uptimeInfo;

const auto uptimeSnapshot =
    uptimeInfo.collect();

snapshot.uptimeSeconds =
    uptimeSnapshot.uptimeSeconds;
return snapshot;
}

}