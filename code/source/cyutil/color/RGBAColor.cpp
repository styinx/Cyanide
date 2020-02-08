#include "cyutil/color/RGBAColor.hpp"

#include <cmath>

namespace cyanide::cyutil
{

    RGBAColor::RGBAColor()
        : r(0)
        , g(0)
        , b(0)
        , a(0xFF)
    {
    }

    RGBAColor::RGBAColor(const Uint32 color)
    {
        r = static_cast<Byte>((color >> 24U) & 0xFF);
        g = static_cast<Byte>((color >> 16U) & 0xFF);
        b = static_cast<Byte>((color >> 8U) & 0xFF);
        a = static_cast<Byte>(color & 0xFFU);
    }

    RGBAColor::RGBAColor(const RGBA color)
    {
        const auto rgba = static_cast<Uint32>(color);

        r = static_cast<Byte>((rgba >> 24U) & 0xFF);
        g = static_cast<Byte>((rgba >> 16U) & 0xFF);
        b = static_cast<Byte>((rgba >> 8U) & 0xFF);
        a = static_cast<Byte>(rgba & 0xFFU);
    }

    RGBAColor::RGBAColor(const Byte r, const Byte g, const Byte b, const Byte a)
        : r(r)
        , g(g)
        , b(b)
        , a(a)
    {
    }

    RGBAColor::operator Uint32()
    {
        Uint32 color = 0x00000000;
        color        = (color + r) << 8U;
        color        = (color + g) << 8U;
        color        = (color + b) << 8U;
        color += a;

        return color;
    }

    RGBAColor& RGBAColor::set(const Byte r, const Byte g, const Byte b, const Byte a)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
        return *this;
    }

    RGBAColor& RGBAColor::add(const Byte r, const Byte g, const Byte b, const Byte a)
    {
        this->r = std::min(255, this->r + r);
        this->g = std::min(255, this->g + g);
        this->b = std::min(255, this->b + b);
        this->a = std::min(255, this->a + a);
        return *this;
    }

    RGBAColor& RGBAColor::sub(const Byte r, const Byte g, const Byte b, const Byte a)
    {
        this->r = std::max(0, this->r - r);
        this->g = std::max(0, this->g - r);
        this->b = std::max(0, this->b - r);
        this->a = std::max(0, this->a - a);
        return *this;
    }

    RGBAColor& RGBAColor::mul(const float r, const float g, const float b, const float a)
    {
        this->r = static_cast<Byte>(std::lround((float)this->r * r));
        this->g = static_cast<Byte>(std::lround((float)this->g * g));
        this->b = static_cast<Byte>(std::lround((float)this->b * b));
        this->a = static_cast<Byte>(std::lround((float)this->a * a));
        return *this;
    }

    RGBAColor& RGBAColor::div(const float r, const float g, const float b, const float a)
    {
        this->r = static_cast<Byte>(std::lround((float)this->r / r));
        this->g = static_cast<Byte>(std::lround((float)this->g / g));
        this->b = static_cast<Byte>(std::lround((float)this->b / b));
        this->a = static_cast<Byte>(std::lround((float)this->a / a));
        return *this;
    }

    RGBAColor RGBAColor::operator+(const RGBAColor& color)
    {
        RGBAColor c = *this;
        return c.add(color.a, color.g, color.b, color.a);
    }

    RGBAColor& RGBAColor::operator+=(const RGBAColor& color)
    {
        return add(color.a, color.g, color.b, color.a);
    }

    RGBAColor RGBAColor::operator-(const RGBAColor& color)
    {
        RGBAColor c = *this;
        return c.sub(color.a, color.g, color.b, color.a);
    }

    RGBAColor& RGBAColor::operator-=(const RGBAColor& color)
    {
        return sub(color.a, color.g, color.b, color.a);
    }

    RGBAColor RGBAColor::operator+(const Uint32 color)
    {
        RGBAColor c = *this;
        return c + RGBAColor(color);
    }

    RGBAColor& RGBAColor::operator+=(const Uint32 color)
    {
        RGBAColor rgba(color);
        return add(rgba.a, rgba.g, rgba.b, rgba.a);
    }

    RGBAColor RGBAColor::operator-(const Uint32 color)
    {
        RGBAColor c = *this;
        return c - RGBAColor(color);
    }

    RGBAColor& RGBAColor::operator-=(const Uint32 color)
    {
        RGBAColor rgba(color);
        return sub(rgba.a, rgba.g, rgba.b, rgba.a);
    }

    RGBAColor RGBAColor::operator*(const float scalar)
    {
        RGBAColor color = *this;
        return color.mul(scalar, scalar, scalar, scalar);
    }

    RGBAColor& RGBAColor::operator*=(const float scalar)
    {
        return mul(scalar, scalar, scalar, scalar);
    }

    RGBAColor RGBAColor::operator/(const float scalar)
    {
        RGBAColor color = *this;
        return color.div(scalar, scalar, scalar, scalar);
    }

    RGBAColor& RGBAColor::operator/=(const float scalar)
    {
        return div(scalar, scalar, scalar, scalar);
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
