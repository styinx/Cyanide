
#include "cygui/widgets/Widget.hpp"
#include "cyinput/SDLEventLoop.hpp"
#include "cyutil/io/Print.hpp"
#include "cyvideo/font/SDLFont.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <SDL2/SDL.h>
#include <cygui/GUIRenderManager.hpp>
#include <cygui/layout/HBox.hpp>
#include <cygui/widgets/Button.hpp>
#include <cysystem/sdl/SDL.hpp>
#include <cyvideo/SDLSurface.hpp>
#include <cyvideo/SDLTexture.hpp>
#include <cyvideo/renderer/SDLRenderer.hpp>

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

    eventLoop.onMouseMotion([](const Uint32 x, const Uint32 y) {
        int gx, gy;
        SDL_GetGlobalMouseState(&gx, &gy);
        std::cout << x << " " << y << "\n";
        std::cout << gx << " " << gy << "\n";
    });

    eventLoop.run();

    return 0;
}
