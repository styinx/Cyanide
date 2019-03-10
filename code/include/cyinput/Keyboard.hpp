#ifndef CYANIDE_KEYBOARD_HPP
#define CYANIDE_KEYBOARD_HPP

namespace Cyanide
{
namespace cyinput
{

    class Keyboard
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
}  // namespace Cyanide

#endif  // CYANIDE_KEYBOARD_HPP
