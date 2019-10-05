#ifndef CYANIDE_KEYCOMBINATION_HPP
#define CYANIDE_KEYCOMBINATION_HPP

#include "cyinput/keyboard/IKey.hpp"

namespace cyanide::cyinput
{

    class KeyCombination final
    {
    private:
        Vector<KeyCode> m_and;
        Vector<KeyCode> m_or;

    public:
        KeyCombination()  = default;
        ~KeyCombination() = default;
        KeyCombination(const KeyCombination& other) = default;
        KeyCombination(KeyCombination&& other) noexcept = default;
        KeyCombination& operator=(const KeyCombination& key_combination) = default;
        KeyCombination& operator=(KeyCombination&& key_combination) noexcept = default;
        KeyCombination  operator|(KeyCombination& key_combination);
        KeyCombination& operator|=(KeyCombination& key_combination);
        KeyCombination  operator|(IKey& key);
        KeyCombination& operator|=(IKey& key);
        KeyCombination  operator&(KeyCombination& key_combination);
        KeyCombination& operator&=(KeyCombination& key_combination);
        KeyCombination  operator&(IKey& key);
        KeyCombination& operator&=(IKey& key);
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_KEYCOMBINATION_HPP
