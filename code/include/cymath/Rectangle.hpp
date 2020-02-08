#ifndef CYANIDE_RECTANGLE_HPP
#define CYANIDE_RECTANGLE_HPP

#include "cymath/Point.hpp"
#include "cymath/Size.hpp"
#include "cystd/Types.hpp"

namespace cyanide::cymath
{

    class Rectangle
    {
    public:
        Sint32 x;
        Sint32 y;
        Sint32 w;
        Sint32 h;

        Rectangle();
        Rectangle(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h);
        Rectangle(const Point& p, const Size& s);
        Rectangle(const Rectangle& other)     = default;
        Rectangle(Rectangle&& other) noexcept = default;
        Rectangle&  operator=(const Rectangle& other) = default;
        Rectangle&  operator=(Rectangle&& other) noexcept = default;
        virtual ~Rectangle()                              = default;
        Point       topLeft() const;
        Point       topRight() const;
        Point       bottomLeft() const;
        Point       bottomRight() const;
        Point       center() const;
        Point       getPosition() const;
        Rectangle&  setPosition(const Point& p);
        Size        getSize() const;
        Rectangle&  setSize(const Size& s);
        Rectangle&  set(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h);
        Rectangle&  add(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h);
        Rectangle&  sub(const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h);
        Rectangle&  mul(const float x, const float y, const float w, const float h);
        Rectangle&  div(const float x, const float y, const float w, const float h);
        Rectangle   operator+(const Rectangle& other);
        Rectangle&  operator+=(const Rectangle& other);
        Rectangle   operator-(const Rectangle& other);
        Rectangle&  operator-=(const Rectangle& other);
        Rectangle   operator*(const Rectangle& other);
        Rectangle&  operator*=(const Rectangle& other);
        Rectangle   operator/(const Rectangle& other);
        Rectangle&  operator/=(const Rectangle& other);
        Rectangle   operator*(const float scalar);
        Rectangle&  operator*=(const float scalar);
        Rectangle   operator/(const float scalar);
        Rectangle&  operator/=(const float scalar);

        /**
         * @brief   Reduces the available space of the rectangle with the positive amount of
         *          the space parameter. A negative space gets added to the available space.
         * @param space
         * @return Copy of the rectangle with the new space
         */
        Rectangle   operator+(const Space& space);
        Rectangle&  operator+=(const Space& space);

        /**
         * @brief   Adds positive space to the available space of the rectangle. Negative
         *          space reduces the the available space of the rectangle.
         * @param space
         * @return Copy of the rectangle with the new space.
         */
        Rectangle   operator-(const Space& space);
        Rectangle&  operator-=(const Space& space);

        /**
         * @brief   Compares two rectangles on size. The maximum rectangle is the one
         *          that is >= than the other.
         * @return  Returns the bigger rectangle.
         */
        static Rectangle& max(Rectangle& first, Rectangle& second);

        /**
         * @brief   Compares two rectangles on size. The minmum rectangle is the one
         *          that is <= than the other.
         * @return  Returns the smaller rectangle.
         */
        static Rectangle& min(Rectangle& first, Rectangle& second);

        friend bool operator==(const Rectangle& first, const Rectangle& second);
        friend bool operator!=(const Rectangle& first, const Rectangle& second);

        /**
         * @brief   Compares two rectangles on size. A rectangle is < than another
         *          when its size is smaller.
         */
        friend bool operator<(const Rectangle& first, const Rectangle& second);

        /**
         * @brief   Compares two rectangles on size. A rectangle is <= than another
         *          when its size is smaller or equal.
         */
        friend bool operator<=(const Rectangle& first, const Rectangle& second);

        /**
         * @brief   Compares two rectangles on size. A rectangle is > than another
         *          when its size is bigger.
         */
        friend bool operator>(const Rectangle& first, const Rectangle& second);

        /**
         * @brief   Compares two rectangles on size. A rectangle is >= than another
         *          when its size is bigger or equal.
         */
        friend bool operator>=(const Rectangle& first, const Rectangle& second);
    };

}  // namespace cyanide

#endif  // CYANIDE_RECTANGLE_HPP
