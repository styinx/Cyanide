#ifndef CYANIDE_WIDGETSTYLE_HPP
#define CYANIDE_WIDGETSTYLE_HPP

#include "ObjectStyle.hpp"

namespace cyanide
{
namespace cygui
{
    class WidgetStyle : public ObjectStyle
    {
    private:

    public:
        WidgetStyle() = default;
        WidgetStyle(const WidgetStyle& widget_style) = default;
        WidgetStyle(WidgetStyle&& widget_style) noexcept = default;
        WidgetStyle& operator=(const WidgetStyle& widget_style) = default;
        WidgetStyle& operator=(WidgetStyle&& widget_style) noexcept = default;
        virtual ~WidgetStyle() = default;
    };

}  // namespace cygui
}  // namespace cyanide

#endif  // CYANIDE_WIDGETSTYLE_HPP
