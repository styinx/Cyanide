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

        virtual void          setTitle(const String& title)              = 0;
        virtual const String  getTitle() const                           = 0;
        virtual void          setPosition(const cymath::Point& position) = 0;
        virtual cymath::Point getPosition() const                        = 0;
        virtual void          setSize(const cymath::Size& size)          = 0;
        virtual cymath::Size  getSize() const                            = 0;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_IWINDOW_HPP
