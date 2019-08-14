#ifndef CYANIDE_BUTTONSTYLE_HPP
#define CYANIDE_BUTTONSTYLE_HPP

#include "cygui/styles/WidgetStyle.hpp"
#include "cygui/styles/TextWidgetStyle.hpp"

namespace cyanide::cygui
{

    class ButtonStyle
    {
    public:
        ButtonStyle()                                    = default;
        ButtonStyle(const ButtonStyle& widget_style)     = default;
        ButtonStyle(ButtonStyle&& widget_style) noexcept = default;
        ButtonStyle& operator=(const ButtonStyle& widget_style) = default;
        ButtonStyle& operator=(ButtonStyle&& widget_style) noexcept = default;
        virtual ~ButtonStyle()                                      = default;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_BUTTONSTYLE_HPP
