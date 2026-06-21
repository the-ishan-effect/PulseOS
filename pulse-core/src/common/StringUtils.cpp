#include "pulse/common/StringUtils.hpp"

#include <algorithm>
#include <cctype>

namespace pulse
{

std::string StringUtils::ltrim(std::string text)
{
    text.erase(
        text.begin(),
        std::find_if(
            text.begin(),
            text.end(),
            [](unsigned char ch)
            {
                return !std::isspace(ch);
            }));

    return text;
}

std::string StringUtils::rtrim(std::string text)
{
    text.erase(
        std::find_if(
            text.rbegin(),
            text.rend(),
            [](unsigned char ch)
            {
                return !std::isspace(ch);
            }).base(),
        text.end());

    return text;
}

std::string StringUtils::trim(std::string text)
{
    return ltrim(rtrim(text));
}

} // namespace pulse