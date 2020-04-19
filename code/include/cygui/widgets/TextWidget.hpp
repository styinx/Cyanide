#ifndef CYANIDE_TEXTWIDGET_HPP
#define CYANIDE_TEXTWIDGET_HPP

#include "cygui/styles/TextWidgetStyle.hpp"
#include "cygui/widgets/Widget.hpp"

namespace cyanide::cygui
{
    class TextWidget
        : public Widget
        , public TextWidgetStyle
    {
    private:
        void              initTextTexture();
        cymath::Rectangle calculateTextAlignment();

    protected:
        String m_text;

        TextWidget();
        explicit TextWidget(const String& text);

    public:
        virtual ~TextWidget() = default;

        void   setText(const String& text);
        String getText() const;

        virtual void drawText();

        /*
         * Inherited from Widget
         */
        virtual void draw() override;
    };
}  // namespace cyanide::cygui

#endif  // CYANIDE_TEXTWIDGET_HPP
