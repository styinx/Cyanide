#include "cyinput/SDLEventLoop.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyutil/io/Print.hpp"
#include "cyvideo/SDLSurface.hpp"
#include "cyvideo/font/SDLFont.hpp"
#include "cyvideo/window/SDLWindow.hpp"

int main()
{
    using namespace cyanide;
    using namespace cyanide::cyinput;

    cysystem::SDL sdl{};
    sdl.initSDL(SDL_INIT_EVERYTHING);

    for(Uint8 controller = 0; controller < SDL_NumJoysticks(); ++controller)
    {
        SDL_JoystickOpen(controller);
        std::cout << "Joystick " << (int)controller << " " << std::endl;
    }

    std::make_shared<cyvideo::SDLWindow>("asd", cymath::Point{50, 50}, cymath::Size{250, 250});

    if(SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE) == 1)
    {
        std::cout << "can hook\n";
    }

    if(SDL_CaptureMouse(SDL_TRUE) == 0)
    {
        std::cout << "can capture\n";
    }

    cyinput::SDLEventLoop eventLoop{};

    eventLoop.controller(-1)->onStickMotion(CONTROLLER_STICK::LS, [](const Sint16 x, const Sint16 y) {
        std::cout << "stick " << x << " " << y << "\n";
    });

    eventLoop.joystick(-1)->onAxisMotion(1, [](const Sint16 x) { std::cout << "axis " << x << "\n"; });

    eventLoop.keyboard()->onKeyPressed(
        SDLK_a, [](const KeyboardInput::KeyCode) { std::cout << "a pressed\n"; });

    eventLoop.keyboard()->onKeyDown(
        SDLK_a, [](const KeyboardInput::KeyCode) { std::cout << "a down\n"; });

    eventLoop.mouse()->onMotion(
        [](const Sint16 x, const Sint16 y) { std::cout << x << " " << y << "\n"; });

    eventLoop.run();

    return 0;
}
