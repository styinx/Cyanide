#ifndef CYANIDE_MOUSE_HPP
#define CYANIDE_MOUSE_HPP

#include "MouseInput.hpp"
#include "cymath/Point.hpp"

namespace cyanide::cyinput
{

    class Mouse
        : public MouseInput
    {
    private:
    public:
        Mouse()                       = default;
        virtual ~Mouse()                      = default;
        static bool setMousePosition(Sint32 x, Sint32 y);
        static bool setMousePosition(const cymath::Point p);
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_MOUSE_HPP
