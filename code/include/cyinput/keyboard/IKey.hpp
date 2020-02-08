#ifndef CYANIDE_IKEY_HPP
#define CYANIDE_IKEY_HPP

#include "Keys.hpp"
#include "cystd/Types.hpp"

namespace cyanide::cyinput
{
    enum class KEY_STATE : Byte
    {
        NONE     = 0x00,
        RELEASED = 0x01,
        DOWN     = 0x02,
        PRESSED  = 0x04
    };
    using KeyCode = Uint16;
    using KeyMod = Uint16;

    class IKey
    {
    public:
        virtual ~IKey() = default;

        virtual KeyCode getCode() const            = 0;
        virtual void    setCode(const KeyCode key) = 0;
    };

    using IKeySPtr = SharedPtr<IKey>;

}  // namespace cyanide::cyinput

#endif  // CYANIDE_IKEY_HPP
