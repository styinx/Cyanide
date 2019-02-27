#include "cymath/Vector.hpp"

namespace Cyanide
{
namespace cymath
{

    Vector::Vector()
        : x(0)
        , y(0)
        , z(0)
    {
    }

    Vector::Vector(float x, float y, float z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    Vector &Vector::set(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        return *this;
    }

    Vector &Vector::add(float x, float y, float z)
    {
        this->x += x;
        this->y += y;
        this->z += z;
        return *this;
    }

    Vector &Vector::sub(float x, float y, float z)
    {
        this->x -= x;
        this->y -= y;
        this->z -= z;
        return *this;
    }

    Vector &Vector::mul(float x, float y, float z)
    {
        this->x *= x;
        this->y *= y;
        this->z *= z;
        return *this;
    }

    Vector &Vector::div(float x, float y, float z)
    {
        if(x != 0) this->x /= x;
        if(y != 0) this->y /= y;
        if(z != 0) this->z /= z;
        return *this;
    }

    Vector Vector::operator+(const Vector &other)
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector& Vector::operator+=(const Vector &other)
    {
        return this->add(other.x, other.y, other.z);
    }

    Vector Vector::operator-(const Vector &other)
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector& Vector::operator-=(const Vector &other)
    {
        return this->sub(other.x, other.y, other.z);
    }

    Vector Vector::operator*(const Vector &other)
    {
        return {x * other.x, y * other.y, z * other.z};
    }

    Vector& Vector::operator*=(const Vector &other)
    {
        return this->mul(other.x, other.y, other.z);
    }

    Vector Vector::operator/(const Vector &other)
    {
        Vector p = *this;
        return p.div(other.x, other.y, other.z);
    }

    Vector& Vector::operator/=(const Vector &other)
    {
        return this->div(other.x, other.y, other.z);
    }

    Vector Vector::operator*(float scalar)
    {
        return {x * scalar, y * scalar, z * scalar};
    }

    Vector& Vector::operator*=(float scalar)
    {
        return this->mul(scalar, scalar, scalar);
    }

    Vector Vector::operator/(float scalar)
    {
        Vector p = *this;
        return p.div(scalar, scalar, scalar);
    }

    Vector& Vector::operator/=(float scalar)
    {
        return this->div(scalar, scalar, scalar);
    }

    bool operator==(const Vector &first, const Vector &second)
    {
        return (first.x == second.x && first.y == second.y && first.z == second.z);
    }

    bool operator!=(const Vector &first, const Vector &second)
    {
        return !(first == second);
    }

    bool operator<(const Vector &first, const Vector &second)
    {
        return (first.x < second.x) && (first.y < second.y) && (first.z < second.z);
    }

    bool operator<=(const Vector &first, const Vector &second)
    {
        return (first.x <= second.x) && (first.y <= second.y) && (first.z <= second.z);
    }

    bool operator>(const Vector &first, const Vector &second)
    {
        return (first.x > second.x) && (first.y > second.y) && (first.z > second.z);
    }

    bool operator>=(const Vector &first, const Vector &second)
    {
        return (first.x >= second.x) && (first.y >= second.y) && (first.z >= second.z);
    }

}  // namespace cymath
}  // namespace Cyanide