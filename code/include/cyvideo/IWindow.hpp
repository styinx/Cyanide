#ifndef CYANIDE_IWINDOW_HPP
#define CYANIDE_IWINDOW_HPP

#include "cymath/Point.hpp"
#include "cymath/Size.hpp"

namespace cyanide::cyvideo
{

    class IWindow
    {
    public:
        virtual ~IWindow() = default;

        virtual IWindow&      setTitle(const char* title)               = 0;
        virtual const char*   getTitle() const                          = 0;
        virtual IWindow&      setPosition(const cymath::Point position) = 0;
        virtual cymath::Point getPosition() const                       = 0;
        virtual IWindow&      setSize(const cymath::Size size)          = 0;
        virtual cymath::Size  getSize() const                           = 0;
    };

}  // namespace cyanide

#endif  // CYANIDE_IWINDOW_HPP
