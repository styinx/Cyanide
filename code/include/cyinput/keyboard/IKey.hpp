#ifndef CYANIDE_IKEY_HPP
#define CYANIDE_IKEY_HPP

#include "Keys.hpp"
#include "cystd/stdPrototypes.hpp"

namespace cyanide::cyinput
{

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
