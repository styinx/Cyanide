#include "cyinput/keyboard/KeyCombination.hpp"

namespace cyanide::cyinput
{

    KeyCombination KeyCombination::operator|(KeyCombination& key_combination)
    {
        KeyCombination keyComb = *this;

        for(const auto& or_key : key_combination.m_or)
        {
            keyComb.m_or.emplace_back(or_key);
        }

        return keyComb;
    }

    KeyCombination& KeyCombination::operator|=(KeyCombination& key_combination)
    {
        for(const auto& or_key : key_combination.m_or)
        {
            m_or.emplace_back(or_key);
        }

        return *this;
    }

    KeyCombination KeyCombination::operator|(IKey& key)
    {
        KeyCombination keyComb = *this;
        keyComb.m_or.emplace_back(key.getCode());
        return keyComb;
    }

    KeyCombination& KeyCombination::operator|=(IKey& key)
    {
        m_or.emplace_back(key.getCode());
        return *this;
    }

    KeyCombination KeyCombination::operator&(KeyCombination& key_combination)
    {
        KeyCombination keyComb = *this;

        for(const auto& and_key : key_combination.m_and)
        {
            keyComb.m_and.emplace_back(and_key);
        }

        return keyComb;
    }

    KeyCombination& KeyCombination::operator&=(KeyCombination& key_combination)
    {
        for(const auto& and_key : key_combination.m_and)
        {
            m_and.emplace_back(and_key);
        }

        return *this;
    }

    KeyCombination KeyCombination::operator&(IKey& key)
    {
        KeyCombination keyComb = *this;
        keyComb.m_and.emplace_back(key.getCode());
        return keyComb;
    }

    KeyCombination& KeyCombination::operator&=(IKey& key)
    {
        m_and.emplace_back(key.getCode());
        return *this;
    }

}  // namespace cyanide::cyinput
