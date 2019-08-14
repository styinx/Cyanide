#ifndef CYANIDE_IRENDERER_HPP
#define CYANIDE_IRENDERER_HPP

#include "cymath/Line.hpp"
#include "cymath/Point.hpp"
#include "cymath/Rectangle.hpp"
#include "cyvideo/ITexture.hpp"
#include "cyvideo/color/RGBAColor.hpp"

namespace cyanide::cyvideo
{

    class IRenderer
    {
    private:
    public:
        virtual ~IRenderer() = default;

        virtual void clear()                                      = 0;
        virtual void show()                                       = 0;
        virtual void setDrawColor(RGBAColor color)                = 0;
        virtual void drawText(const String& string)               = 0;
        virtual void drawPoint(const cymath::Point& p)            = 0;
        virtual void drawLine(const cymath::Line& l)              = 0;
        virtual void
                     drawTriangle(const cymath::Point& p1, const cymath::Point& p2, const cymath::Point& p3) = 0;
        virtual void drawRectangle(const cymath::Rectangle& r)       = 0;
        virtual void drawFilledRectangle(const cymath::Rectangle& r) = 0;
        virtual void drawPolygon(const Vector<cymath::Point>& p)     = 0;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_IRENDERER_HPP
