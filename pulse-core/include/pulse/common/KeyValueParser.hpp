#pragma once

#include <string>

#include "pulse/common/KeyValueDocument.hpp"

namespace pulse
{

class KeyValueParser
{
public:
    [[nodiscard]]
    static KeyValueDocument parse(
        const std::string& text,
        char separator = '=');
};

}