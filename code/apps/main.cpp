#include "cygui/widgets/Widget.hpp"
#include "cysystem/sdl/SDLEventLoop.hpp"
#include "cyutil/io/Print.hpp"
#include "cyvideo/font/SDLFont.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <SDL2/SDL.h>
#include <cygui/GUIObjectManager.hpp>
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

    const String base_dir = "../../";
    auto         font     = cyvideo::SDLFontSPtr(new cyvideo::SDLFont(
        "/home/chris/Projekte/Cyanide/resources/fonts/Roboto/Roboto-Thin.ttf", 16));

    auto win_rect = cymath::Rectangle{50, 50, 200, 200};

    auto win = cyvideo::SDLWindowSPtr(new cyvideo::SDLWindow{"asd", win_rect});
    auto ren = cyvideo::SDLRendererSPtr(new cyvideo::SDLRenderer{win});
    auto gui_manager = cygui::GUIObjectManager(ren);

    auto button_widget = cygui::Button{"Hello"};

    ren->clear();
    button_widget.draw();
    ren->show();

    cysystem::SDLEventLoop eventLoop{};

    eventLoop.run();

    return 0;
}
