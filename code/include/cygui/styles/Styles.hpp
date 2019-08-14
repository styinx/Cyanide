#ifndef CYANIDE_STYLES_HPP
#define CYANIDE_STYLES_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cygui
{

    enum class SCALE : Byte
    {
        ORIGINAL = 0x01,
        DOUBLE   = 0x02
    };

    enum class ORIENT : Byte
    {
        HORIZONTAL = 0x01,
        VERTICAL   = 0x02
    };

    enum class ALIGN : Byte
    {
        LEFT          = 0x01,
        CENTER        = 0x02,
        RIGHT         = 0x04,
        TOP           = 0x10,
        MIDDLE        = 0x20,
        BOTTOM        = 0x40,
        TOP_LEFT      = 0x11,
        TOP_CENTER    = 0x12,
        TOP_RIGHT     = 0x14,
        MIDDLE_LEFT   = 0x21,
        MIDDLE_CENTER = 0x22,
        MIDDLE_RIGHT  = 0x24,
        BOTTOM_LEFT   = 0x41,
        BOTTOM_CENTER = 0x42,
        BOTTOM_RIGHT  = 0x44
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_STYLES_HPP
