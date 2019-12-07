#ifndef CYANIDE_IKEYBOARD_HPP
#define CYANIDE_IKEYBOARD_HPP

namespace cyanide::cyinput
{

    class IKeyboard
    {
    protected:
        IKeyboard() = default;

    public:
        virtual ~IKeyboard() = default;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_IKEYBOARD_HPP
