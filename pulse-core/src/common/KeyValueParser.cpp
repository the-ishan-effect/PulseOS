#include "pulse/common/KeyValueParser.hpp"

#include "pulse/common/StringUtils.hpp"

#include <sstream>
#include <stdexcept>

namespace pulse
{

bool KeyValueDocument::contains(
    const std::string& key) const
{
    return data_.contains(key);
}

std::string KeyValueDocument::get(
    const std::string& key) const
{
    auto it = data_.find(key);

    if (it == data_.end())
    {
        throw std::runtime_error(
            "Key not found: " + key);
    }

    return it->second;
}

KeyValueDocument KeyValueParser::parse(
    const std::string& text,
    char separator)
{
    KeyValueDocument document;

    std::istringstream stream(text);

    std::string line;

    while (std::getline(stream, line))
    {
        const auto position = line.find(separator);

        if (position == std::string::npos)
        {
            continue;
        }

        const auto key =
            StringUtils::trim(
                line.substr(0, position));

        const auto value =
            StringUtils::trim(
                line.substr(position + 1));

        document.data_[key] = value;
    }

    return document;
}

}