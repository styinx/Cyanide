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
    protected:
        String m_text;

        TextWidget();
        explicit TextWidget(const String& text);

    public:
        void   setText(const String& text);
        String getText() const;
    };
}  // namespace cyanide::cygui

#endif  // CYANIDE_TEXTWIDGET_HPP
