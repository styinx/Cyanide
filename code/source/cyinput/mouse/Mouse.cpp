#include "cyinput/mouse/Mouse.hpp"

#include <SDL2/SDL_mouse.h>

namespace cyanide::cyinput
{

    bool Mouse::setMousePosition(Sint32 x, Sint32 y)
    {
        return SDL_WarpMouseGlobal(x, y) == 0;
    }

    bool Mouse::setMousePosition(const cymath::Point p)
    {
        return Mouse::setMousePosition(p.x, p.y);
    }

}  // namespace cyanide
