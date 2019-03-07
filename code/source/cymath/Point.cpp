#include "cymath/Point.hpp"

#include <cmath>
#include <cymath/Point.hpp>

namespace Cyanide
{
namespace cymath
{

    Point::Point()
        : x(0)
        , y(0)
        , z(0)
    {
    }

    Point::Point(Sint32 x, Sint32 y, Sint32 z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    Point::Point(const Point& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    Point& Point::operator=(const Point& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Point& Point::set(Sint32 x, Sint32 y, Sint32 z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        return *this;
    }

    Point& Point::add(Sint32 x, Sint32 y, Sint32 z)
    {
        this->x += x;
        this->y += y;
        this->z += z;
        return *this;
    }

    Point& Point::add(Point p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }

    Point& Point::sub(Sint32 x, Sint32 y, Sint32 z)
    {
        this->x -= x;
        this->y -= y;
        this->z -= z;
        return *this;
    }

    Point& Point::sub(Point p)
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }

    Point& Point::mul(Sint32 x, Sint32 y, Sint32 z)
    {
        this->x *= x;
        this->y *= y;
        this->z *= z;
        return *this;
    }

    Point& Point::mul(float x, float y, float z)
    {
        this->x = static_cast<Sint32>(std::lround(this->x * x));
        this->y = static_cast<Sint32>(std::lround(this->y * y));
        this->z = static_cast<Sint32>(std::lround(this->z * z));
        return *this;
    }

    Point& Point::div(Sint32 x, Sint32 y, Sint32 z)
    {
        if(x != 0) this->x = static_cast<Sint32>(std::lround(this->x / x));
        if(y != 0) this->y = static_cast<Sint32>(std::lround(this->y / y));
        if(z != 0) this->z = static_cast<Sint32>(std::lround(this->z / z));
        return *this;
    }

    Point& Point::div(float x, float y, float z)
    {
        if(x != 0) this->x = static_cast<Sint32>(std::lround(this->x / x));
        if(y != 0) this->y = static_cast<Sint32>(std::lround(this->y / y));
        if(z != 0) this->z = static_cast<Sint32>(std::lround(this->z / z));
        return *this;
    }

    Point Point::operator+(const Point& other) { return {x + other.x, y + other.y, z + other.z}; }

    Point& Point::operator+=(const Point& other) { return add(other.x, other.y, other.z); }

    Point Point::operator-(const Point& other) { return {x - other.x, y - other.y, z - other.z}; }

    Point& Point::operator-=(const Point& other) { return sub(other.x, other.y, other.z); }

    Point Point::operator*(const Point& other) { return {x * other.x, y * other.y, z * other.z}; }

    Point& Point::operator*=(const Point& other) { return mul(other.x, other.y, other.z); }

    Point Point::operator/(const Point& other)
    {
        Point p = *this;
        return p.div(other.x, other.y, other.z);
    }

    Point& Point::operator/=(const Point& other) { return div(other.x, other.y, other.z); }

    Point Point::operator*(Sint32 scalar) { return {x * scalar, y * scalar, z * scalar}; }

    Point Point::operator*(float scalar)
    {
        Point p = *this;
        return p.mul(scalar, scalar, scalar);
    }

    Point& Point::operator*=(Sint32 scalar) { return mul(scalar, scalar, scalar); }

    Point& Point::operator*=(float scalar) { return mul(scalar, scalar, scalar); }

    Point Point::operator/(Sint32 scalar)
    {
        Point p = *this;
        return p.div(scalar, scalar, scalar);
    }

    Point Point::operator/(float scalar)
    {
        Point p = *this;
        return p.div(scalar, scalar, scalar);
    }

    Point& Point::operator/=(Sint32 scalar) { return div(scalar, scalar, scalar); }

    Point& Point::operator/=(float scalar) { return div(scalar, scalar, scalar); }

    bool operator==(const Point& first, const Point& second)
    {
        return (first.x == second.x && first.y == second.y && first.z == second.z);
    }

    bool operator!=(const Point& first, const Point& second) { return !(first == second); }

    bool operator<(const Point& first, const Point& second)
    {
        return (first.x < second.x) && (first.y < second.y) && (first.z < second.z);
    }

    bool operator<=(const Point& first, const Point& second)
    {
        return (first.x <= second.x) && (first.y <= second.y) && (first.z <= second.z);
    }

    bool operator>(const Point& first, const Point& second)
    {
        return (first.x > second.x) && (first.y > second.y) && (first.z > second.z);
    }

    bool operator>=(const Point& first, const Point& second)
    {
        return (first.x >= second.x) && (first.y >= second.y) && (first.z >= second.z);
    }

}  // namespace cymath
}  // namespace Cyanide