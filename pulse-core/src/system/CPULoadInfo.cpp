#include "pulse/system/CPULoadInfo.hpp"

#include "pulse/common/FileReader.hpp"

#include <chrono>
#include <sstream>
#include <thread>

namespace
{

struct CPUStats
{
    long user{};
    long nice{};
    long system{};
    long idle{};
    long iowait{};
    long irq{};
    long softirq{};
    long steal{};
};

CPUStats readStats()
{
    const std::string content =
        pulse::FileReader::read("/proc/stat");

    std::istringstream stream(content);

    std::string cpuLabel;

    CPUStats stats;

    stream >> cpuLabel
           >> stats.user
           >> stats.nice
           >> stats.system
           >> stats.idle
           >> stats.iowait
           >> stats.irq
           >> stats.softirq
           >> stats.steal;

    return stats;
}

long totalTime(const CPUStats& stats)
{
    return stats.user +
           stats.nice +
           stats.system +
           stats.idle +
           stats.iowait +
           stats.irq +
           stats.softirq +
           stats.steal;
}

long idleTime(const CPUStats& stats)
{
    return stats.idle +
           stats.iowait;
}

}

namespace pulse
{

CPULoadSnapshot CPULoadInfo::collect() const
{
    const auto first =
        readStats();

    std::this_thread::sleep_for(
        std::chrono::milliseconds(1000));

    const auto second =
        readStats();

    const auto deltaTotal =
        totalTime(second) -
        totalTime(first);

    const auto deltaIdle =
        idleTime(second) -
        idleTime(first);

    CPULoadSnapshot snapshot;

    snapshot.usagePercent =
        100.0 *
        (deltaTotal - deltaIdle) /
        deltaTotal;

    return snapshot;
}

}