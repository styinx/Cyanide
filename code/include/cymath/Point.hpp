#ifndef CYANIDE_POINT_HPP
#define CYANIDE_POINT_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cymath
{

    class Point final
    {
    public:
        Sint32 x;
        Sint32 y;
        Sint32 z;

        Point();
        Point(const Sint32 x, const Sint32 y, const Sint32 z = 0);
        Point(const Point& other);
        Point(Point&& other) noexcept = default;
        Point&      operator=(const Point& other);
        Point&      operator=(Point&& other) noexcept = default;
        Point&      set(const Sint32 x, const Sint32 y, const Sint32 z = 0);
        Point&      add(const Sint32 x, const Sint32 y, const Sint32 z = 0);
        Point&      add(const Point p);
        Point&      sub(const Sint32 x, const Sint32 y, const Sint32 z = 0);
        Point&      sub(const Point p);
        Point&      mul(const Sint32 x, const Sint32 y, const Sint32 z = 1);
        Point&      mul(const float x, const float y, const float z = 1);
        Point&      div(const Sint32 x, const Sint32 y, const Sint32 z = 1);
        Point&      div(const float x, const float y, const float z = 1);
        Point       operator+(const Point& other);
        Point&      operator+=(const Point& other);
        Point       operator-(const Point& other);
        Point&      operator-=(const Point& other);
        Point       operator*(const Point& other);
        Point&      operator*=(const Point& other);
        Point       operator/(const Point& other);
        Point&      operator/=(const Point& other);
        Point       operator*(const Sint32 scalar);
        Point       operator*(const float scalar);
        Point&      operator*=(const Sint32 scalar);
        Point&      operator*=(const float scalar);
        Point       operator/(const Sint32 scalar);
        Point       operator/(const float scalar);
        Point&      operator/=(const Sint32 scalar);
        Point&      operator/=(float scalar);
        friend bool operator==(const Point& first, const Point& second);
        friend bool operator!=(const Point& first, const Point& second);
        friend bool operator<(const Point& first, const Point& second);
        friend bool operator<=(const Point& first, const Point& second);
        friend bool operator>(const Point& first, const Point& second);
        friend bool operator>=(const Point& first, const Point& second);
    };

}  // namespace cyanide

#endif  // CYANIDE_POINT_HPP
