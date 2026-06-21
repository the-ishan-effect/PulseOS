#include <iostream>

#include "pulse/system/SystemInfo.hpp"

int main()
{
    pulse::SystemInfo system;

    const auto snapshot = system.collect();

    std::cout << "=============================\n";
    std::cout << " PulseOS v0.2.0\n";
    std::cout << "=============================\n\n";

    std::cout << "Hostname : "
              << snapshot.hostname
              << '\n';
    std::cout << "OS        : "
              << snapshot.osName
              << '\n';
    return 0;
}