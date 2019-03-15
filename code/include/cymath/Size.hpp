#ifndef CYANIDE_SIZE_HPP
#define CYANIDE_SIZE_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide
{
namespace cymath
{

    class Size final
    {
    public:
        Sint32 width;
        Sint32 height;

        Size();
        Size(const Sint32 width, const Sint32 height);
        Size(const Size& other)     = default;
        Size(Size&& other) noexcept = default;
        Size& operator=(const Size& other) = default;
        Size& operator=(Size&& other) noexcept = default;
        Size& set(const Sint32 w, const Sint32 h);
        Size& add(const Sint32 w, const Sint32 h);
        Size& add(const Size p);
        Size& sub(const Sint32 w, const Sint32 h);
        Size& sub(const Size p);
        Size& mul(const Sint32 w, const Sint32 h);
        Size& mul(const float w, const float h);
        Size& div(const Sint32 w, const Sint32 h);
        Size& div(const float w, const float h);
        Size  operator+(const Size& other);
        Size& operator+=(const Size& other);
        Size  operator-(const Size& other);
        Size& operator-=(const Size& other);
        Size  operator*(const Size& other);
        Size& operator*=(const Size& other);
        Size  operator/(const Size& other);
        Size& operator/=(const Size& other);
        Size  operator*(const Sint32 scalar);
        Size  operator*(const float scalar);
        Size& operator*=(const Sint32 scalar);
        Size& operator*=(const float scalar);
        Size  operator/(const Sint32 scalar);
        Size  operator/(const float scalar);
        Size& operator/=(const Sint32 scalar);
        Size& operator/=(const float scalar);
    };

}  // namespace cymath
}  // namespace cyanide

#endif  // CYANIDE_SIZE_HPP
