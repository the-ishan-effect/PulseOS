#include "pulse/system/SystemInfo.hpp"

#include <unistd.h>

namespace pulse
{

std::string SystemInfo::getHostname() const
{
    char hostname[256];

    if(gethostname(hostname, sizeof(hostname)) == 0)
        return hostname;

    return "Unknown";
}

}