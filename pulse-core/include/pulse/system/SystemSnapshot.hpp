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
    long totalMemoryMB{};
    double uptimeSeconds{};
};

}