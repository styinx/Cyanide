#include "cymath/Rectangle.hpp"

#include <cmath>


namespace Cyanide
{
namespace cymath
{

    Rectangle::Rectangle()
        : x(0)
        , y(0)
        , w(0)
        , h(0)
    {
    }

    Rectangle::Rectangle(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h)
        : x(x)
        , y(y)
        , w(w)
        , h(h)
    {
    }

    Point Rectangle::topLeft() const
    {
        return {x, y};
    }

    Point Rectangle::topRight() const
    {
        return {x + w, y};
    }

    Point Rectangle::bottomLeft() const
    {
        return {x, y + h};
    }

    Point Rectangle::bottomRight() const
    {
        return {x + w, y + h};
    }

    Point Rectangle::center() const
    {
        return bottomRight() / 2;
    }

    Size Rectangle::getSize() const
    {
        return Size(w, h);
    }

    Rectangle& Rectangle::set(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        return *this;
    }

    Rectangle& Rectangle::add(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h)
    {
        this->x += x;
        this->y += y;
        this->w += w;
        this->h += h;
        return *this;
    }

    Rectangle& Rectangle::sub(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h)
    {
        this->x -= x;
        this->y -= y;
        this->w -= w;
        this->h -= h;
        return *this;
    }

    Rectangle& Rectangle::mul(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h)
    {
        this->x *= x;
        this->y *= y;
        this->w *= w;
        this->h *= h;
        return *this;
    }

    Rectangle &Rectangle::mul(const float x, const float y, const float w, const float h)
    {
        this->x = static_cast<Sint32>(std::lround(this->x * x));
        this->y = static_cast<Sint32>(std::lround(this->y * y));
        this->w = static_cast<Sint32>(std::lround(this->w * w));
        this->h = static_cast<Sint32>(std::lround(this->h * h));
        return *this;
    }

    Rectangle& Rectangle::div(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h)
    {
        if(x != 0) this->x = static_cast<Sint32>(std::lround(this->x / x));
        if(y != 0) this->y = static_cast<Sint32>(std::lround(this->y / y));
        if(w != 0) this->w = static_cast<Sint32>(std::lround(this->w / w));
        if(h != 0) this->h = static_cast<Sint32>(std::lround(this->h / h));
        return *this;
    }

    Rectangle &Rectangle::div(const float x, const float y, const float w, const float h)
    {
        if(x != 0) this->x = static_cast<Sint32>(std::lround(this->x / x));
        if(y != 0) this->y = static_cast<Sint32>(std::lround(this->y / y));
        if(w != 0) this->w = static_cast<Sint32>(std::lround(this->w / w));
        if(h != 0) this->h = static_cast<Sint32>(std::lround(this->h / h));
        return *this;
    }

    Rectangle Rectangle::operator+(const Rectangle& other)
    {
        return {x + other.x, y + other.y, w + other.w, h + other.h};
    }

    Rectangle& Rectangle::operator+=(const Rectangle& other)
    {
        return this->add(other.x, other.y, other.w, other.h);
    }

    Rectangle Rectangle::operator-(const Rectangle& other)
    {
        return {x - other.x, y - other.y, w - other.w, h - other.h};
    }

    Rectangle& Rectangle::operator-=(const Rectangle& other)
    {
        return this->sub(other.x, other.y, other.w, other.h);
    }

    Rectangle Rectangle::operator*(const Rectangle& other)
    {
        return {x * other.x, y * other.y, w * other.w, h * other.h};
    }

    Rectangle& Rectangle::operator*=(const Rectangle& other)
    {
        return this->mul(other.x, other.y, other.w, other.h);
    }

    Rectangle Rectangle::operator/(const Rectangle& other)
    {
        Rectangle r = *this;
        return r.div(other.x, other.y, other.w, other.h);
    }

    Rectangle& Rectangle::operator/=(const Rectangle& other)
    {
        return this->div(other.x, other.y, other.w, other.h);
    }

    Rectangle Rectangle::operator*(const Sint32 scalar)
    {
        return {x * scalar, y * scalar, w * scalar, h * scalar};
    }

    Rectangle Rectangle::operator*(const float scalar)
    {
        Rectangle r = *this;
        return r.mul(scalar, scalar, scalar, scalar);
    }

    Rectangle& Rectangle::operator*=(const Sint32 scalar)
    {
        return this->mul(scalar, scalar, scalar, scalar);
    }

    Rectangle &Rectangle::operator*=(const float scalar)
    {
        return this->mul(scalar, scalar, scalar, scalar);
    }

    Rectangle Rectangle::operator/(const Sint32 scalar)
    {
        Rectangle r = *this;
        return r.div(scalar, scalar, scalar, scalar);
    }

    Rectangle Rectangle::operator/(const float scalar)
    {
        Rectangle r = *this;
        return r.div(scalar, scalar, scalar, scalar);
    }

    Rectangle& Rectangle::operator/=(const Sint32 scalar)
    {
        return this->div(scalar, scalar, scalar, scalar);
    }

    Rectangle &Rectangle::operator/=(const float scalar)
    {
        return this->div(scalar, scalar, scalar, scalar);
    }

    bool operator==(const Rectangle& first, const Rectangle& second)
    {
        return (first.x == second.x) && (first.y == second.y) && (first.w == second.w) &&
               (first.h == second.h);
    }

    bool operator!=(const Rectangle& first, const Rectangle& second)
    {
        return !(first == second);
    }

    bool operator<(const Rectangle& first, const Rectangle& second)
    {
        Point tl1 = first.topLeft();
        Point tl2 = second.topLeft();
        Point br1 = first.bottomRight();
        Point br2 = second.bottomRight();

        return ((tl1 >= tl2) || (br1 <= br2)) && (first.w < second.w) && (first.h < second.h);
    }

    bool operator<=(const Rectangle& first, const Rectangle& second)
    {
        Point tl1 = first.topLeft();
        Point tl2 = second.topLeft();
        Point br1 = first.bottomRight();
        Point br2 = second.bottomRight();

        return ((tl1 >= tl2) || (br1 <= br2)) && (first.w <= second.w) &&
               (first.h <= second.h);
    }

    bool operator>(const Rectangle& first, const Rectangle& second)
    {
        Point tl1 = first.topLeft();
        Point tl2 = second.topLeft();
        Point br1 = first.bottomRight();
        Point br2 = second.bottomRight();

        return ((tl1 <= tl2) || (br1 >= br2)) && (first.w > second.w) && (first.h > second.h);
    }

    bool operator>=(const Rectangle& first, const Rectangle& second)
    {
        Point tl1 = first.topLeft();
        Point tl2 = second.topLeft();
        Point br1 = first.bottomRight();
        Point br2 = second.bottomRight();

        return ((tl1 <= tl2) || (br1 >= br2)) && (first.w >= second.w) &&
               (first.h >= second.h);
    }

    Rectangle& Rectangle::max(Rectangle& first, Rectangle& second)
    {
        return first >= second ? first : second;
    }

    Rectangle& Rectangle::min(Rectangle& first, Rectangle& second)
    {
        return first <= second ? first : second;
    }

}  // namespace cymath
}  // namespace Cyanide