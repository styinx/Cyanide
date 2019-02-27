#ifndef CYANIDE_SPACE_HPP
#define CYANIDE_SPACE_HPP

#include "cystd/stdPrototypes.hpp"

namespace Cyanide
{
namespace cymath
{

    class Space
    {
    public:
        Sint32 top;
        Sint32 right;
        Sint32 bottom;
        Sint32 left;

        Space();
        Space(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left);
        Space& set(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left);
        Space& add(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left);
        Space& sub(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left);
        Space& mul(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left);
        Space& mul(float top, float right, float bottom, float left);
        Space& div(Sint32 top, Sint32 right, Sint32 bottom, Sint32 left);
        Space& div(float top, float right, float bottom, float left);
        Space  operator+(const Space& other);
        Space& operator+=(const Space& other);
        Space  operator-(const Space& other);
        Space& operator-=(const Space& other);
        Space  operator*(const Space& other);
        Space& operator*=(const Space& other);
        Space  operator/(const Space& other);
        Space& operator/=(const Space& other);
        Space  operator*(Sint32 scalar);
        Space  operator*(float scalar);
        Space& operator*=(Sint32 scalar);
        Space& operator*=(float scalar);
        Space  operator/(Sint32 scalar);
        Space  operator/(float scalar);
        Space& operator/=(Sint32 scalar);
        Space& operator/=(float scalar);
    };

}  // namespace cymath
}  // namespace Cyanide

#endif  // CYANIDE_SPACE_HPP
