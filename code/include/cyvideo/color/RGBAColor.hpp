#ifndef CYANIDE_RGBACOLOR_HPP
#define CYANIDE_RGBACOLOR_HPP

#include "cystd/stdPrototypes.hpp"
#include "IColor.hpp"

namespace cyanide::cyvideo
{

    class RGBAColor : public IColor<Byte>
    {
    public:
        Byte r = 0x00;
        Byte g = 0x00;
        Byte b = 0x00;
        Byte a = 0xff;

        RGBAColor() = default;
        explicit RGBAColor(const Byte& r, const Byte& g, const Byte& b, const Byte& a);
        RGBAColor(const RGBAColor& color)     = default;
        RGBAColor(RGBAColor&& color) noexcept = default;
        RGBAColor& operator=(const RGBAColor& color) = default;
        RGBAColor& operator=(RGBAColor&& color) noexcept = default;
        virtual ~RGBAColor()                             = default;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_RGBACOLOR_HPP
