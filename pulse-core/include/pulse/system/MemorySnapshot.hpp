#pragma once

namespace pulse
{

struct MemorySnapshot
{
    long totalMemoryMB{};
    long availableMemoryMB{};
    long usedMemoryMB{};
    double usagePercent{};
};

}