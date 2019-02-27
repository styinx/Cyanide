#ifndef CYANIDE_ISTYLE_HPP
#define CYANIDE_ISTYLE_HPP

#include "cystd/stdPrototypes.hpp"

#include "cymath/Point.hpp"
#include "cymath/Rectangle.hpp"

namespace Cyanide
{
namespace cygui
{

    using SomeValue = Uint8;

    class ObjectStyle
    {
    private:
        cymath::Point     position;
        cymath::Rectangle size;
        cymath::Point     content_position;
        cymath::Rectangle content_size;
        cymath::Point     decoration_position;
        cymath::Rectangle decoration_size;

    public:
        Map<String, SomeValue> map;

        virtual ~ObjectStyle() = default;

        virtual cymath::Point     getPosition() const;
        virtual ObjectStyle&      setPosition(cymath::Point p);
        virtual cymath::Rectangle getSize() const;
        virtual ObjectStyle&      setSize(cymath::Rectangle r);
        virtual cymath::Point     getContentPosition() const;
        virtual ObjectStyle&      setContentPosition(cymath::Point p);
        virtual cymath::Rectangle getContentSize() const;
        virtual ObjectStyle&      setContentSize(cymath::Rectangle r);
        virtual cymath::Point     getDecorationPosition() const;
        virtual ObjectStyle&      setDecorationPosition(cymath::Point p);
        virtual cymath::Rectangle getDecorationSize() const;
        virtual ObjectStyle&      setDecorationSize(cymath::Rectangle p);
    };

}  // namespace cygui
}  // namespace Cyanide

#endif  // CYANIDE_ISTYLE_HPP
