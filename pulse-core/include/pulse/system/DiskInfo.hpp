#pragma once

#include "pulse/system/DiskSnapshot.hpp"

namespace pulse
{

class DiskInfo
{
public:

    [[nodiscard]]
    DiskSnapshot collect() const;

};

}