#include "pulse/system/SystemInfo.hpp"

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

    return snapshot;
}

}