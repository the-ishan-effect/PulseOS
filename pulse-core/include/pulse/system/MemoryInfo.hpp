#pragma once

#include "pulse/system/MemorySnapshot.hpp"

namespace pulse
{

class MemoryInfo
{
public:

    [[nodiscard]]
    MemorySnapshot collect() const;

};

}