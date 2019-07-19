#ifndef CYANIDE_BUTTON_HPP
#define CYANIDE_BUTTON_HPP

#include "cygui/styles/ButtonStyle.hpp"
#include "cygui/widgets/Widget.hpp"

namespace cyanide::cygui
{

    class Button
        : public Widget
        , public ButtonStyle
    {
    private:
        String m_text;

    public:
        Button()                               = default;
        explicit Button(const String text);
        Button(const Button& widget_style)     = default;
        Button(Button&& widget_style) noexcept = default;
        Button& operator=(const Button& widget_style) = default;
        Button& operator=(Button&& widget_style) noexcept = default;
        virtual ~Button()                                 = default;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_BUTTON_HPP
