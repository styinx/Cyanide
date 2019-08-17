#include "cymath/Size.hpp"

#include <cmath>

namespace cyanide::cymath
{

    Size::Size()
        : width(0)
        , height(0)
    {
    }

    Size::Size(const Sint32 width, const Sint32 height)
        : width(width)
        , height(height)
    {
    }

    Size& Size::set(const Sint32 w, const Sint32 h)
    {
        width  = w;
        height = h;
        return *this;
    }

    Size& Size::add(const Sint32 w, const Sint32 h)
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

    Size& Size::sub(const Sint32 w, const Sint32 h)
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

    Size& Size::mul(const Sint32 w, const Sint32 h)
    {
        width *= w;
        height *= h;
        return *this;
    }

    Size& Size::mul(const float w, const float h)
    {
        width  = static_cast<Sint32>(std::lround(width * w));
        height = static_cast<Sint32>(std::lround(height * h));
        return *this;
    }

    Size& Size::div(const Sint32 w, const Sint32 h)
    {
        width  = static_cast<Sint32>(std::lround(width / w));
        height = static_cast<Sint32>(std::lround(height / h));
        return *this;
    }

    Size& Size::div(const float w, const float h)
    {
        width  = static_cast<Sint32>(std::lround(width / w));
        height = static_cast<Sint32>(std::lround(height / h));
        return *this;
    }

    Size Size::operator+(const Size& other)
    {
        return {width + other.width, height + other.height};
    }

    Size& Size::operator+=(const Size& other)
    {
        return add(other.width, other.height);
    }

    Size Size::operator-(const Size& other)
    {
        return {width - other.width, height - other.height};
    }

    Size& Size::operator-=(const Size& other)
    {
        return sub(other.width, other.height);
    }

    Size Size::operator*(const Size& other)
    {
        return {width * other.width, height * other.height};
    }

    Size& Size::operator*=(const Size& other)
    {
        return mul(other.width, other.height);
    }

    Size Size::operator/(const Size& other)
    {
        Size s = *this;
        return s.div(other.width, other.height);
    }

    Size& Size::operator/=(const Size& other)
    {
        return div(other.width, other.height);
    }

    Size Size::operator*(const Sint32 scalar)
    {
        return {width * scalar, height * scalar};
    }

    Size Size::operator*(const float scalar)
    {
        Size s = *this;
        return s.mul(scalar, scalar);
    }

    Size& Size::operator*=(const Sint32 scalar)
    {
        return mul(scalar, scalar);
    }

    Size& Size::operator*=(const float scalar)
    {
        return mul(scalar, scalar);
    }

    Size Size::operator/(const Sint32 scalar)
    {
        Size s = *this;
        return s.div(scalar, scalar);
    }

    Size Size::operator/(const float scalar)
    {
        Size s = *this;
        return s.div(scalar, scalar);
    }

    Size& Size::operator/=(const Sint32 scalar)
    {
        return div(scalar, scalar);
    }

    Size& Size::operator/=(const float scalar)
    {
        return div(scalar, scalar);
    }

    Size Size::operator+(const Space& space)
    {
        Size s = *this;
        return s.add(space.left + space.right, space.top + space.right);
    }

    Size& Size::operator+=(const Space& space)
    {
        return add(space.left + space.right, space.top + space.right);
    }

    Size Size::operator-(const Space& space)
    {
        Size s = *this;
        return s.sub(space.left + space.right, space.top + space.right);
    }

    Size& Size::operator-=(const Space& space)
    {
        return sub(space.left + space.right, space.top + space.right);
    }

    Size& Size::max(Size& first, Size& second)
    {
        return first >= second ? first : second;
    }

    Size& Size::min(Size& first, Size& second)
    {
        return first <= second ? first : second;
    }

    bool operator==(const Size& first, const Size& second)
    {
        return first.width == second.width && first.height == second.height;
    }
    bool operator!=(const Size& first, const Size& second)
    {
        return !(first == second);
    }
    bool operator<(const Size& first, const Size& second)
    {
        return first.width < second.width && first.height < second.height;
    }
    bool operator<=(const Size& first, const Size& second)
    {
        return first.width <= second.width && first.height <= second.height;
    }
    bool operator>(const Size& first, const Size& second)
    {
        return first.width > second.width && first.height > second.height;
    }
    bool operator>=(const Size& first, const Size& second)
    {
        return first.width >= second.width && first.height >= second.height;
    }

}  // namespace cyanide::cymath