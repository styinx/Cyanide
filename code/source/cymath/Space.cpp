
#include <cymath/Space.hpp>

#include "cymath/Space.hpp"

namespace Cyanide
{
namespace cymath
{

    Space::Space()
        : top(0)
        , right(0)
        , bottom(0)
        , left(0)
    {
    }

    Space::Space(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left)
        : top(top)
        , right(right)
        , bottom(bottom)
        , left(left)
    {
    }

    Space& Space::set(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left)
    {
        this->top    = top;
        this->right  = right;
        this->bottom = bottom;
        this->left   = left;
        return *this;
    }

    Space& Space::add(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left)
    {
        this->top += top;
        this->right += right;
        this->bottom += bottom;
        this->left += left;
        return *this;
    }

    Space& Space::sub(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left)
    {
        this->top -= top;
        this->right -= right;
        this->bottom -= bottom;
        this->left -= left;
        return *this;
    }

    Space& Space::mul(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left)
    {
        this->top *= top;
        this->right *= right;
        this->bottom *= bottom;
        this->left *= left;
        return *this;
    }

    Space& Space::mul(float top, float right, float bottom, float left)
    {
        this->top    = static_cast<Sint32>(this->top * top);
        this->right  = static_cast<Sint32>(this->right * right);
        this->bottom = static_cast<Sint32>(this->bottom * bottom);
        this->left   = static_cast<Sint32>(this->left * left);
        return *this;
    }

    Space& Space::div(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left)
    {
        if(top != 0) this->top = static_cast<Sint32>(this->top * top);
        if(right != 0) this->right = static_cast<Sint32>(this->right * right);
        if(bottom != 0) this->bottom = static_cast<Sint32>(this->bottom * bottom);
        if(left != 0) this->left = static_cast<Sint32>(this->left * left);
        return *this;
    }

    Space& Space::div(float top, float right, float bottom, float left)
    {
        if(top != 0) this->top = static_cast<Sint32>(this->top * top);
        if(right != 0) this->right = static_cast<Sint32>(this->right * right);
        if(bottom != 0) this->bottom = static_cast<Sint32>(this->bottom * bottom);
        if(left != 0) this->left = static_cast<Sint32>(this->left * left);
        return *this;
    }

    Space Space::operator+(const Space& other)
    {
        return {top + other.top, right + other.right, bottom + other.bottom, left + other.left};
    }

    Space& Space::operator+=(const Space& other)
    {
        return this->add(other.top, other.right, other.bottom, other.left);
    }

    Space Space::operator-(const Space& other)
    {
        return {top - other.top, right - other.right, bottom - other.bottom, left - other.left};
    }

    Space& Space::operator-=(const Space& other)
    {
        return this->sub(other.top, other.right, other.bottom, other.left);
    }

    Space Space::operator*(const Space& other)
    {
        return {top * other.top, right * other.right, bottom * other.bottom, left * other.left};
    }

    Space& Space::operator*=(const Space& other)
    {
        return this->mul(other.top, other.right, other.bottom, other.left);
    }

    Space Space::operator/(const Space& other)
    {
        Space s = *this;
        return s.div(other.top, other.right, other.bottom, other.left);
    }

    Space& Space::operator/=(const Space& other)
    {
        return this->div(other.top, other.right, other.bottom, other.left);
    }

    Space Space::operator*(Sint32 scalar)
    {
        Space s = *this;
        return s.mul(scalar, scalar, scalar, scalar);
    }

    Space Space::operator*(float scalar)
    {
        Space s = *this;
        return s.mul(scalar, scalar, scalar, scalar);
    }

    Space& Space::operator*=(Sint32 scalar)
    {
        return this->mul(scalar, scalar, scalar, scalar);
    }

    Space& Space::operator*=(float scalar)
    {
        return this->mul(scalar, scalar, scalar, scalar);
    }

    Space Space::operator/(Sint32 scalar)
    {
        Space s = *this;
        return s.div(scalar, scalar, scalar, scalar);
    }

    Space Space::operator/(float scalar)
    {
        Space s = *this;
        return s.div(scalar, scalar, scalar, scalar);
    }

    Space& Space::operator/=(Sint32 scalar)
    {
        return this->mul(scalar, scalar, scalar, scalar);
    }

    Space& Space::operator/=(float scalar)
    {
        return this->mul(scalar, scalar, scalar, scalar);
    }

}  // namespace cymath
}  // namespace Cyanide