#include "pulse/system/MemoryInfo.hpp"

#include "pulse/common/FileReader.hpp"
#include "pulse/common/KeyValueParser.hpp"

namespace pulse
{

MemorySnapshot MemoryInfo::collect() const
{
    MemorySnapshot snapshot;

    const std::string memInfo =
        FileReader::read("/proc/meminfo");

    const auto document =
    KeyValueParser::parse(
        memInfo,
        ':');

    const auto totalMemoryKB =
        std::stol(document.get("MemTotal"));

    const auto availableMemoryKB =
        std::stol(document.get("MemAvailable"));

    snapshot.totalMemoryMB =
        totalMemoryKB / 1024;

    snapshot.availableMemoryMB =
        availableMemoryKB / 1024;

    snapshot.usedMemoryMB =
        snapshot.totalMemoryMB -
        snapshot.availableMemoryMB;

    snapshot.usagePercent =
        (static_cast<double>(
             snapshot.usedMemoryMB) /
         snapshot.totalMemoryMB) * 100.0;

    return snapshot;
}

}