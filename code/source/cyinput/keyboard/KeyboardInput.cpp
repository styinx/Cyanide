#include "cyinput/keyboard/KeyboardInput.hpp"

namespace cyanide::cyinput
{

    const UMap<String, KeyboardInput::KEYBOARD_EVENT> KeyboardInput::s_event = {
        {"keydown", KeyboardInput::KEYBOARD_EVENT::DOWN},
        {"keyup", KeyboardInput::KEYBOARD_EVENT::UP},
        {"keypressed", KeyboardInput::KEYBOARD_EVENT::PRESSED},
    };

    KeyboardInput::KeyboardInput()
    {
        m_event_callbacks[KEYBOARD_EVENT::DOWN]    = Vector<EventCallback>();
        m_event_callbacks[KEYBOARD_EVENT::UP]      = Vector<EventCallback>();
        m_event_callbacks[KEYBOARD_EVENT::PRESSED] = Vector<EventCallback>();
        m_event_callbacks[KEYBOARD_EVENT::ANY]     = Vector<EventCallback>();
    }

    void KeyboardInput::keyEvent(const KeyCode key) const
    {
        if(m_key_event_callbacks.count(key))
        {
            for(const auto& callback : m_key_event_callbacks.at(key))
            {
                callback(key);
            }
        }
    }

    void KeyboardInput::keyDown(const KeyCode key) const
    {
        if(m_key_down_callbacks.count(key))
        {
            for(const auto& callback : m_key_down_callbacks.at(key))
            {
                callback(key);
            }
        }
    }

    void KeyboardInput::keyUp(const KeyCode key) const
    {
        if(m_key_up_callbacks.count(key))
        {
            for(const auto& callback : m_key_up_callbacks.at(key))
            {
                callback(key);
            }
        }
    }

    void KeyboardInput::keyPressed(const KeyCode key) const
    {
        if(m_key_pressed_callbacks.count(key))
        {
            for(const auto& callback : m_key_pressed_callbacks.at(key))
            {
                callback(key);
            }
        }
    }

    KeyboardInput::KEY_STATE KeyboardInput::getKeyState(const KeyCode key) const
    {
        if(m_keys_states.count(key))
        {
            return m_keys_states.at(key);
        }
        return KEY_STATE::NONE;
    }

    void KeyboardInput::on(const String& event, const EventCallback& callback)
    {
        if(KeyboardInput::s_event.count(event))
        {
            on(KeyboardInput::s_event.at(event), callback);
        }
    }

    void KeyboardInput::on(const KEYBOARD_EVENT event, const EventCallback& callback)
    {
        m_event_callbacks[event].emplace_back(callback);
    }

    void KeyboardInput::on(const String& event, const KeyCode key, const KeyCallback& callback)
    {
        if(KeyboardInput::s_event.count(event))
        {
            on(KeyboardInput::s_event.at(event), key, callback);
        }
    }

    void KeyboardInput::on(const KEYBOARD_EVENT event, const KeyCode key, const KeyCallback& callback)
    {
        switch(event)
        {
        case KEYBOARD_EVENT::DOWN:
        {
            onKeyDown(key, callback);
            break;
        }
        case KEYBOARD_EVENT::UP:
        {
            onKeyUp(key, callback);
            break;
        }
        case KEYBOARD_EVENT::PRESSED:
        {
            onKeyPressed(key, callback);
            break;
        }
        case KEYBOARD_EVENT::ANY:
        {
            onKey(key, callback);
            break;
        }
        default:
        {
            break;
        }
        }
    }

    void KeyboardInput::onAnyKeyEvent(const EventCallback& callback)
    {
        m_event_callbacks[KEYBOARD_EVENT::ANY].emplace_back(callback);
    }

    void KeyboardInput::onKey(const KeyCode key, const KeyCallback& callback)
    {
        if(!m_key_event_callbacks.count(key))
        {
            m_key_event_callbacks[key] = Vector<KeyCallback>();
        }
        m_key_event_callbacks[key].emplace_back(callback);
    }

    void KeyboardInput::onKeyDown(const KeyCode key, const KeyCallback& callback)
    {
        if(!m_key_down_callbacks.count(key))
        {
            m_key_down_callbacks[key] = Vector<KeyCallback>();
        }
        m_key_down_callbacks[key].emplace_back(callback);
    }

    void KeyboardInput::onKeyUp(const KeyCode key, const KeyCallback& callback)
    {
        if(!m_key_up_callbacks.count(key))
        {
            m_key_up_callbacks[key] = Vector<KeyCallback>();
        }
        m_key_up_callbacks[key].emplace_back(callback);
    }

    void KeyboardInput::onKeyPressed(const KeyCode key, const KeyCallback& callback)
    {
        if(!m_key_pressed_callbacks.count(key))
        {
            m_key_pressed_callbacks[key] = Vector<KeyCallback>();
        }
        m_key_pressed_callbacks[key].emplace_back(callback);
    }

    void KeyboardInput::anyKeyEvent(const SDL_Event& event) const
    {
        for(const auto& callback : m_event_callbacks.at(KEYBOARD_EVENT::ANY))
        {
            callback(event);
        }
    }

    void KeyboardInput::defaultKeyboardHandler()
    {
        const WeakPtr<KeyboardInput> weak_this = shared_from_this();

        const auto setKeyState = [weak_this](const SDL_Event& event) {
            if(const SharedPtr<KeyboardInput> strong_this = weak_this.lock())
            {
                const auto key = event.key.keysym.sym;

                strong_this->keyEvent(key);

                if(event.type == SDL_KEYDOWN)
                {
                    if(strong_this->m_keys_states[key] == KEY_STATE::DOWN)
                    {
                        strong_this->m_keys_states[key] = KEY_STATE::PRESSED;
                    }

                    if(strong_this->m_keys_states[key] == KEY_STATE::PRESSED)
                    {
                        strong_this->keyPressed(key);
                    }
                    else
                    {
                        strong_this->m_keys_states[key] = KEY_STATE::DOWN;
                        strong_this->keyDown(key);
                    }
                }
                else if(event.type == SDL_KEYUP)
                {
                    strong_this->m_keys_states[key] = KEY_STATE::RELEASED;
                    strong_this->keyUp(key);
                }
            }
        };

        onAnyKeyEvent(setKeyState);
    }

}  // namespace cyanide::cyinput
