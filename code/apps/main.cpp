#include "cygui/GUIRenderManager.hpp"
#include "cyinput/SDLEventLoop.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyutil/io/Print.hpp"
#include "cyvideo/SDLSurface.hpp"
#include "cyvideo/SDLTexture.hpp"
#include "cyvideo/font/SDLFont.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <SDL2/SDL.h>

int main()
{
    using namespace cyanide;

    cysystem::SDL sdl{};
    sdl.initSDL(SDL_INIT_EVERYTHING);
    sdl.initTTF();

    auto win =
        std::make_shared<cyvideo::SDLWindow>("asd", cymath::Point{50, 50}, cymath::Size{250, 250});
    auto ren         = std::make_shared<cyvideo::SDLRenderer>(win);
    auto gui_manager = std::make_shared<cygui::GUIRenderManager>(ren);

    const String font_dir = "/home/chris/Projekte/Cyanide/resources/fonts/Roboto/"
                            "Roboto-Regular.ttf";
    auto font = std::make_shared<cyvideo::SDLFont>(font_dir, 20);

    cyinput::SDLEventLoop eventLoop{};

    if(SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE) == 1)
    {
        std::cout << "can hook\n";
    }

    if(SDL_CaptureMouse(SDL_TRUE) == 0)
    {
        std::cout << "can capture\n";
    }

    eventLoop.keyboard()->onKeyDown(
        SDLK_a, [](const cyinput::KeyboardInput::KeyCode) { std::cout << "a down\n"; });
    eventLoop.mouse()->on(cyinput::MouseInput::MOUSE_EVENT::ANY, [](const SDL_Event& event) {
        std::cout << event.button.button << "\n";
    });

    eventLoop.run();

    return 0;
}
