#ifndef CYANIDE_KEYCOMBINATION_HPP
#define CYANIDE_KEYCOMBINATION_HPP

#include "cyinput/IKey.hpp"

namespace cyanide
{
namespace cyinput
{

    class KeyCombination final
    {
    private:

    public:
        KeyCombination() = default;
        ~KeyCombination() = default;
        explicit KeyCombination(const IKey& key);
        KeyCombination(const KeyCombination& key_combination) = default;
        KeyCombination(KeyCombination&& key_combination) noexcept = default;
        KeyCombination& operator=(const KeyCombination& key_combination) = default;
        KeyCombination& operator=(KeyCombination&& key_combination) noexcept = default;
        KeyCombination operator|(KeyCombination& key_combination);
        KeyCombination& operator|=(KeyCombination& key_combination);
        KeyCombination operator|(IKey& key);
        KeyCombination& operator|=(IKey& key);
        KeyCombination operator&(KeyCombination& key_combination);
        KeyCombination& operator&=(KeyCombination& key_combination);
        KeyCombination operator&(IKey& key);
        KeyCombination& operator&=(IKey& key);
        explicit operator bool() const;
    };

}  // namespace cyinput
}  // namespace cyanide

#endif  // CYANIDE_KEYCOMBINATION_HPP
