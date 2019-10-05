#ifndef CYANIDE_HBOX_HPP
#define CYANIDE_HBOX_HPP

#include "cygui/layout/Box.hpp"

namespace cyanide::cygui
{

    class HBox final : public Box
    {
    public:
        HBox();
        HBox(const HBox& box)     = default;
        HBox(HBox&& box) noexcept = default;
        HBox& operator=(const HBox& box) = default;
        HBox& operator=(HBox&& box) noexcept = default;
        virtual ~HBox()                       = default;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_HBOX_HPP
