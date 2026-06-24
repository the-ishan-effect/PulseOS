#pragma once

#include "pulse/system/UptimeSnapshot.hpp"

namespace pulse
{

class UptimeInfo
{
public:

    [[nodiscard]]
    UptimeSnapshot collect() const;

};

}