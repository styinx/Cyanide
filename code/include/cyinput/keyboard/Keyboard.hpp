#ifndef CYANIDE_KEYBOARD_HPP
#define CYANIDE_KEYBOARD_HPP

#include "cyinput/keyboard/IKeyboard.hpp"

namespace cyanide::cyinput
{

    class Keyboard final : public IKeyboard
    {
    private:
    public:
        Keyboard() = default;
        ~Keyboard() = default;
        Keyboard(const Keyboard& keyboard) = default;
        Keyboard(Keyboard&& keyboard) noexcept = default;
        Keyboard& operator=(const Keyboard& keyboard) = default;
        Keyboard& operator=(Keyboard&& keyboard) noexcept = default;
    };

}  // namespace cyanide

#endif  // CYANIDE_KEYBOARD_HPP
