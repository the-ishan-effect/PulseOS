#include "pulse/system/CPUInfo.hpp"

#include "pulse/common/FileReader.hpp"
#include "pulse/common/StringUtils.hpp"

#include <sstream>
#include <string>

namespace
{

struct ParsedField
{
    std::string name;
    std::string value;
};

ParsedField splitLine(const std::string& line)
{
    const auto separator = line.find(':');

    if (separator == std::string::npos)
    {
        return {};
    }

    ParsedField field;

    field.name = pulse::StringUtils::trim(
        line.substr(0, separator));

    field.value = pulse::StringUtils::trim(
        line.substr(separator + 1));

    return field;
}

} // unnamed namespace

namespace pulse
{

CPUSnapshot CPUInfo::collect() const
{
    CPUSnapshot snapshot;

    const std::string cpuInfo =
        FileReader::read("/proc/cpuinfo");

    std::istringstream stream(cpuInfo);

    std::string line;

    while (std::getline(stream, line))
    {
        ParsedField field = splitLine(line);

        if (field.name.empty())
        {
            continue;
        }

        if (field.name == "vendor_id")
        {
            snapshot.vendor = field.value;
        }
        else if (field.name == "model name")
        {
            snapshot.model = field.value;
        }
        else if (field.name == "cpu cores")
        {
            snapshot.physicalCores =
                std::stoi(field.value);
        }
        else if (field.name == "siblings")
        {
            snapshot.logicalThreads =
                std::stoi(field.value);
        }

        if (!snapshot.vendor.empty() &&
            !snapshot.model.empty() &&
            snapshot.physicalCores > 0 &&
            snapshot.logicalThreads > 0)
        {
            break;
        }
    }

    return snapshot;
}

} // namespace pulse