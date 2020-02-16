#ifndef CYANIDE_JOYSTICK_HPP
#define CYANIDE_JOYSTICK_HPP

#include "cyinput/joystick/IJoystick.hpp"
#include "cyinput/joystick/JoystickInput.hpp"

namespace cyanide::cyinput
{

    class Joystick
        : public IJoystick
        , public JoystickInput
    {
    public:
        explicit Joystick(const Uint8 id);
        virtual ~Joystick() = default;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_JOYSTICK_HPP
