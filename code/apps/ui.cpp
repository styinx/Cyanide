#include "cygui/GUIRenderManager.hpp"
#include "cygui/widgets/Button.hpp"
#include "cyinput/SDLEventLoop.hpp"
#include "cymath/Rectangle.hpp"
#include "cystd/Enum.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyvideo/SDLSurface.hpp"
#include "cyvideo/SDLTexture.hpp"
#include "cyvideo/font/SDLFont.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>

int main()
{
    using namespace cyanide;
    using namespace cygui;
    using namespace cymath;
    using namespace cyutil;
    using namespace cyvideo;

    const String FILENAME = __FILE__;
    const String BASE_DIR = FILENAME.substr(0, FILENAME.find_last_of('/')) + "/../../";

    cysystem::SDL sdl{};
    sdl.initSDL(SDL_INIT_EVERYTHING);
    sdl.initTTF();

    const auto win = std::make_shared<SDLWindow>("asd", Point{50, 50}, Size{250, 250});
    const auto ren = std::make_shared<SDLRenderer>(win);

    const auto surf = std::make_shared<SDLSurface>(String(BASE_DIR + "resources/cyanide.png"));
    const auto tex  = std::make_shared<SDLTexture>(ren, surf);
    tex->rotate(180);

    const auto   gui_ren  = std::make_shared<GUIRenderManager>(ren);
    const String font_dir = BASE_DIR + "resources/fonts/Roboto/Roboto-Regular.ttf";
    auto         font     = std::make_shared<SDLFont>(font_dir, 20);
    const auto   button   = std::make_shared<Button>("Hello");
    button->setTextAlignment(ALIGN::RIGHT);
    button->setContentSize({100, 50});
    button->setFGColor(RGBAColor{255, 255, 0, 255});

    ren->clear();
    ren->drawSDLTexture(tex, {0, 0}, {150, 150});
    button->draw();
    ren->show();

    cyinput::SDLEventLoop eventLoop{};
    eventLoop.run();

    return 0;
}
