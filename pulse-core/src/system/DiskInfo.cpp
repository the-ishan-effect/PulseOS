#include "pulse/system/DiskInfo.hpp"

#include <sys/statvfs.h>
#include <stdexcept>

namespace pulse
{

DiskSnapshot DiskInfo::collect() const
{
    DiskSnapshot snapshot;

    struct statvfs filesystem{};

    if (statvfs("/", &filesystem) != 0)
    {
        throw std::runtime_error(
            "Failed to retrieve filesystem information.");
    }

    const unsigned long long totalBytes =
        static_cast<unsigned long long>(filesystem.f_blocks) *
        filesystem.f_frsize;

    const unsigned long long freeBytes =
        static_cast<unsigned long long>(filesystem.f_bavail) *
        filesystem.f_frsize;

    const unsigned long long usedBytes =
        totalBytes - freeBytes;

    constexpr double bytesPerGB =
    1024.0 * 1024.0 * 1024.0;

snapshot.totalSpaceGB =
    totalBytes / bytesPerGB;

snapshot.usedSpaceGB =
    usedBytes / bytesPerGB;

snapshot.freeSpaceGB =
    freeBytes / bytesPerGB;
    if (snapshot.totalSpaceGB > 0)
    {
        snapshot.usagePercent =
            (static_cast<double>(usedBytes) /
             static_cast<double>(totalBytes)) * 100.0;
    }

    return snapshot;
}

} // namespace pulse