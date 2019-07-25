
#include <cyinput/KeyCombination.hpp>

#include "cyinput/KeyCombination.hpp"

namespace cyanide
{
namespace cyinput
{

    KeyCombination::KeyCombination(const IKey& key)
    {

    }

    KeyCombination KeyCombination::operator|(KeyCombination& key_combination)
    {
        return KeyCombination();
    }

    KeyCombination& KeyCombination::operator|=(KeyCombination& key_combination)
    {
        return *this;
    }

    KeyCombination KeyCombination::operator|(IKey& key)
    {
        return KeyCombination();
    }

    KeyCombination& KeyCombination::operator|=(IKey& key)
    {
        return *this;
    }

    KeyCombination KeyCombination::operator&(KeyCombination& key_combination)
    {
        return KeyCombination();
    }

    KeyCombination& KeyCombination::operator&=(KeyCombination& key_combination)
    {
        return *this;
    }

    KeyCombination KeyCombination::operator&(IKey& key)
    {
        return KeyCombination();
    }

    KeyCombination& KeyCombination::operator&=(IKey& key)
    {
        return *this;
    }

    KeyCombination::operator bool() const
    {
        return false;
    }

}  // namespace cyinput
}  // namespace cyanide