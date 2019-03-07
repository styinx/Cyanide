
#include <cyutil/color/Color.hpp>

#include "cyutil/color/Color.hpp"

namespace Cyanide
{
namespace cyutil
{

    Color::Color(Uint32 color)
    {
        r = static_cast<Uint8>((color >> 24u) & 0xFF);
        g = static_cast<Uint8>((color >> 16u) & 0xFF);
        b = static_cast<Uint8>((color >> 8u) & 0xFF);
        a = static_cast<Uint8>(color & 0xFFu);
    }

    Color::Color(Uint8 r, Uint8 g, Uint8 b)
        : r(r)
        , g(g)
        , b(b)
    {
    }

    Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
        : r(r)
        , g(g)
        , b(b)
        , a(a)
    {
    }

    Color::operator Uint32 ()
    {
        Uint32 color = 0x00000000;
        color = (color + r) << 8u;
        color = (color + g) << 8u;
        color = (color + b) << 8u;
        color += a;

        return color;
    }

    Color &Color::add(Color color)
    {
        r += color.r;
        g += color.g;
        b += color.b;
        a += color.a;
        return *this;
    }

    Color &Color::add(Uint32 color)
    {
        Color c(color);
        r += c.r;
        g += c.g;
        b += c.b;
        a += c.a;
        return *this;
    }

    Color &Color::sub(Color color)
    {
        r -= color.r;
        g -= color.g;
        b -= color.b;
        a -= color.a;
        return *this;
    }

    Color &Color::sub(Uint32 color)
    {
        Color c(color);
        r -= c.r;
        g -= c.g;
        b -= c.b;
        a -= c.a;
        return *this;
    }

    Color &Color::operator+=(Color color)
    {
        return this->add(color);
    }

    Color &Color::operator+=(Uint32 color)
    {
        return this->add(color);
    }

    Color Color::operator+(Color color)
    {
        Color c = *this;
        return c.add(color);
    }

    Color Color::operator+(Uint32 color)
    {
        Color c = *this;
        return c.add(color);
    }

    Color &Color::operator-=(Color color)
    {
        return this->sub(color);
    }

    Color &Color::operator-=(Uint32 color)
    {
        return this->sub(color);
    }

    Color Color::operator-(Color color)
    {
        Color c = *this;
        return c.sub(color);
    }

    Color Color::operator-(Uint32 color)
    {
        Color c = *this;
        return c.sub(color);
    }

    bool operator==(Color left, Color right)
    {
        return Uint32(left) == Uint32(right);
    }

    bool operator!=(Color left, Color right)
    {
        return !(left == right);
    }

    bool operator<(Color left, Color right)
    {
        return Uint32(left) < Uint32(right);
    }

    bool operator<=(Color left, Color right)
    {
        return Uint32(left) <= Uint32(right);
    }

    bool operator>(Color left, Color right)
    {
        return Uint32(left) > Uint32(right);
    }

    bool operator>=(Color left, Color right)
    {
        return Uint32(left) >= Uint32(right);
    }

}  // namespace cyutil
}  // namespace Cyanide