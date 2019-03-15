#ifndef CYANIDE_KEYS_HPP
#define CYANIDE_KEYS_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide
{
namespace cyinput
{

    enum class KEY_STATE : Byte
    {
        RELEASED = 0x01,
        DOWN     = 0x02,
        PRESSED  = 0x04

    };

    enum class KEYMOD : Uint16
    {
        KMOD_NONE     = 0x0000,
        KMOD_LSHIFT   = 0x0001,
        KMOD_RSHIFT   = 0x0002,
        KMOD_LCTRL    = 0x0040,
        KMOD_RCTRL    = 0x0080,
        KMOD_LALT     = 0x0100,
        KMOD_RALT     = 0x0200,
        KMOD_LGUI     = 0x0400,
        KMOD_RGUI     = 0x0800,
        KMOD_NUM      = 0x1000,
        KMOD_CAPS     = 0x2000,
        KMOD_MODE     = 0x4000,
        KMOD_RESERVED = 0x8000
    };

    enum class KEY : Byte
    {
        ESCAPE = 0x1
    };

}  // namespace cyinput
}  // namespace cyanide

#endif  // CYANIDE_KEYS_HPP
