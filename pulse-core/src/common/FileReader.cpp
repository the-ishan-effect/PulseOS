#include "pulse/common/FileReader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace pulse
{

std::string FileReader::read(const std::string& path)
{
    std::ifstream file(path);

    if (!file)
    {
        throw std::runtime_error("Failed to open file: " + path);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

}