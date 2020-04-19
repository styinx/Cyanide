#ifndef CYANIDE_SIZE_HPP
#define CYANIDE_SIZE_HPP

#include "cymath/Space.hpp"
#include "cystd/Types.hpp"

namespace cyanide::cymath
{

    class Size final
    {
    public:
        Sint32 width  = 0;
        Sint32 height = 0;

        Size();
        Size(const Sint32 width, const Sint32 height);
        Size(const Size& other)     = default;
        Size(Size&& other) noexcept = default;
        Size& operator=(const Size& other) = default;
        Size& operator=(Size&& other) noexcept = default;
        virtual ~Size()                        = default;
        explicit operator bool() const;
        bool     empty() const;
        Size&    set(const Sint32 w, const Sint32 h);
        Size&    add(const Sint32 w, const Sint32 h);
        Size&    sub(const Sint32 w, const Sint32 h);
        Size&    mul(const float w, const float h);
        Size&    div(const float w, const float h);
        Size     operator+(const Size& other) const;
        Size&    operator+=(const Size& other);
        Size     operator-(const Size& other) const;
        Size&    operator-=(const Size& other);
        Size     operator*(const Size& other) const;
        Size&    operator*=(const Size& other);
        Size     operator/(const Size& other) const;
        Size&    operator/=(const Size& other);
        Size     operator*(const float scalar) const;
        Size&    operator*=(const float scalar);
        Size     operator/(const float scalar) const;
        Size&    operator/=(const float scalar);

        Size  operator+(const Space& space) const;
        Size& operator+=(const Space& space);
        Size  operator-(const Space& space) const;
        Size& operator-=(const Space& space);

        static Size& max(Size& first, Size& second);
        static Size& min(Size& first, Size& second);

        friend bool operator==(const Size& first, const Size& second);
        friend bool operator!=(const Size& first, const Size& second);
        friend bool operator<(const Size& first, const Size& second);
        friend bool operator<=(const Size& first, const Size& second);
        friend bool operator>(const Size& first, const Size& second);
        friend bool operator>=(const Size& first, const Size& second);
    };

}  // namespace cyanide::cymath

#endif  // CYANIDE_SIZE_HPP
