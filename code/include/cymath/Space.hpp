#ifndef CYANIDE_SPACE_HPP
#define CYANIDE_SPACE_HPP

#include "cystd/Types.hpp"

namespace cyanide::cymath
{

    class Space
    {
    public:
        Sint32 top    = 0;
        Sint32 right  = 0;
        Sint32 bottom = 0;
        Sint32 left   = 0;

        Space();
        Space(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left);
        Space(const Space& other)     = default;
        Space(Space&& other) noexcept = default;
        Space& operator=(const Space& other) = default;
        Space& operator=(Space&& other) noexcept = default;
        virtual ~Space()                         = default;
        explicit operator bool() const;
        bool     empty() const;
        Space&   set(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left);
        Space&   add(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left);
        Space&   sub(const Sint32 top, const Sint32 right, const Sint32 bottom, const Sint32 left);
        Space&   mul(const float top, const float right, const float bottom, const float left);
        Space&   div(const float top, const float right, const float bottom, const float left);
        Space    operator+(const Space& other);
        Space&   operator+=(const Space& other);
        Space    operator-(const Space& other);
        Space&   operator-=(const Space& other);
        Space    operator*(const Space& other);
        Space&   operator*=(const Space& other);
        Space    operator/(const Space& other);
        Space&   operator/=(const Space& other);
        Space    operator*(const float scalar);
        Space&   operator*=(const float scalar);
        Space    operator/(const float scalar);
        Space&   operator/=(const float scalar);
    };

}  // namespace cyanide::cymath

#endif  // CYANIDE_SPACE_HPP
