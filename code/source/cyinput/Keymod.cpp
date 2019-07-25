#include "cyinput/Keymod.hpp"

namespace cyanide
{
namespace cyinput
{

    Keymod::Keymod(const KEYMOD& keymod)
        : code(0)//TODO
    {

    }

    Keymod::Keymod(const IKey& key)
        : code(key.getCode())
    {

    }

    Keymod::Keymod(const KEY& key)
        : code(static_cast<Uint32>(key))
    {

    }

    Uint32 Keymod::getCode() const
    {
        return code;
    }

    IKey& Keymod::setCode(const Uint32 key)
    {
        code = key;
        return *this;
    }

    IKey& Keymod::setCode(const KEY key)
    {
        code = static_cast<Uint32>(key);
        return *this;
    }

    IKey& Keymod::setCode(const IKey& key)
    {
        code = key.getCode();
        return *this;
    }

}  // namespace cyinput
}  // namespace cyanide