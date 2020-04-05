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

    const auto update = [ren, color_animation](const SDL_Event& event) {
        ren->clear();
        color_animation->update();
        ren->setDrawColor(color_animation->current());
        ren->drawFilledRectangle(Rectangle{0, 0, 50, 50});
    };

    const auto draw = [ren](const SDL_Event& event) { ren->show(); };

    cyinput::SDLEventLoop eventLoop{};
    eventLoop.onLoopBegin(update);
    eventLoop.onLoopEnd(draw);
    eventLoop.run();

    return 0;
}
