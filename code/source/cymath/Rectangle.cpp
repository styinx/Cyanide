#include "cymath/Rectangle.hpp"

#include <cmath>

namespace cyanide::cymath
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

    Rectangle::Rectangle(const Point& p, const Size& s)
        : x(p.x)
        , y(p.y)
        , w(s.width)
        , h(s.height)
    {
    }

    Rectangle::operator bool() const
    {
        return !empty();
    }

    bool Rectangle::empty() const
    {
        return x + y + w + h == 0;
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
        return {static_cast<Sint32>(std::lround(x + w / 2.0F)),
                static_cast<Sint32>(std::lround(y + h / 2.0F))};
    }

    Point Rectangle::getPosition() const
    {
        return {x, y};
    }

    Rectangle& Rectangle::setPosition(const Point& p)
    {
        x = p.x;
        y = p.y;
        return *this;
    }

    Size Rectangle::getSize() const
    {
        return {w, h};
    }

    Rectangle& Rectangle::setSize(const Size& s)
    {
        w = s.width;
        h = s.height;
        return *this;
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

    Rectangle& Rectangle::mul(const float x, const float y, const float w, const float h)
    {
        this->x = static_cast<Sint32>(std::lround(this->x * x));
        this->y = static_cast<Sint32>(std::lround(this->y * y));
        this->w = static_cast<Sint32>(std::lround(this->w * w));
        this->h = static_cast<Sint32>(std::lround(this->h * h));
        return *this;
    }

    Rectangle& Rectangle::div(const float x, const float y, const float w, const float h)
    {
        if(x != 0)
            this->x = static_cast<Sint32>(std::lround(this->x / x));
        if(y != 0)
            this->y = static_cast<Sint32>(std::lround(this->y / y));
        if(w != 0)
            this->w = static_cast<Sint32>(std::lround(this->w / w));
        if(h != 0)
            this->h = static_cast<Sint32>(std::lround(this->h / h));
        return *this;
    }

    Rectangle Rectangle::operator+(const Rectangle& other)
    {
        return {x + other.x, y + other.y, w + other.w, h + other.h};
    }

    Rectangle& Rectangle::operator+=(const Rectangle& other)
    {
        return add(other.x, other.y, other.w, other.h);
    }

    Rectangle Rectangle::operator-(const Rectangle& other)
    {
        return {x - other.x, y - other.y, w - other.w, h - other.h};
    }

    Rectangle& Rectangle::operator-=(const Rectangle& other)
    {
        return sub(other.x, other.y, other.w, other.h);
    }

    Rectangle Rectangle::operator*(const Rectangle& other)
    {
        return {x * other.x, y * other.y, w * other.w, h * other.h};
    }

    Rectangle& Rectangle::operator*=(const Rectangle& other)
    {
        return mul(other.x, other.y, other.w, other.h);
    }

    Rectangle Rectangle::operator/(const Rectangle& other)
    {
        Rectangle r = *this;
        return r.div(other.x, other.y, other.w, other.h);
    }

    Rectangle& Rectangle::operator/=(const Rectangle& other)
    {
        return div(other.x, other.y, other.w, other.h);
    }

    Rectangle Rectangle::operator*(const float scalar)
    {
        Rectangle r = *this;
        return r.mul(scalar, scalar, scalar, scalar);
    }

    Rectangle& Rectangle::operator*=(const float scalar)
    {
        return mul(scalar, scalar, scalar, scalar);
    }

    Rectangle Rectangle::operator/(const float scalar)
    {
        Rectangle r = *this;
        return r.div(scalar, scalar, scalar, scalar);
    }

    Rectangle& Rectangle::operator/=(const float scalar)
    {
        return div(scalar, scalar, scalar, scalar);
    }

    Rectangle Rectangle::operator+(const Space& space)
    {
        Rectangle r = *this;
        return r.add(-space.left, -space.top, space.right * 2, space.bottom * 2);
    }

    Rectangle& Rectangle::operator+=(const Space& space)
    {
        return add(-space.left, -space.top, space.right * 2, space.bottom * 2);
    }

    Rectangle Rectangle::operator-(const Space& space)
    {
        Rectangle r = *this;
        return r.add(space.left, space.top, -space.right * 2, -space.bottom * 2);
    }

    Rectangle& Rectangle::operator-=(const Space& space)
    {
        return add(space.left, space.top, -space.right * 2, -space.bottom * 2);
    }

    Rectangle& Rectangle::max(Rectangle& first, Rectangle& second)
    {
        return first >= second ? first : second;
    }

    Rectangle& Rectangle::min(Rectangle& first, Rectangle& second)
    {
        return first <= second ? first : second;
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

        return ((tl1 >= tl2) || (br1 <= br2)) && (first.w <= second.w) && (first.h <= second.h);
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

        return ((tl1 <= tl2) || (br1 >= br2)) && (first.w >= second.w) && (first.h >= second.h);
    }

}  // namespace cyanide::cymath
