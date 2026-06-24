#include "pulse/system/UptimeInfo.hpp"

#include "pulse/common/FileReader.hpp"

#include <sstream>

namespace pulse
{

UptimeSnapshot UptimeInfo::collect() const
{
    UptimeSnapshot snapshot;

    const std::string uptimeText =
        FileReader::read("/proc/uptime");

    std::istringstream stream(uptimeText);

    stream >> snapshot.uptimeSeconds;

    return snapshot;
}

}