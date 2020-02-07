#ifndef CYANIDE_SPACE_HPP
#define CYANIDE_SPACE_HPP

#include "cystd/Types.hpp"

namespace cyanide::cymath
{

    class Space
    {
    public:
        Sint32 top;
        Sint32 right;
        Sint32 bottom;
        Sint32 left;

        Space();
        Space(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left);
        Space(const Space& other)     = default;
        Space(Space&& other) noexcept = default;
        virtual ~Space()              = default;
        Space& operator=(const Space& other) = default;
        Space& operator=(Space&& other) noexcept = default;
        Space& set(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left);
        Space& add(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left);
        Space& sub(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left);
        Space& mul(const float top, const float right, const float bottom, const float left);
        Space& div(const float top, const float right, const float bottom, const float left);
        Space  operator+(const Space& other);
        Space& operator+=(const Space& other);
        Space  operator-(const Space& other);
        Space& operator-=(const Space& other);
        Space  operator*(const Space& other);
        Space& operator*=(const Space& other);
        Space  operator/(const Space& other);
        Space& operator/=(const Space& other);
        Space  operator*(const float scalar);
        Space& operator*=(const float scalar);
        Space  operator/(const float scalar);
        Space& operator/=(const float scalar);
    };

}  // namespace cyanide::cymath

#endif  // CYANIDE_SPACE_HPP
