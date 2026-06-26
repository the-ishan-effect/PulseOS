#pragma once

#include "pulse/system/SystemSnapshot.hpp"

namespace pulse
{

class ConsoleRenderer
{
public:

    void render(
        const SystemSnapshot& snapshot) const;

};

}