#include "cymath/Line.hpp"

#include <cmath>

namespace cyanide
{
namespace cymath
{

    Line::Line()
        : x1(0)
        , y1(0)
        , x2(0)
        , y2(0)
    {
    }

    Line::Line(Point p1, Point p2)
        : x1(p1.x)
        , y1(p1.y)
        , x2(p2.x)
        , y2(p2.y)
    {
    }

    Line::Line(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2)
        : x1(x1)
        , y1(y1)
        , x2(x2)
        , y2(y2)
    {
    }

    Point Line::first() const
    {
        return {x1, y1};
    }

    Point Line::second() const
    {
        return {x2, y2};
    }

    Line &Line::set(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        return *this;
    }

    Line &Line::add(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2)
    {
        this->x1 += x1;
        this->y1 += y1;
        this->x2 += x2;
        this->y2 += y2;
        return *this;
    }

    Line &Line::sub(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2)
    {
        this->x1 -= x1;
        this->y1 -= y1;
        this->x2 -= x2;
        this->y2 -= y2;
        return *this;
    }

    Line &Line::mul(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2)
    {
        this->x1 *= x1;
        this->y1 *= y1;
        this->x2 *= x2;
        this->y2 *= y2;
        return *this;
    }

    Line &Line::mul(const float x1, const float y1, const float x2, const float y2)
    {
        this->x1 = static_cast<Sint32>(std::lround(this->x1 * x1));
        this->y1 = static_cast<Sint32>(std::lround(this->y1 * y1));
        this->x2 = static_cast<Sint32>(std::lround(this->x2 * x2));
        this->y2 = static_cast<Sint32>(std::lround(this->y2 * y2));
        return *this;
    }

    Line &Line::div(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2)
    {
        if(x1 != 0) this->x1 = static_cast<Sint32>(std::lround(this->x1 / x1));
        if(y1 != 0) this->y1 = static_cast<Sint32>(std::lround(this->y1 / y1));
        if(x2 != 0) this->x2 = static_cast<Sint32>(std::lround(this->x2 / x2));
        if(y2 != 0) this->y2 = static_cast<Sint32>(std::lround(this->y2 / y2));
        return *this;
    }

    Line &Line::div(const float x1, const float y1, const float x2, const float y2)
    {
        if(x1 != 0) this->x1 = static_cast<Sint32>(std::lround(this->x1 / x1));
        if(y1 != 0) this->y1 = static_cast<Sint32>(std::lround(this->y1 / y1));
        if(x2 != 0) this->x2 = static_cast<Sint32>(std::lround(this->x2 / x2));
        if(y2 != 0) this->y2 = static_cast<Sint32>(std::lround(this->y2 / y2));
        return *this;
    }

    Line Line::operator+(const Line& other)
    {
        return {x1 + other.x1, y1 + other.y1, x2 + other.x2, y2 + other.y2};
    }

    Line& Line::operator+=(const Line& other)
    {
        return this->add(other.x1, other.y1, other.x2, other.y2);
    }

    Line Line::operator-(const Line& other)
    {
        return {x1 - other.x1, y1 - other.y1, x2 - other.x2, y2 - other.y2};
    }

    Line& Line::operator-=(const Line& other)
    {
        return this->sub(other.x1, other.y1, other.x2, other.y2);
    }

    Line Line::operator*(const Line& other)
    {
        return {x1 * other.x1, y1 * other.y1, x2 * other.x2, y2 * other.y2};
    }

    Line& Line::operator*=(const Line& other)
    {
        return this->mul(other.x1, other.y1, other.x2, other.y2);
    }

    Line Line::operator/(const Line& other)
    {
        Line l = *this;
        return l.div(other.x1, other.y1, other.x2, other.y2);
    }

    Line& Line::operator/=(const Line& other)
    {
        return this->div(other.x1, other.y1, other.x2, other.y2);
    }

    Line Line::operator*(const Sint32 scalar)
    {
        return {x1 * scalar, y1 * scalar, x2 * scalar, y2 * scalar};
    }

    Line Line::operator*(const float scalar)
    {
        Line l = *this;
        return l.mul(scalar, scalar, scalar, scalar);
    }

    Line& Line::operator*=(const Sint32 scalar)
    {
        return this->mul(scalar, scalar, scalar, scalar);
    }

    Line &Line::operator*=(const float scalar)
    {
        return this->mul(scalar, scalar, scalar, scalar);
    }

    Line Line::operator/(const Sint32 scalar)
    {
        Line l = *this;
        return l.div(x1 / scalar, y1 / scalar, x2 / scalar, y2 / scalar);
    }

    Line Line::operator/(const float scalar)
    {
        Line l = *this;
        return l.div(scalar, scalar, scalar, scalar);
    }

    Line& Line::operator/=(const Sint32 scalar)
    {
        return this->div(scalar, scalar, scalar, scalar);
    }

    Line &Line::operator/=(const float scalar)
    {
        return this->div(scalar, scalar, scalar, scalar);
    }

    bool operator==(const Line& first, const Line& second)
    {
        return first.first() == second.first() && first.second() == second.second();
    }

    bool operator!=(const Line& first, const Line& second)
    {
        return !(first == second);
    }

    bool operator<(const Line& first, const Line& second)
    {
        return (first.first() < second.first()) && (first.second() < second.second());
    }

    bool operator<=(const Line& first, const Line& second)
    {
        return (first.first() <= second.first()) && (first.second() <= second.second());
    }

    bool operator>(const Line& first, const Line& second)
    {
        return (first.first() > second.first()) && (first.second() > second.second());
    }

    bool operator>=(const Line& first, const Line& second)
    {
        return (first.first() >= second.first()) && (first.second() >= second.second());
    }

}  // namespace cymath
}  // namespace cyanide