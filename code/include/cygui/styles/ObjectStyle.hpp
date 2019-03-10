#ifndef CYANIDE_OBJECTSTYLE_HPP
#define CYANIDE_OBJECTSTYLE_HPP

#include "cystd/stdPrototypes.hpp"

#include "cymath/Point.hpp"
#include "cymath/Size.hpp"

namespace Cyanide
{
namespace cygui
{

    using SomeValue = Uint8;

    class ObjectStyle
    {
    private:
        cymath::Point m_position;
        cymath::Size  m_size;
        cymath::Point m_content_position;
        cymath::Size  m_content_size;
        cymath::Point m_decoration_position;
        cymath::Size  m_decoration_size;

    public:

        ObjectStyle() = default;
        ObjectStyle(const ObjectStyle& object_style) = default;
        ObjectStyle(ObjectStyle&& object_style) noexcept = default;
        ObjectStyle& operator=(const ObjectStyle& object_style) = default;
        ObjectStyle& operator=(ObjectStyle&& object_style) noexcept = default;
        virtual ~ObjectStyle() = default;

        virtual cymath::Point getPosition() const;
        virtual ObjectStyle&  setPosition(const cymath::Point position);
        virtual cymath::Size  getSize() const;
        virtual ObjectStyle&  setSize(const cymath::Size size);
        virtual cymath::Point getContentPosition() const;
        virtual ObjectStyle&  setContentPosition(const cymath::Point position);
        virtual cymath::Size  getContentSize() const;
        virtual ObjectStyle&  setContentSize(const cymath::Size size);
        virtual cymath::Point getDecorationPosition() const;
        virtual ObjectStyle&  setDecorationPosition(const cymath::Point position);
        virtual cymath::Size  getDecorationSize() const;
        virtual ObjectStyle&  setDecorationSize(const cymath::Size size);
    };

}  // namespace cygui
}  // namespace Cyanide

#endif  // CYANIDE_OBJECTSTYLE_HPP
