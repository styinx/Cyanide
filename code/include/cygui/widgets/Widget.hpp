#ifndef CYANIDE_WIDGET_HPP
#define CYANIDE_WIDGET_HPP

#include "cygui/widgets/Object.hpp"
#include "cygui/styles/WidgetStyle.hpp"

namespace cyanide::cygui
{

    class Widget
        : public Object
        , public WidgetStyle
    {
    private:
    public:
        Widget()                         = default;
        Widget(const Widget& widget)     = default;
        Widget(Widget&& widget) noexcept = default;
        Widget& operator=(const Widget& widget) = default;
        Widget& operator=(Widget&& widget) noexcept = default;
        virtual ~Widget()                           = default;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_WIDGET_HPP
