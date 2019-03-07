#ifndef CYANIDE_SIZE_HPP
#define CYANIDE_SIZE_HPP

#include "cystd/stdPrototypes.hpp"

namespace Cyanide
{
namespace cymath
{

    class Size final
    {
    public:
        Sint32 width;
        Sint32 height;

        Size();
        Size(Sint32 width, Sint32 height);
        Size(const Size& other) = default;
        Size(Size&& other) noexcept = default;
        Size&      operator=(const Size& other) = default;
        Size&      operator=(Size&& other) noexcept = default;
        Size& set(Sint32 w, Sint32 h);
        Size& add(Sint32 w, Sint32 h);
        Size& add(Size p);
        Size& sub(Sint32 w, Sint32 h);
        Size& sub(Size p);
        Size& mul(Sint32 w, Sint32 h);
        Size& mul(float w, float h);
        Size& div(Sint32 w, Sint32 h);
        Size& div(float w, float h);
        Size  operator+(const Size& other);
        Size& operator+=(const Size& other);
        Size  operator-(const Size& other);
        Size& operator-=(const Size& other);
        Size  operator*(const Size& other);
        Size& operator*=(const Size& other);
        Size  operator/(const Size& other);
        Size& operator/=(const Size& other);
        Size  operator*(Sint32 scalar);
        Size  operator*(float scalar);
        Size& operator*=(Sint32 scalar);
        Size& operator*=(float scalar);
        Size  operator/(Sint32 scalar);
        Size  operator/(float scalar);
        Size& operator/=(Sint32 scalar);
        Size& operator/=(float scalar);
    };

}  // namespace cymath
}  // namespace Cyanide

#endif  // CYANIDE_SIZE_HPP
