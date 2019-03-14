
#include "cygui/styles/ObjectStyle.hpp"

namespace Cyanide
{
namespace cygui
{

    cymath::Point cygui::ObjectStyle::getPosition() const
    {
        return m_position;
    }

    ObjectStyle &ObjectStyle::setPosition(const cymath::Point position)
    {
        m_position = position;
        return *this;
    }

    cymath::Size cygui::ObjectStyle::getSize() const
    {
        return m_size;
    }

    ObjectStyle &ObjectStyle::setSize(const cymath::Size size)
    {
        m_size = size;
        return *this;
    }

    cymath::Point cygui::ObjectStyle::getContentPosition() const
    {
        return m_content_position;
    }

    ObjectStyle &ObjectStyle::setContentPosition(const cymath::Point position)
    {
        m_content_position = position;
        return *this;
    }

    cymath::Size cygui::ObjectStyle::getContentSize() const
    {
        return m_content_size;
    }

    ObjectStyle &ObjectStyle::setContentSize(const cymath::Size size)
    {
        m_content_size = size;
        return *this;
    }

    cymath::Point cygui::ObjectStyle::getDecorationPosition() const
    {
        return m_decoration_position;
    }

    ObjectStyle &ObjectStyle::setDecorationPosition(const cymath::Point position)
    {
        m_decoration_position = position;
        return *this;
    }

    cymath::Size cygui::ObjectStyle::getDecorationSize() const
    {
        return m_decoration_size;
    }

    ObjectStyle &ObjectStyle::setDecorationSize(const cymath::Size size)
    {
        m_decoration_size = size;
        return *this;
    }

}  // namespace cygui
}  // namespace Cyanide