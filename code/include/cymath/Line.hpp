#ifndef CYANIDE_LINE_HPP
#define CYANIDE_LINE_HPP

#include "cystd/stdPrototypes.hpp"

#include "cymath/Point.hpp"

namespace Cyanide
{
namespace cymath
{

    class Line
    {
    public:
        Sint32 x1;
        Sint32 y1;
        Sint32 x2;
        Sint32 y2;

        Line();
        Line(const Point p1, const Point p2);
        Line(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2);
        Point       first() const;
        Point       second() const;
        Line&       set(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2);
        Line&       add(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2);
        Line&       sub(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2);
        Line&       mul(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2);
        Line&       mul(const float x1, const float y1, const float x2, const float y2);
        Line&       div(const Sint32 x1, const Sint32 y1, const Sint32 x2, const Sint32 y2);
        Line&       div(const float x1, const float y1, const float x2, const float y2);
        Line        operator+(const Line& other);
        Line&       operator+=(const Line& other);
        Line        operator-(const Line& other);
        Line&       operator-=(const Line& other);
        Line        operator*(const Line& other);
        Line&       operator*=(const Line& other);
        Line        operator/(const Line& other);
        Line&       operator/=(const Line& other);
        Line        operator*(const Sint32 scalar);
        Line        operator*(const float scalar);
        Line&       operator*=(const Sint32 scalar);
        Line&       operator*=(const float scalar);
        Line        operator/(const Sint32 scalar);
        Line        operator/(const float scalar);
        Line&       operator/=(const Sint32 scalar);
        Line&       operator/=(const float scalar);
        friend bool operator==(const Line& first, const Line& second);
        friend bool operator!=(const Line& first, const Line& second);
        friend bool operator<(const Line& first, const Line& second);
        friend bool operator<=(const Line& first, const Line& second);
        friend bool operator>(const Line& first, const Line& second);
        friend bool operator>=(const Line& first, const Line& second);
    };

}  // namespace cymath
}  // namespace Cyanide

#endif  // CYANIDE_LINE_HPP
