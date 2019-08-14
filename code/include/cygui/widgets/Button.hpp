#ifndef CYANIDE_BUTTON_HPP
#define CYANIDE_BUTTON_HPP

#include "cygui/styles/ButtonStyle.hpp"
#include "cygui/widgets/TextWidget.hpp"

namespace cyanide::cygui
{

    class Button
        : public TextWidget
        , public ButtonStyle
    {
    public:
        Button() = delete;
        explicit Button(const String& text);
        Button(const Button& button)     = default;
        Button(Button&& button) noexcept = default;
        Button& operator=(const Button& button) = default;
        Button& operator=(Button&& button) noexcept = default;
        virtual ~Button()                           = default;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_BUTTON_HPP
