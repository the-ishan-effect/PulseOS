#pragma once

#include "pulse/system/SystemSnapshot.hpp"

namespace pulse
{

/**
 * @brief Collects information about the current system.
 *
 * Aggregates hostname, operating system, kernel,
 * CPU, memory and uptime into a single snapshot.
 */
class SystemInfo
{
public:
    [[nodiscard]]
    SystemSnapshot collect() const;
};
}