#include "cyutil/color/RGBAColor.hpp"

#include "cystd/Enum.hpp"

#include <cmath>

namespace cyanide::cyutil
{

    RGBAColor::RGBAColor()
        : r(0)
        , g(0)
        , b(0)
        , a(Default::MASK)
    {
    }

    RGBAColor::RGBAColor(const Uint32 color)
    {
        const auto rgba = toRGBA(color);

        r = rgba.r;
        g = rgba.g;
        b = rgba.b;
        a = rgba.a;
    }

    RGBAColor::RGBAColor(const String& color)
    {
        if(color.front() != '#')
        {
            // err
        }

        String value = color.substr(1);

        // TODO refactor
        for(const auto& c : value)
        {
            if(!((c >= 48 && c <= 57) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102)))
            {
                // err
                break;
            }
        }

        if(value.size() == 3)
        {
            char*  hex = value.data();
            String temp{};
            temp += hex[0];
            temp += hex[0];
            temp += hex[1];
            temp += hex[1];
            temp += hex[2];
            temp += hex[2];
            value = temp;
        }

        if(value.size() != 6)
        {
            // err
        }

        const auto rgba = RGBAColor::toRGBA(std::stoi(value));

        r = rgba.r;
        g = rgba.g;
        b = rgba.b;
        a = rgba.a;
    }

    RGBAColor::RGBAColor(const RGBA color)
    {
        const auto rgba = RGBAColor::toRGBA(cystd::fromEnum(color));

        r = rgba.r;
        g = rgba.g;
        b = rgba.b;
        a = rgba.a;
    }

    RGBAColor::RGBAColor(const Byte r, const Byte g, const Byte b, const Byte a)
        : r(r)
        , g(g)
        , b(b)
        , a(a)
    {
    }

    // Private

    RGBAColor RGBAColor::toRGBA(const Uint32 value)
    {
        RGBAColor color;

        color.r = static_cast<Byte>((value >> 24U) & Default::MASK);
        color.g = static_cast<Byte>((value >> 16U) & Default::MASK);
        color.b = static_cast<Byte>((value >> 8U) & Default::MASK);
        color.a = static_cast<Byte>(value & Default::MASK);

        return color;
    }

    // Public

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
        this->r = std::min<Byte>(Default::RGBA_MAX, this->r + r);
        this->g = std::min<Byte>(Default::RGBA_MAX, this->g + g);
        this->b = std::min<Byte>(Default::RGBA_MAX, this->b + b);
        this->a = std::min<Byte>(Default::RGBA_MAX, this->a + a);
        return *this;
    }

    RGBAColor& RGBAColor::sub(const Byte r, const Byte g, const Byte b, const Byte a)
    {
        this->r = std::max<Byte>(Default::RGBA_MIN, this->r - r);
        this->g = std::max<Byte>(Default::RGBA_MIN, this->g - r);
        this->b = std::max<Byte>(Default::RGBA_MIN, this->b - r);
        this->a = std::max<Byte>(Default::RGBA_MIN, this->a - a);
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
