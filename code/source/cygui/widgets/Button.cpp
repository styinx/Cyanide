#include "cygui/widgets/Button.hpp"

namespace cyanide::cygui
{

    Button::Button(const String& label)
        : TextWidget(label)
    {
    }

    void Button::draw()
    {
        TextWidget::draw();
    }

}  // namespace cyanide::cygui
