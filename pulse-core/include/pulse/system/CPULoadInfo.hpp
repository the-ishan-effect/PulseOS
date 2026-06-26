#pragma once

#include "pulse/system/CPULoadSnapshot.hpp"

namespace pulse
{

class CPULoadInfo
{
public:

    [[nodiscard]]
    CPULoadSnapshot collect() const;

};

}