
#include <cygui/styles/ObjectStyle.hpp>

namespace Cyanide
{
namespace cygui
{

    cymath::Point cygui::ObjectStyle::getPosition() const
    {
        return position;
    }

    ObjectStyle &ObjectStyle::setPosition(cymath::Point p)
    {
        position = p;
        return *this;
    }

    cymath::Rectangle cygui::ObjectStyle::getSize() const
    {
        return size;
    }

    ObjectStyle &ObjectStyle::setSize(cymath::Rectangle r)
    {
        size = r;
        return *this;
    }

    cymath::Point cygui::ObjectStyle::getContentPosition() const
    {
        return content_position;
    }

    ObjectStyle &ObjectStyle::setContentPosition(cymath::Point p)
    {
        content_position = p;
        return *this;
    }

    cymath::Rectangle cygui::ObjectStyle::getContentSize() const
    {
        return content_size;
    }

    ObjectStyle &ObjectStyle::setContentSize(cymath::Rectangle r)
    {
        content_size = r;
        return *this;
    }

    cymath::Point cygui::ObjectStyle::getDecorationPosition() const
    {
        return decoration_position;
    }

    ObjectStyle &ObjectStyle::setDecorationPosition(cymath::Point p)
    {
        decoration_position = p;
        return *this;
    }

    cymath::Rectangle cygui::ObjectStyle::getDecorationSize() const
    {
        return decoration_size;
    }

    ObjectStyle &ObjectStyle::setDecorationSize(cymath::Rectangle r)
    {
        decoration_size = r;
        return *this;
    }

}  // namespace cygui
}  // namespace Cyanide