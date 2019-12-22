#include "cyinput/mouse/MouseInput.hpp"

namespace cyanide::cyinput
{

    const UMap<String, MouseInput::MOUSE_EVENT> MouseInput::s_event = {
        {"motion", MouseInput::MOUSE_EVENT::MOTION},
        {"buttondown", MouseInput::MOUSE_EVENT::BUTTON_DOWN},
        {"buttonup", MouseInput::MOUSE_EVENT::BUTTON_UP},
        {"buttonpressed", MouseInput::MOUSE_EVENT::BUTTON_PRESSED},
        {"wheelmotion", MouseInput::MOUSE_EVENT::WHEEL_MOTION},
    };

    MouseInput::MouseInput()
    {
        m_event_callbacks[MOUSE_EVENT::MOTION]         = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::BUTTON_DOWN]    = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::BUTTON_UP]      = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::BUTTON_PRESSED] = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::WHEEL_MOTION]   = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::ANY]            = Vector<EventCallback>();
    }

    void MouseInput::buttonEvent(const MouseButtonCode button) const
    {
        if(m_button_event_callbacks.count(button))
        {
            for(const auto& callback : m_button_event_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void MouseInput::buttonDown(const MouseButtonCode button) const
    {
        if(m_button_down_callbacks.count(button))
        {
            for(const auto& callback : m_button_down_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void MouseInput::buttonUp(const MouseButtonCode button) const
    {
        if(m_button_up_callbacks.count(button))
        {
            for(const auto& callback : m_button_up_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void MouseInput::buttonPressed(const MouseButtonCode button) const
    {
        if(m_button_pressed_callbacks.count(button))
        {
            for(const auto& callback : m_button_pressed_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    MouseInput::MOUSE_BUTTON_STATE MouseInput::getButtonState(const MouseButtonCode button) const
    {
        if(m_button_states.count(button))
        {
            return m_button_states.at(button);
        }
        return MOUSE_BUTTON_STATE::NONE;
    }

    void MouseInput::on(const String& event, const EventCallback& callback)
    {
        if(MouseInput::s_event.count(event))
        {
            on(MouseInput::s_event.at(event), callback);
        }
    }

    void MouseInput::on(const MOUSE_EVENT event, const EventCallback& callback)
    {
        m_event_callbacks.at(event).emplace_back(callback);
    }

    void MouseInput::on(const String& event, const MouseButtonCode button, const MouseButtonCallback& callback)
    {
        if(MouseInput::s_event.count(event))
        {
            on(MouseInput::s_event.at(event), button, callback);
        }
    }

    void MouseInput::on(const MOUSE_EVENT event, const MouseButtonCode button, const MouseButtonCallback& callback)
    {
        switch(event)
        {
        case MOUSE_EVENT::MOTION:
        {
            break;
        }
        case MOUSE_EVENT::BUTTON_DOWN:
        {
            buttonDown(button);
            break;
        }
        case MOUSE_EVENT::BUTTON_UP:
        {
            buttonUp(button);
            break;
        }
        case MOUSE_EVENT::BUTTON_PRESSED:
        {
            buttonPressed(button);
            break;
        }
        case MOUSE_EVENT::WHEEL_MOTION:
        {
            break;
        }
        case MOUSE_EVENT::ANY:
        {
            break;
        }
        case MOUSE_EVENT::NONE:
        default:
        {
            break;
        }
        }
    }

    void MouseInput::onAnyMouseEvent(const EventCallback& callback)
    {
    }

    void MouseInput::onAnyButtonEvent(const EventCallback& callback)
    {
    }

    void MouseInput::onButton(const MouseButtonCode button, const MouseButtonCallback& callback)
    {
    }

    void MouseInput::onButtonDown(const MouseButtonCode button, const MouseButtonCallback& callback)
    {
    }

    void MouseInput::onButtonUp(const MouseButtonCode button, const MouseButtonCallback& callback)
    {
    }

    void MouseInput::onButtonPressed(const MouseButtonCode button, const MouseButtonCallback& callback)
    {
    }

    void MouseInput::anyMouseEvent(const SDL_Event& event) const
    {
    }

    void MouseInput::defaultMouseHandler()
    {
        const WeakPtr<MouseInput> weak_this = shared_from_this();

        const auto setMouseState = [weak_this](const SDL_Event& event) {
            if(const SharedPtr<MouseInput> strong_this = weak_this.lock())
            {
                const auto key = event.key.keysym.sym;

                strong_this->buttonEvent(key);

                if(event.type == SDL_MOUSEBUTTONDOWN)
                {
                    if(strong_this->m_button_states[key] == MOUSE_BUTTON_STATE::DOWN)
                    {
                        strong_this->m_button_states[key] = MOUSE_BUTTON_STATE::PRESSED;
                    }

                    if(strong_this->m_button_states[key] == MOUSE_BUTTON_STATE::PRESSED)
                    {
                        strong_this->buttonPressed(key);
                    }
                    else
                    {
                        strong_this->m_button_states[key] = MOUSE_BUTTON_STATE::DOWN;
                        strong_this->buttonDown(key);
                    }
                }
                else if(event.type == SDL_MOUSEBUTTONUP)
                {
                    strong_this->m_button_states[key] = MOUSE_BUTTON_STATE::RELEASED;
                    strong_this->buttonUp(key);
                }
            }
        };

        onAnyMouseEvent(setMouseState);
    }

}  // namespace cyanide::cyinput
