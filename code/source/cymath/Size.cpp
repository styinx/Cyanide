#include "cymath/Size.hpp"

#include <cmath>

namespace Cyanide
{
namespace cymath
{

    Size::Size()
        : width(0)
        , height(0)
    {
    }

    Size::Size(Sint32 width, Sint32 height)
        : width(width)
        , height(height)
    {
    }

    Size& Size::set(Sint32 w, Sint32 h)
    {
        width  = w;
        height = h;
        return *this;
    }

    Size& Size::add(Sint32 w, Sint32 h)
    {
        width += w;
        height += h;
        return *this;
    }

    Size& Size::add(Size p)
    {
        width += p.width;
        height += p.height;
        return *this;
    }

    Size& Size::sub(Sint32 w, Sint32 h)
    {
        width -= w;
        height -= h;
        return *this;
    }

    Size& Size::sub(Size p)
    {
        width -= p.width;
        height -= p.height;
        return *this;
    }

    Size& Size::mul(Sint32 w, Sint32 h)
    {
        width *= w;
        height *= h;
        return *this;
    }

    Size& Size::mul(float w, float h)
    {
        width  = static_cast<Sint32>(std::lround(width * w));
        height = static_cast<Sint32>(std::lround(height * h));
        return *this;
    }

    Size& Size::div(Sint32 w, Sint32 h)
    {
        width  = static_cast<Sint32>(std::lround(width / w));
        height = static_cast<Sint32>(std::lround(height / h));
        return *this;
    }

    Size& Size::div(float w, float h)
    {
        width  = static_cast<Sint32>(std::lround(width / w));
        height = static_cast<Sint32>(std::lround(height / h));
        return *this;
    }

    Size Size::operator+(const Size& other) { return {width + other.width, height + other.height}; }

    Size& Size::operator+=(const Size& other) { return add(other.width, other.height); }

    Size Size::operator-(const Size& other) { return {width - other.width, height - other.height}; }

    Size& Size::operator-=(const Size& other) { return sub(other.width, other.height); }

    Size Size::operator*(const Size& other) { return {width * other.width, height * other.height}; }

    Size& Size::operator*=(const Size& other) { return mul(other.width, other.height); }

    Size Size::operator/(const Size& other)
    {
        Size s = *this;
        return s.div(other.width, other.height);
    }

    Size& Size::operator/=(const Size& other) { return div(other.width, other.height); }

    Size Size::operator*(Sint32 scalar) { return {width * scalar, height * scalar}; }

    Size Size::operator*(float scalar)
    {
        Size s = *this;
        return s.mul(scalar, scalar);
    }

    Size& Size::operator*=(Sint32 scalar) { return mul(scalar, scalar); }

    Size& Size::operator*=(float scalar) { return mul(scalar, scalar); }

    Size Size::operator/(Sint32 scalar)
    {
        Size s = *this;
        return s.div(scalar, scalar);
    }

    Size Size::operator/(float scalar)
    {
        Size s = *this;
        return s.div(scalar, scalar);
    }

    Size& Size::operator/=(Sint32 scalar) { return div(scalar, scalar); }

    Size& Size::operator/=(float scalar) { return div(scalar, scalar); }

}  // namespace cymath
}  // namespace Cyanide