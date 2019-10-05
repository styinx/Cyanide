#ifndef CYANIDE_RGBACOLOR_HPP
#define CYANIDE_RGBACOLOR_HPP

#include "cystd/stdPrototypes.hpp"
#include "cyutil/color/IColor.hpp"

namespace cyanide::cyutil
{

    enum class RGBA : Uint32
    {
        TRANSPARENT = 0x00000000,
        BLACK       = 0x000000FF,
        BLUE        = 0x0000FFFF,
        SKY         = 0x0080FFFF,
        GREEN       = 0x00FF00FF,
        MINT        = 0x00FF80FF,
        CYAN        = 0x00FFFFFF,
        GREY1       = 0x111111FF,
        GREY2       = 0x222222FF,
        GREY3       = 0x333333FF,
        GREY4       = 0x444444FF,
        GREY5       = 0x555555FF,
        GREY6       = 0x666666FF,
        GREY7       = 0x777777FF,
        PURPLE      = 0x8000FFFF,
        LIME        = 0x80FF00FF,
        GREY8       = 0x888888FF,
        GREY9       = 0x999999FF,
        GREYA       = 0xAAAAAAFF,
        GREYB       = 0xBBBBBBFF,
        GREYC       = 0xCCCCCCFF,
        GREYD       = 0xDDDDDDFF,
        GREYE       = 0xEEEEEEFF,
        RED         = 0xFF0000FF,
        MAGENTA     = 0xFF00FFFF,
        ORANGE      = 0xFF8000FF,
        YELLOW      = 0xFFFF00FF,
        WHITE       = 0xFFFFFFFF
    };

    class RGBAColor : public IColor<Byte>
    {
    public:
        Byte r;
        Byte g;
        Byte b;
        Byte a;

        explicit RGBAColor(Uint32 color);
        explicit RGBAColor(Byte r, Byte g, Byte b, Byte a = 0);
        RGBAColor(const RGBAColor& color)     = default;
        RGBAColor(RGBAColor&& color) noexcept = default;
        RGBAColor& operator=(const RGBAColor& color) = default;
        RGBAColor& operator=(RGBAColor&& color) noexcept = default;
        virtual ~RGBAColor()                             = default;
        explicit    operator Uint32();
        RGBAColor&  add(const RGBAColor& color);
        RGBAColor&  add(const Uint32 color);
        RGBAColor&  sub(const RGBAColor& color);
        RGBAColor&  sub(const Uint32 color);
        RGBAColor&  operator+=(const RGBAColor& color);
        RGBAColor&  operator+=(const Uint32 color);
        RGBAColor   operator+(const RGBAColor& color);
        RGBAColor   operator+(const Uint32 color);
        RGBAColor&  operator-=(const RGBAColor& color);
        RGBAColor&  operator-=(const Uint32 color);
        RGBAColor   operator-(const RGBAColor& color);
        RGBAColor   operator-(const Uint32 color);
        friend bool operator==(const RGBAColor& left, const RGBAColor& right);
        friend bool operator!=(const RGBAColor& left, const RGBAColor& right);
        friend bool operator<(const RGBAColor& left, const RGBAColor& right);
        friend bool operator<=(const RGBAColor& left, const RGBAColor& right);
        friend bool operator>(const RGBAColor& left, const RGBAColor& right);
        friend bool operator>=(const RGBAColor& left, const RGBAColor& right);
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_RGBACOLOR_HPP
