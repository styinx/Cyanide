#include "cyinput/SDLEventLoop.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyutil/io/Print.hpp"
#include "cyutil/logging/Logging.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <SDL2/SDL.h>

int main()
{
    using namespace cyanide;
    using namespace cyanide::cyinput;
    using namespace cyanide::cyutil;

    cysystem::SDL sdl{};
    sdl.initSDL(SDL_INIT_EVERYTHING);

    for(Uint8 controller = 0; controller < SDL_NumJoysticks(); ++controller)
    {
        SDL_JoystickOpen(controller);
        print("Joystick {}", controller);
    }

    std::make_shared<cyvideo::SDLWindow>("asd", cymath::Point{50, 50}, cymath::Size{250, 250});

    if(SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE) == 1)
    {
        print("Can hook");
    }

    if(SDL_CaptureMouse(SDL_TRUE) == 0)
    {
        print("Can capture");
    }

    cyinput::SDLEventLoop eventLoop{};

    eventLoop.controller(-1)->onStickMotion(CONTROLLER_STICK::LS, [](const Sint16 x, const Sint16 y) {
        print("Stick {4:d} {4:d}", x, y);
    });

    eventLoop.joystick(-1)->onAxisMotion(1, [](const Sint16 x) { print("Axis {4:d}", x); });

    eventLoop.keyboard()->onKeyPressed(
        SDLK_a, [](const KeyboardInput::KeyCode) { print("'a' pressed"); });

    eventLoop.keyboard()->onKeyDown(SDLK_a, [](const KeyboardInput::KeyCode) { print("'a' down"); });

    eventLoop.mouse()->onMotion(
        [](const Sint16 x, const Sint16 y) { print("Mouse {4:d} {4:d}", x, y); });

    eventLoop.run();

    return 0;
}
