#include "cyinput/SDLEventLoop.hpp"
#include "cymath/Rectangle.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyutil/color/animation/ColorAnimation.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <SDL2/SDL.h>
#include <iostream>

int main()
{
    using namespace cyanide;
    using namespace cyutil;
    using namespace cymath;
    using namespace cyvideo;

    cysystem::SDL sdl{};
    sdl.initSDL(SDL_INIT_EVERYTHING);

    auto win =
        std::make_shared<cyvideo::SDLWindow>("asd", cymath::Point{50, 50}, cymath::Size{250, 250});
    auto ren = std::make_shared<cyvideo::SDLRenderer>(win);

    auto color_animation = std::make_shared<cyutil::ColorAnimation>(
        RGBAColor(0x00000000),
        RGBAColor(0xFFFFFFFF),
        cyvideo::AnimationType::LINEAR,
        cyvideo::AnimationDirection::BACKWARD,
        255);

    cyinput::SDLEventLoop eventLoop{};

    eventLoop.keyboard()->onKeyDown(SDLK_PLUS, [color_animation](const cyinput::KeyboardInput::KeyCode) {
        color_animation->next();
        auto col = color_animation->current();
        std::cout << "next " << col.r << " " << col.g << " " << col.b << " " << col.a << "\n";
    });

    eventLoop.keyboard()->onKeyDown(SDLK_MINUS, [color_animation](const cyinput::KeyboardInput::KeyCode) {
        color_animation->previous();
        auto col = color_animation->current();
        std::cout << "prev " << col.r << " " << col.g << " " << col.b << " " << col.a << "\n";
    });

    eventLoop.onLoopBegin([ren, color_animation]() {
        ren->clear();
        color_animation->next();
        ren->setDrawColor(color_animation->current());
        ren->drawFilledRectangle(Rectangle{0, 0, 50, 50});
    });

    eventLoop.onLoopEnd([ren]() { ren->show(); });

    eventLoop.run();

    return 0;
}
