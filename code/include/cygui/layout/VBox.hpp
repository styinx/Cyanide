#ifndef CYANIDE_VBOX_HPP
#define CYANIDE_VBOX_HPP

#include "cygui/layout/Box.hpp"

namespace cyanide::cygui
{

    class VBox final : public Box
    {
    public:
        VBox();
        VBox(const VBox& box)     = default;
        VBox(VBox&& box) noexcept = default;
        VBox& operator=(const VBox& box) = default;
        VBox& operator=(VBox&& box) noexcept = default;
        virtual ~VBox()                       = default;
    };

}  // namespace cyanide::cygui

#endif //CYANIDE_VBOX_HPP
