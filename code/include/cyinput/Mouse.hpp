#ifndef CYANIDE_MOUSE_HPP
#define CYANIDE_MOUSE_HPP

namespace cyanide
{
namespace cyinput
{

    class Mouse
    {
    private:
    public:
        Mouse() = default;
        ~Mouse() = default;
        Mouse(const Mouse& mouse) = default;
        Mouse(Mouse&& mouse) noexcept = default;
        Mouse& operator=(const Mouse& mouse) = default;
        Mouse& operator=(Mouse&& mouse) noexcept = default;
    };

}  // namespace cyinput
}  // namespace cyanide

#endif  // CYANIDE_MOUSE_HPP
