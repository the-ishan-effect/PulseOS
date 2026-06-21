#include "pulse/system/SystemInfo.hpp"
#include "pulse/common/FileReader.hpp"
#include "pulse/common/KeyValueParser.hpp"
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
    return snapshot;
}

}