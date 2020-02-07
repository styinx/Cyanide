#ifndef CYANIDE_VECTOR_HPP
#define CYANIDE_VECTOR_HPP

namespace cyanide::cymath
{

    class Vector
    {
    public:
        float x;
        float y;
        float z;

        Vector();
        Vector(const float x, const float y, const float z = 0);
        Vector(const Vector& other)     = default;
        Vector(Vector&& other) noexcept = default;
        virtual ~Vector()               = default;
        Vector&     operator=(const Vector& other) = default;
        Vector&     operator=(Vector&& other) noexcept = default;
        Vector&     set(const float x, const float y, const float z = 0);
        Vector&     add(const float x, const float y, const float z = 0);
        Vector&     sub(const float x, const float y, const float z = 0);
        Vector&     mul(const float x, const float y, const float z = 1);
        Vector&     div(const float x, const float y, const float z = 1);
        Vector      operator+(const Vector& other);
        Vector&     operator+=(const Vector& other);
        Vector      operator-(const Vector& other);
        Vector&     operator-=(const Vector& other);
        Vector      operator*(const Vector& other);
        Vector&     operator*=(const Vector& other);
        Vector      operator/(const Vector& other);
        Vector&     operator/=(const Vector& other);
        Vector      operator*(const float scalar);
        Vector&     operator*=(const float scalar);
        Vector      operator/(const float scalar);
        Vector&     operator/=(const float scalar);
        friend bool operator==(const Vector& first, const Vector& second);
        friend bool operator!=(const Vector& first, const Vector& second);
        friend bool operator<(const Vector& first, const Vector& second);
        friend bool operator<=(const Vector& first, const Vector& second);
        friend bool operator>(const Vector& first, const Vector& second);
        friend bool operator>=(const Vector& first, const Vector& second);
    };

}  // namespace cyanide

#endif  // CYANIDE_VECTOR_HPP
