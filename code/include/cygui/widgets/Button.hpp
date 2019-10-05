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
        explicit Button(const String& label);
        virtual ~Button() = default;

        /*
         * Inherited from TextWidget
         */
        virtual void draw() override;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_BUTTON_HPP
