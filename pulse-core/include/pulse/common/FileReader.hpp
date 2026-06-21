#pragma once

#include <string>

namespace pulse
{

class FileReader
{
public:
    [[nodiscard]]
    static std::string read(const std::string& path);
};

}