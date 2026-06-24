#pragma once

#include <string>

namespace pulse
{

struct CPUSnapshot
{
    std::string vendor;
    std::string model;
    std::string architecture;

    int physicalCores{};
    int logicalThreads{};
};

}