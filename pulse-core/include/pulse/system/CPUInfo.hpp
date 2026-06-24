#pragma once

#include "pulse/system/CPUSnapshot.hpp"

namespace pulse
{

class CPUInfo
{
public:

    [[nodiscard]]
    CPUSnapshot collect() const;

};

}