#ifndef CYANIDE_BOXSTYLE_HPP
#define CYANIDE_BOXSTYLE_HPP

#include "cygui/styles/WidgetStyle.hpp"

namespace cyanide::cygui
{

    class BoxStyle
    {
    protected:
        BoxStyle();

    public:
        virtual ~BoxStyle() = default;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_BOXSTYLE_HPP
