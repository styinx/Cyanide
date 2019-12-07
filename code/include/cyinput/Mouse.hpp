#ifndef CYANIDE_MOUSE_HPP
#define CYANIDE_MOUSE_HPP

#include "cymath/Point.hpp"

namespace cyanide::cyinput
{

    class Mouse final
    {
    private:
    public:
        Mouse()                       = default;
        ~Mouse()                      = default;
        Mouse(const Mouse& mouse)     = default;
        Mouse(Mouse&& mouse) noexcept = default;
        Mouse&      operator=(const Mouse& mouse) = default;
        Mouse&      operator=(Mouse&& mouse) noexcept = default;
        static bool setMousePosition(Sint32 x, Sint32 y);
        static bool setMousePosition(const cymath::Point p);
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_MOUSE_HPP
