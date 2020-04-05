#ifndef CYANIDE_VECTOR_HPP
#define CYANIDE_VECTOR_HPP

namespace cyanide::cymath
{

    class Vector
    {
    public:
        float x = 0;
        float y = 0;
        float z = 0;

        Vector();
        Vector(const float x, const float y, const float z = 0);
        Vector(const Vector& other)     = default;
        Vector(Vector&& other) noexcept = default;
        Vector& operator=(const Vector& other) = default;
        Vector& operator=(Vector&& other) noexcept = default;
        virtual ~Vector()                          = default;
        explicit    operator bool() const;
        bool        empty() const;
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

}  // namespace cyanide::cymath

#endif  // CYANIDE_VECTOR_HPP
