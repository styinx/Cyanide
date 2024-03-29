
#include <cmath>
#include "cymath/Space.hpp"

namespace cyanide::cymath
{

    Space::Space()
        : top(0)
        , right(0)
        , bottom(0)
        , left(0)
    {
    }

    Space::Space(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left)
        : top(top)
        , right(right)
        , bottom(bottom)
        , left(left)
    {
    }

    Space::operator bool() const
    {
        return !empty();
    }

    bool Space::empty() const
    {
        return top + right + bottom + left == 0;
    }

    Space& Space::set(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left)
    {
        this->top    = top;
        this->right  = right;
        this->bottom = bottom;
        this->left   = left;
        return *this;
    }

    Space& Space::add(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left)
    {
        this->top += top;
        this->right += right;
        this->bottom += bottom;
        this->left += left;
        return *this;
    }

    Space& Space::sub(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left)
    {
        this->top -= top;
        this->right -= right;
        this->bottom -= bottom;
        this->left -= left;
        return *this;
    }

    Space& Space::mul(const float top, const float right, const float bottom, const float left)
    {
        this->top    = static_cast<Sint32>(std::lround(this->top * top));
        this->right  = static_cast<Sint32>(std::lround(this->right * right));
        this->bottom = static_cast<Sint32>(std::lround(this->bottom * bottom));
        this->left   = static_cast<Sint32>(std::lround(this->left * left));
        return *this;
    }

    Space& Space::div(const float top, const float right, const float bottom, const float left)
    {
        if(top != 0)
            this->top = static_cast<Sint32>(this->top * top);
        if(right != 0)
            this->right = static_cast<Sint32>(this->right * right);
        if(bottom != 0)
            this->bottom = static_cast<Sint32>(this->bottom * bottom);
        if(left != 0)
            this->left = static_cast<Sint32>(this->left * left);
        return *this;
    }

    Space Space::operator+(const Space& other)
    {
        return {top + other.top, right + other.right, bottom + other.bottom, left + other.left};
    }

    Space& Space::operator+=(const Space& other)
    {
        return add(other.top, other.right, other.bottom, other.left);
    }

    Space Space::operator-(const Space& other)
    {
        return {top - other.top, right - other.right, bottom - other.bottom, left - other.left};
    }

    Space& Space::operator-=(const Space& other)
    {
        return sub(other.top, other.right, other.bottom, other.left);
    }

    Space Space::operator*(const Space& other)
    {
        return {top * other.top, right * other.right, bottom * other.bottom, left * other.left};
    }

    Space& Space::operator*=(const Space& other)
    {
        return mul(other.top, other.right, other.bottom, other.left);
    }

    Space Space::operator/(const Space& other)
    {
        Space s = *this;
        return s.div(other.top, other.right, other.bottom, other.left);
    }

    Space& Space::operator/=(const Space& other)
    {
        return div(other.top, other.right, other.bottom, other.left);
    }

    Space Space::operator*(const float scalar)
    {
        Space s = *this;
        return s.mul(scalar, scalar, scalar, scalar);
    }

    Space& Space::operator*=(const float scalar)
    {
        return mul(scalar, scalar, scalar, scalar);
    }

    Space Space::operator/(const float scalar)
    {
        Space s = *this;
        return s.div(scalar, scalar, scalar, scalar);
    }

    Space& Space::operator/=(const float scalar)
    {
        return mul(scalar, scalar, scalar, scalar);
    }

}  // namespace cyanide::cymath
