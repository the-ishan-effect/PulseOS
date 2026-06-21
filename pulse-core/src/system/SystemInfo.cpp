#include "pulse/system/SystemInfo.hpp"
#include "pulse/common/FileReader.hpp"
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

    const std::string key = "PRETTY_NAME=\"";

    const auto pos = osRelease.find(key);

    if (pos != std::string::npos)
    {
        const auto start = pos + key.length();

        const auto end =
            osRelease.find('"', start);

        if (end != std::string::npos)
        {
            snapshot.osName =
                osRelease.substr(start,
                                 end - start);
        }
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