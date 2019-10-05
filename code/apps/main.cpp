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

    auto win = std::make_shared<cyvideo::SDLWindow>("asd", cymath::Point{50, 50}, cymath::Size{250, 250});
    auto ren = std::make_shared<cyvideo::SDLRenderer>(win);
    auto gui_manager = std::make_shared<cygui::GUIRenderManager>(ren);

    const String font_dir = "/home/chris/Projekte/Cyanide/resources/fonts/Roboto/Roboto-Regular.ttf";
    auto         font     = std::make_shared<cyvideo::SDLFont>(font_dir, 20);

    cyinput::SDLEventLoop eventLoop{};

    eventLoop.run();

    return 0;
}
