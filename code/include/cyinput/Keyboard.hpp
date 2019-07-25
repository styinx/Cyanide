#ifndef CYANIDE_KEYBOARD_HPP
#define CYANIDE_KEYBOARD_HPP

namespace cyanide
{
namespace cyinput
{

    class Keyboard final
    {
    private:
    public:
        Keyboard() = default;
        ~Keyboard() = default;
        Keyboard(const Keyboard& keyboard) = default;
        Keyboard(Keyboard&& keyboard) noexcept = default;
        Keyboard& operator=(const Keyboard& keyboard) = default;
        Keyboard& operator=(Keyboard&& keyboard) noexcept = default;
    };

}  // namespace cyinput
}  // namespace cyanide

#endif  // CYANIDE_KEYBOARD_HPP
