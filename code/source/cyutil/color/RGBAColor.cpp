#include "cyutil/color/RGBAColor.hpp"

namespace cyanide::cyutil
{

    RGBAColor::RGBAColor(Uint32 color)
    {
        r = static_cast<Byte>((color >> 24u) & 0xFF);
        g = static_cast<Byte>((color >> 16u) & 0xFF);
        b = static_cast<Byte>((color >> 8u) & 0xFF);
        a = static_cast<Byte>(color & 0xFFu);
    }

    RGBAColor::RGBAColor(Byte r, Byte g, Byte b, Byte a)
        : r(r)
        , g(g)
        , b(b)
        , a(a)
    {
    }

    RGBAColor::operator Uint32()
    {
        Uint32 color = 0x00000000;
        color        = (color + r) << 8u;
        color        = (color + g) << 8u;
        color        = (color + b) << 8u;
        color += a;

        return color;
    }

    RGBAColor& RGBAColor::add(const RGBAColor& color)
    {
        r += color.r;
        g += color.g;
        b += color.b;
        a += color.a;
        return *this;
    }

    RGBAColor& RGBAColor::add(const Uint32 color)
    {
        RGBAColor c(color);
        r += c.r;
        g += c.g;
        b += c.b;
        a += c.a;
        return *this;
    }

    RGBAColor& RGBAColor::sub(const RGBAColor& color)
    {
        r -= color.r;
        g -= color.g;
        b -= color.b;
        a -= color.a;
        return *this;
    }

    RGBAColor& RGBAColor::sub(const Uint32 color)
    {
        RGBAColor c(color);
        r -= c.r;
        g -= c.g;
        b -= c.b;
        a -= c.a;
        return *this;
    }

    RGBAColor& RGBAColor::operator+=(const RGBAColor& color)
    {
        return add(color);
    }

    RGBAColor& RGBAColor::operator+=(const Uint32 color)
    {
        return add(color);
    }

    RGBAColor RGBAColor::operator+(const RGBAColor& color)
    {
        RGBAColor c = *this;
        return c.add(color);
    }

    RGBAColor RGBAColor::operator+(const Uint32 color)
    {
        RGBAColor c = *this;
        return c.add(color);
    }

    RGBAColor& RGBAColor::operator-=(const RGBAColor& color)
    {
        return sub(color);
    }

    RGBAColor& RGBAColor::operator-=(const Uint32 color)
    {
        return sub(color);
    }

    RGBAColor RGBAColor::operator-(const RGBAColor& color)
    {
        RGBAColor c = *this;
        return c.sub(color);
    }

    RGBAColor RGBAColor::operator-(const Uint32 color)
    {
        RGBAColor c = *this;
        return c.sub(color);
    }

    bool operator==(const RGBAColor& left, const RGBAColor& right)
    {
        return left.r == right.r && left.g == right.g && left.b == right.b && left.a == right.a;
    }

    bool operator!=(const RGBAColor& left, const RGBAColor& right)
    {
        return !(left == right);
    }

    bool operator<(const RGBAColor& left, const RGBAColor& right)
    {
        return left.r < right.r && left.g < right.g && left.b < right.b && left.a < right.a;
    }

    bool operator<=(const RGBAColor& left, const RGBAColor& right)
    {
        return left.r <= right.r && left.g <= right.g && left.b <= right.b && left.a <= right.a;
    }

    bool operator>(const RGBAColor& left, const RGBAColor& right)
    {
        return left.r > right.r && left.g > right.g && left.b > right.b && left.a > right.a;
    }

    bool operator>=(const RGBAColor& left, const RGBAColor& right)
    {
        return left.r >= right.r && left.g >= right.g && left.b >= right.b && left.a >= right.a;
    }

}  // namespace cyanide::cyutil