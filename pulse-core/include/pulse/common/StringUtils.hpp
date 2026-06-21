#pragma once

#include <string>

namespace pulse
{

class StringUtils
{
public:

    [[nodiscard]]
    static std::string ltrim(std::string text);

    [[nodiscard]]
    static std::string rtrim(std::string text);

    [[nodiscard]]
    static std::string trim(std::string text);

};

}