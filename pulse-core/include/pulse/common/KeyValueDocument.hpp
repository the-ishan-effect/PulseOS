#pragma once

#include <string>
#include <unordered_map>

namespace pulse
{

class KeyValueDocument
{
public:
    [[nodiscard]]
    bool contains(const std::string& key) const;

    [[nodiscard]]
    std::string get(const std::string& key) const;

private:
    std::unordered_map<std::string, std::string> data_;

    friend class KeyValueParser;
};

}