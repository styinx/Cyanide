#ifndef CYANIDE_WIDGETSTYLE_HPP
#define CYANIDE_WIDGETSTYLE_HPP

#include "cygui/styles/ObjectStyle.hpp"
#include "cymath/Space.hpp"

namespace cyanide::cygui
{
    class WidgetStyle : public virtual ObjectStyle
    {
    protected:
        cymath::Space m_margin;
        cymath::Space m_padding;
        cymath::Space m_border;

        WidgetStyle();

    public:
        virtual ~WidgetStyle() = default;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_WIDGETSTYLE_HPP
