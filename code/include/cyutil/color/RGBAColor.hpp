#ifndef CYANIDE_RGBACOLOR_HPP
#define CYANIDE_RGBACOLOR_HPP

#include "cystd/Types.hpp"
#include "cyutil/color/IColor.hpp"

namespace cyanide::cyutil
{
    namespace Default
    {
        static const Byte RGBA_MIN = 0;
        static const Byte RGBA_MAX = 255;
        static const Byte MASK     = 0xFFU;
    }  // namespace Default

    enum class RGBA : Uint32
    {
        TRANSPARENT = 0x00000000,
        BLACK       = 0x000000FF,
        BLUE1       = 0x000011FF,
        BLUE2       = 0x000022FF,
        BLUE3       = 0x000033FF,
        BLUE4       = 0x000044FF,
        BLUE5       = 0x000055FF,
        BLUE6       = 0x000066FF,
        BLUE7       = 0x000077FF,
        BLUE8       = 0x000088FF,
        BLUE9       = 0x000099FF,
        BLUEA       = 0x0000AAFF,
        BLUEB       = 0x0000BBFF,
        BLUEC       = 0x0000CCFF,
        BLUED       = 0x0000DDFF,
        BLUEE       = 0x0000EEFF,
        BLUE        = 0x0000FFFF,
        GREEN1      = 0x001100FF,
        GREEN2      = 0x002200FF,
        GREEN3      = 0x003300FF,
        GREEN4      = 0x004400FF,
        GREEN5      = 0x005500FF,
        GREEN6      = 0x006600FF,
        GREEN7      = 0x007700FF,
        SKY         = 0x0080FFFF,
        GREEN8      = 0x008800FF,
        GREEN9      = 0x009900FF,
        GREENA      = 0x00AA00FF,
        GREENB      = 0x00BB00FF,
        GREENC      = 0x00CC00FF,
        GREEND      = 0x00DD00FF,
        GREENE      = 0x00EE00FF,
        GREEN       = 0x00FF00FF,
        MINT        = 0x00FF80FF,
        CYAN        = 0x00FFFFFF,
        RED1        = 0x110000FF,
        GREY1       = 0x111111FF,
        RED2        = 0x220000FF,
        GREY2       = 0x222222FF,
        RED3        = 0x330000FF,
        GREY3       = 0x333333FF,
        RED4        = 0x440000FF,
        GREY4       = 0x444444FF,
        RED5        = 0x550000FF,
        GREY5       = 0x555555FF,
        RED6        = 0x660000FF,
        GREY6       = 0x666666FF,
        RED7        = 0x770000FF,
        GREY7       = 0x777777FF,
        PURPLE      = 0x8000FFFF,
        LIME        = 0x80FF00FF,
        RED8        = 0x880000FF,
        GREY8       = 0x888888FF,
        RED9        = 0x990000FF,
        GREY9       = 0x999999FF,
        REDA        = 0xAA0000FF,
        GREYA       = 0xAAAAAAFF,
        REDB        = 0xBB0000FF,
        GREYB       = 0xBBBBBBFF,
        REDC        = 0xCC0000FF,
        GREYC       = 0xCCCCCCFF,
        REDD        = 0xDD0000FF,
        GREYD       = 0xDDDDDDFF,
        REDE        = 0xEE0000FF,
        GREYE       = 0xEEEEEEFF,
        RED         = 0xFF0000FF,
        MAGENTA     = 0xFF00FFFF,
        ORANGE      = 0xFF8000FF,
        YELLOW      = 0xFFFF00FF,
        WHITE       = 0xFFFFFFFF
    };

    class RGBAColor : public IColor<Byte>
    {
    private:
        static RGBAColor toRGBA(const Uint32 value);

    public:
        Byte r;
        Byte g;
        Byte b;
        Byte a;

        RGBAColor();
        explicit RGBAColor(const Uint32 color);
        explicit RGBAColor(const String& color);
        explicit RGBAColor(const RGBA color);
        explicit RGBAColor(const Byte r, const Byte g, const Byte b, const Byte a = 0);
        RGBAColor(const RGBAColor& color)     = default;
        RGBAColor(RGBAColor&& color) noexcept = default;
        RGBAColor& operator=(const RGBAColor& color) = default;
        RGBAColor& operator=(RGBAColor&& color) noexcept = default;
        virtual ~RGBAColor()                             = default;
        explicit    operator Uint32();
        RGBAColor&  set(const Byte r, const Byte g, const Byte b, const Byte a);
        RGBAColor&  add(const Byte r, const Byte g, const Byte b, const Byte a);
        RGBAColor&  sub(const Byte r, const Byte g, const Byte b, const Byte a);
        RGBAColor&  mul(const float r, const float g, const float b, const float a);
        RGBAColor&  div(const float r, const float g, const float b, const float a);
        RGBAColor   operator+(const RGBAColor& color);
        RGBAColor&  operator+=(const RGBAColor& color);
        RGBAColor   operator-(const RGBAColor& color);
        RGBAColor&  operator-=(const RGBAColor& color);
        RGBAColor   operator+(const Uint32 color);
        RGBAColor&  operator+=(const Uint32 color);
        RGBAColor   operator-(const Uint32 color);
        RGBAColor&  operator-=(const Uint32 color);
        RGBAColor   operator*(const float scalar);
        RGBAColor&  operator*=(const float scalar);
        RGBAColor   operator/(const float scalar);
        RGBAColor&  operator/=(const float scalar);
        friend bool operator==(const RGBAColor& left, const RGBAColor& right);
        friend bool operator!=(const RGBAColor& left, const RGBAColor& right);
        friend bool operator<(const RGBAColor& left, const RGBAColor& right);
        friend bool operator<=(const RGBAColor& left, const RGBAColor& right);
        friend bool operator>(const RGBAColor& left, const RGBAColor& right);
        friend bool operator>=(const RGBAColor& left, const RGBAColor& right);
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_RGBACOLOR_HPP
