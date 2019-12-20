#ifndef CYANIDE_KEYS_HPP
#define CYANIDE_KEYS_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cyinput
{

    using KeyCode = Uint16;
    using KeyMod  = Uint16;

    using MouseButtonCode = Uint8;

    enum class KEY_STATE : Byte
    {
        NONE     = 0x00,
        RELEASED = 0x01,
        DOWN     = 0x02,
        PRESSED  = 0x04
    };

    enum class MOUSE_BUTTON_STATE : Byte
    {
        NONE     = 0x00,
        RELEASED = 0x01,
        DOWN     = 0x02,
        PRESSED  = 0x04
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_KEYS_HPP
