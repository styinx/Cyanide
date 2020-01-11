#ifndef CYANIDE_KEYBOARD_HPP
#define CYANIDE_KEYBOARD_HPP

#include "cyinput/keyboard/IKeyboard.hpp"
#include "cyinput/keyboard/KeyboardInput.hpp"

namespace cyanide::cyinput
{

    class Keyboard final
        : public IKeyboard
        , public KeyboardInput
    {
    private:

    public:
        Keyboard() = default;
        virtual ~Keyboard() = default;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_KEYBOARD_HPP
