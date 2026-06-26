#pragma once

#include <string>

namespace pulse
{

struct SystemSnapshot
{
    std::string hostname;
    std::string osName;
    std::string kernelVersion;

    std::string cpuModel;
    unsigned int logicalCPUs{};
    double cpuUsagePercent{};
    long totalMemoryMB{};
    long availableMemoryMB{};
    long usedMemoryMB{};
    double memoryUsagePercent{};
    long totalDiskGB{};
    long usedDiskGB{};
    long freeDiskGB{};
    double diskUsagePercent{};
    double uptimeSeconds{};
};

}