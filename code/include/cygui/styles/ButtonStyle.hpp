#ifndef CYANIDE_BUTTONSTYLE_HPP
#define CYANIDE_BUTTONSTYLE_HPP

#include "cygui/styles/TextWidgetStyle.hpp"
#include "cygui/styles/WidgetStyle.hpp"

namespace cyanide::cygui
{

    class ButtonStyle
    {
    protected:
        ButtonStyle();

    public:
        virtual ~ButtonStyle() = default;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_BUTTONSTYLE_HPP
