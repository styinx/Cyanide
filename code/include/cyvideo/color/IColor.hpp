#ifndef CYANIDE_ICOLOR_HPP
#define CYANIDE_ICOLOR_HPP

namespace cyanide::cyvideo
{

    template<typename T = Byte>
    class IColor
    {
    public:
        IColor()                        = default;
        IColor(const IColor& color)     = default;
        IColor(IColor&& color) noexcept = default;
        IColor& operator=(const IColor& color) = default;
        IColor& operator=(IColor&& color) noexcept = default;
        virtual ~IColor()                          = default;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_ICOLOR_HPP
