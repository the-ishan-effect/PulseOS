#include "pulse/system/SystemInfo.hpp"
#include "pulse/ui/ConsoleRenderer.hpp"

int main()
{
    pulse::SystemInfo system;

    const auto snapshot =
        system.collect();

    pulse::ConsoleRenderer renderer;

    renderer.render(snapshot);

    return 0;
}