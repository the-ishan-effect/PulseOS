#pragma once

namespace pulse
{

struct DiskSnapshot
{
    double totalSpaceGB{};
    double usedSpaceGB{};
    double freeSpaceGB{};
    double usagePercent{};
};

}