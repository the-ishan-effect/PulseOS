add_executable(pulseos
    src/main.cpp
    src/system/SystemInfo.cpp
    src/system/CPUInfo.cpp
    src/system/MemoryInfo.cpp
    src/system/UptimeInfo.cpp
    src/system/CPULoadInfo.cpp
    src/common/FileReader.cpp
    src/common/StringUtils.cpp
    src/common/KeyValueParser.cpp
)
target_include_directories(pulseos PRIVATE include)