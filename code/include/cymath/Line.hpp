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
        Line(Point p1, Point p2);
        Line(Sint32 x1, Sint32 y1, Sint32 x2, Sint32 y2);
        Point       first() const;
        Point       second() const;
        Line&       set(Sint32 x1, Sint32 y1, Sint32 x2, Sint32 y2);
        Line&       add(Sint32 x1, Sint32 y1, Sint32 x2, Sint32 y2);
        Line&       sub(Sint32 x1, Sint32 y1, Sint32 x2, Sint32 y2);
        Line&       mul(Sint32 x1, Sint32 y1, Sint32 x2, Sint32 y2);
        Line&       mul(float x1, float y1, float x2, float y2);
        Line&       div(Sint32 x1, Sint32 y1, Sint32 x2, Sint32 y2);
        Line&       div(float x1, float y1, float x2, float y2);
        Line        operator+(const Line& other);
        Line&       operator+=(const Line& other);
        Line        operator-(const Line& other);
        Line&       operator-=(const Line& other);
        Line        operator*(const Line& other);
        Line&       operator*=(const Line& other);
        Line        operator/(const Line& other);
        Line&       operator/=(const Line& other);
        Line        operator*(Sint32 scalar);
        Line        operator*(float scalar);
        Line&       operator*=(Sint32 scalar);
        Line&       operator*=(float scalar);
        Line        operator/(Sint32 scalar);
        Line        operator/(float scalar);
        Line&       operator/=(Sint32 scalar);
        Line&       operator/=(float scalar);
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
