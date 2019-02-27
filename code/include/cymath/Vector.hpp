#ifndef CYANIDE_VECTOR_HPP
#define CYANIDE_VECTOR_HPP

namespace Cyanide
{
namespace cymath
{

    class Vector
    {
    public:
        float x;
        float y;
        float z;

        Vector();
        Vector(float x, float y, float z = 0);
        Vector&      set(float x, float y, float z = 0);
        Vector&      add(float x, float y, float z = 0);
        Vector&      sub(float x, float y, float z = 0);
        Vector&      mul(float x, float y, float z = 1);
        Vector&      div(float x, float y, float z = 1);
        Vector       operator+(const Vector& other);
        Vector&      operator+=(const Vector& other);
        Vector       operator-(const Vector& other);
        Vector&      operator-=(const Vector& other);
        Vector       operator*(const Vector& other);
        Vector&      operator*=(const Vector& other);
        Vector       operator/(const Vector& other);
        Vector&      operator/=(const Vector& other);
        Vector       operator*(float scalar);
        Vector&      operator*=(float scalar);
        Vector       operator/(float scalar);
        Vector&      operator/=(float scalar);
        friend bool operator==(const Vector& first, const Vector& second);
        friend bool operator!=(const Vector& first, const Vector& second);
        friend bool operator<(const Vector& first, const Vector& second);
        friend bool operator<=(const Vector& first, const Vector& second);
        friend bool operator>(const Vector& first, const Vector& second);
        friend bool operator>=(const Vector& first, const Vector& second);
    };

}  // namespace
}  // namespace Cyanide

#endif  // CYANIDE_VECTOR_HPP
