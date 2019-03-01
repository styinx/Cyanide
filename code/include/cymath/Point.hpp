#ifndef CYANIDE_POINT_HPP
#define CYANIDE_POINT_HPP

#include "cystd/stdPrototypes.hpp"

namespace Cyanide
{
namespace cymath
{

    class Point
    {
    public:
        Sint32 x;
        Sint32 y;
        Sint32 z;

        Point();
        Point(Sint32 x, Sint32 y, Sint32 z = 0);
        Point&      set(Sint32 x, Sint32 y, Sint32 z = 0);
        Point&      add(Sint32 x, Sint32 y, Sint32 z = 0);
        Point&      add(Point p);
        Point&      sub(Sint32 x, Sint32 y, Sint32 z = 0);
        Point&      sub(Point p);
        Point&      mul(Sint32 x, Sint32 y, Sint32 z = 1);
        Point&      mul(float x, float y, float z = 1);
        Point&      div(Sint32 x, Sint32 y, Sint32 z = 1);
        Point&      div(float x, float y, float z = 1);
        Point       operator+(const Point& other);
        Point&      operator+=(const Point& other);
        Point       operator-(const Point& other);
        Point&      operator-=(const Point& other);
        Point       operator*(const Point& other);
        Point&      operator*=(const Point& other);
        Point       operator/(const Point& other);
        Point&      operator/=(const Point& other);
        Point       operator*(Sint32 scalar);
        Point       operator*(float scalar);
        Point&      operator*=(Sint32 scalar);
        Point&      operator*=(float scalar);
        Point       operator/(Sint32 scalar);
        Point       operator/(float scalar);
        Point&      operator/=(Sint32 scalar);
        Point&      operator/=(float scalar);
        friend bool operator==(const Point& first, const Point& second);
        friend bool operator!=(const Point& first, const Point& second);
        friend bool operator<(const Point& first, const Point& second);
        friend bool operator<=(const Point& first, const Point& second);
        friend bool operator>(const Point& first, const Point& second);
        friend bool operator>=(const Point& first, const Point& second);
    };

}  // namespace cymath
}  // namespace Cyanide

#endif  // CYANIDE_POINT_HPP
