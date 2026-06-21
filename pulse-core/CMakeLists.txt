add_executable(pulseos
    src/main.cpp
    src/system/SystemInfo.cpp
    src/common/FileReader.cpp
)

target_include_directories(pulseos PRIVATE include)