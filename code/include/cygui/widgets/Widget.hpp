#ifndef CYANIDE_WIDGET_HPP
#define CYANIDE_WIDGET_HPP

#include "cygui/styles/WidgetStyle.hpp"
#include "cygui/widgets/Object.hpp"
#include "cymath/Space.hpp"

namespace cyanide::cygui
{

    class Widget
        : public Object
        , public WidgetStyle
    {
    protected:

    public:
        Widget();
        virtual ~Widget()                           = default;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_WIDGET_HPP
