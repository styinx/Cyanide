#include "cyinput/keyboard/Keymod.hpp"

namespace cyanide::cyinput
{

    Keymod::Keymod(const IKey& key)
        : m_key_mod(key.getCode())
    {

    }

}  // namespace cyanide
