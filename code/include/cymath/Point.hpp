#ifndef CYANIDE_POINT_HPP
#define CYANIDE_POINT_HPP

#include "cystd/Types.hpp"

namespace cyanide::cymath
{

    class Point final
    {
    public:
        Sint32 x = 0;
        Sint32 y = 0;
        Sint32 z = 0;

        Point();
        Point(const Sint32 x, const Sint32 y, const Sint32 z = 0);
        Point(const Point& other);
        Point(Point&& other) noexcept = default;
        Point& operator=(const Point& other) = default;
        Point& operator=(Point&& other) noexcept = default;
        virtual ~Point()                         = default;
        explicit    operator bool() const;
        bool        empty() const;
        Point&      set(const Sint32 x, const Sint32 y, const Sint32 z = 0);
        Point&      add(const Sint32 x, const Sint32 y, const Sint32 z = 0);
        Point&      sub(const Sint32 x, const Sint32 y, const Sint32 z = 0);
        Point&      mul(const float x, const float y, const float z = 1);
        Point&      div(const float x, const float y, const float z = 1);
        Point       operator+(const Point& other);
        Point&      operator+=(const Point& other);
        Point       operator-(const Point& other);
        Point&      operator-=(const Point& other);
        Point       operator*(const Point& other);
        Point&      operator*=(const Point& other);
        Point       operator/(const Point& other);
        Point&      operator/=(const Point& other);
        Point       operator*(const float scalar);
        Point&      operator*=(const float scalar);
        Point       operator/(const float scalar);
        Point&      operator/=(float scalar);
        friend bool operator==(const Point& first, const Point& second);
        friend bool operator!=(const Point& first, const Point& second);
        friend bool operator<(const Point& first, const Point& second);
        friend bool operator<=(const Point& first, const Point& second);
        friend bool operator>(const Point& first, const Point& second);
        friend bool operator>=(const Point& first, const Point& second);
    };

}  // namespace cyanide::cymath

#endif  // CYANIDE_POINT_HPP
