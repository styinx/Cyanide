#include "cyinput/keyboard/Key.hpp"

namespace cyanide::cyinput
{

    Key::Key(const KeyCode key)
        : m_key_code(key)
    {

    }

    Key::Key(const Key& other)
        : m_key_code(other.m_key_code)
    {
    }

    Key::Key(Key&& other) noexcept
        : m_key_code(other.m_key_code)
    {
        other.m_key_code = 0;
    }

    Key& Key::operator=(const Key& other)
    {
        m_key_code = other.m_key_code;
        return *this;
    }

    Key& Key::operator=(Key&& other) noexcept
    {
        m_key_code = other.m_key_code;
        other.m_key_code = 0;
        return *this;
    }

    KEY_STATE Key::getKeyState() const
    {
        return m_key_state;
    }

    bool Key::isReleased() const
    {
        return m_key_state == KEY_STATE::RELEASED;
    }

    bool Key::isDown() const
    {
        return m_key_state == KEY_STATE::DOWN;
    }

    bool Key::isPressed() const
    {
        return m_key_state == KEY_STATE::PRESSED;
    }

    KeyCode Key::getCode() const
    {
        return m_key_code;
    }

    void Key::setCode(const KeyCode key)
    {
        m_key_code = key;
    }

}  // namespace cyanide
