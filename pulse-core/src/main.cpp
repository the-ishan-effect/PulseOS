#include <iostream>

#include "pulse/system/SystemInfo.hpp"

int main()
{
    pulse::SystemInfo system;

    std::cout << "=============================\n";
    std::cout << " PulseOS v0.1.0\n";
    std::cout << "=============================\n\n";

    std::cout << "Hostname : "
              << system.getHostname()
              << '\n';

    return 0;
}