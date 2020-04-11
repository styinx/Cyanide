#include "cygui/widgets/Button.hpp"
#include "cyinput/SDLEventLoop.hpp"
#include "cymath/Rectangle.hpp"
#include "cysystem/Cyanide.hpp"
#include "cyvideo/SDLSurface.hpp"
#include "cyvideo/SDLTexture.hpp"
#include "cyvideo/font/SDLFont.hpp"
#include "cyvideo/renderer/GUIRenderManager.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <memory>

int main()
{
    using namespace cyanide;
    using namespace cygui;
    using namespace cymath;
    using namespace cysystem;
    using namespace cyutil;
    using namespace cyvideo;

    const String FILENAME = __FILE__;
    const String BASE_DIR = FILENAME.substr(0, FILENAME.find_last_of('/')) + "/../../";

    Cyanide cyanide{};
    cyanide.initVideo();
    cyanide.initGUI();

    const auto win = std::make_shared<SDLWindow>("asd", Point{50, 50}, Size{250, 250});
    const auto ren = std::make_shared<SDLRenderer>(win);

    const auto surf = std::make_shared<SDLSurface>(String(BASE_DIR + "resources/cyanide.png"));
    const auto tex  = std::make_shared<SDLTexture>(ren, surf);
    tex->rotate(180);

    GUIRenderManager::createInstance(ren);
    const String font_dir = BASE_DIR + "resources/fonts/Roboto/Roboto-Regular.ttf";
    auto         font     = std::make_shared<SDLFont>(font_dir, 40);
    const auto   button   = std::make_shared<Button>("Hello");
    button->setTextAlignment(ALIGN::MIDDLE_CENTER);
    button->setSize({200, 100});
    button->setTextFGColor(RGBAColor{0, 0, 255, 255});
    button->setTextBGColor(RGBAColor{255, 255, 255, 255});
    button->setBorderColor(RGBAColor{255, 0, 0, 255});
    button->setBackgroundColor(RGBAColor{100, 100, 100, 255});

    ren->clear();
    ren->drawSDLTexture(tex, {0, 0}, {150, 150});
    button->draw();
    ren->show();

    cyinput::SDLEventLoop eventLoop{};
    eventLoop.run();

    return 0;
}
