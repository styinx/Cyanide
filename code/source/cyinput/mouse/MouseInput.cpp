#include "cyinput/mouse/MouseInput.hpp"

namespace cyanide::cyinput
{

    const UMap<String, MouseInput::MOUSE_EVENT> MouseInput::s_event = {
        {"stickMotion", MouseInput::MOUSE_EVENT::MOTION},
        {"button", MouseInput::MOUSE_EVENT::BUTTON},
        {"buttondown", MouseInput::MOUSE_EVENT::BUTTON_DOWN},
        {"buttonup", MouseInput::MOUSE_EVENT::BUTTON_UP},
        {"buttonpressed", MouseInput::MOUSE_EVENT::BUTTON_PRESSED},
        {"wheelmotion", MouseInput::MOUSE_EVENT::WHEEL_MOTION},
        {"any", MouseInput::MOUSE_EVENT::ANY},
    };

    MouseInput::MouseInput()
    {
        m_event_callbacks[MOUSE_EVENT::MOTION]         = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::BUTTON]         = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::BUTTON_DOWN]    = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::BUTTON_UP]      = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::BUTTON_PRESSED] = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::WHEEL_MOTION]   = Vector<EventCallback>();
        m_event_callbacks[MOUSE_EVENT::ANY]            = Vector<EventCallback>();
    }

    void MouseInput::motion(const Sint32 x, const Sint32 y) const
    {
        for(const auto& callback : m_motion_callbacks)
        {
            callback(x, y);
        }
    }

    void MouseInput::buttonEvent(const MouseButton button) const
    {
        if(m_button_event_callbacks.count(button))
        {
            for(const auto& callback : m_button_event_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void MouseInput::buttonDown(const MouseButton button) const
    {
        if(m_button_down_callbacks.count(button))
        {
            for(const auto& callback : m_button_down_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void MouseInput::buttonUp(const MouseButton button) const
    {
        if(m_button_up_callbacks.count(button))
        {
            for(const auto& callback : m_button_up_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void MouseInput::buttonPressed(const MouseButton button) const
    {
        if(m_button_pressed_callbacks.count(button))
        {
            for(const auto& callback : m_button_pressed_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void MouseInput::wheelMotion(const Sint32 x, const Sint32 y) const
    {
        for(const auto& callback : m_wheel_motion_callbacks)
        {
            callback(x, y);
        }
    }

    MouseInput::MOUSE_BUTTON_STATE MouseInput::getButtonState(const MouseButton button) const
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
        m_event_callbacks[event].emplace_back(callback);
    }

    void MouseInput::onAnyMouseEvent(const EventCallback& callback)
    {
        m_event_callbacks[MOUSE_EVENT::ANY].emplace_back(callback);
    }

    void MouseInput::onMotion(const MouseInput::MouseMotionCallback& callback)
    {
        m_motion_callbacks.emplace_back(callback);
    }

    void MouseInput::onAnyButtonEvent(const EventCallback& callback)
    {
        m_event_callbacks[MOUSE_EVENT::BUTTON].emplace_back(callback);
    }

    void MouseInput::onButton(const MouseButton button, const MouseButtonCallback& callback)
    {
        if(!m_button_event_callbacks.count(button))
        {
            m_button_event_callbacks[button] = Vector<MouseButtonCallback>();
        }
        m_button_event_callbacks[button].emplace_back(callback);
    }

    void MouseInput::onButtonDown(const MouseButton button, const MouseButtonCallback& callback)
    {
        if(!m_button_down_callbacks.count(button))
        {
            m_button_down_callbacks[button] = Vector<MouseButtonCallback>();
        }
        m_button_down_callbacks[button].emplace_back(callback);
    }

    void MouseInput::onButtonUp(const MouseButton button, const MouseButtonCallback& callback)
    {
        if(!m_button_up_callbacks.count(button))
        {
            m_button_up_callbacks[button] = Vector<MouseButtonCallback>();
        }
        m_button_up_callbacks[button].emplace_back(callback);
    }

    void MouseInput::onButtonPressed(const MouseButton button, const MouseButtonCallback& callback)
    {
        if(!m_button_pressed_callbacks.count(button))
        {
            m_button_pressed_callbacks[button] = Vector<MouseButtonCallback>();
        }
        m_button_pressed_callbacks[button].emplace_back(callback);
    }

    void MouseInput::onWheelMotion(const MouseInput::MouseMotionCallback& callback)
    {
        m_wheel_motion_callbacks.emplace_back(callback);
    }

    void MouseInput::anyMouseEvent(const SDL_Event& event) const
    {
        for(const auto& callback : m_event_callbacks.at(MOUSE_EVENT::ANY))
        {
            callback(event);
        }
    }

    void MouseInput::defaultHandler()
    {
        const WeakPtr<MouseInput> weak_this = shared_from_this();

        const auto setMouseState = [weak_this](const SDL_Event& event) {
            if(const SharedPtr<MouseInput> strong_this = weak_this.lock())
            {
                const auto button             = event.button.button;
                bool       mouse_button_event = false;

                if(event.type == SDL_MOUSEMOTION)
                {
                    strong_this->m_mouse_position.set(event.motion.x, event.motion.y);
                    strong_this->motion(event.motion.x, event.motion.y);
                }
                else if(event.type == SDL_MOUSEBUTTONDOWN)
                {
                    mouse_button_event = true;
                    if(strong_this->m_button_states[button] == MOUSE_BUTTON_STATE::DOWN)
                    {
                        strong_this->m_button_states[button] = MOUSE_BUTTON_STATE::PRESSED;
                    }

                    if(strong_this->m_button_states[button] == MOUSE_BUTTON_STATE::PRESSED)
                    {
                        strong_this->buttonPressed(button);
                    }
                    else
                    {
                        strong_this->m_button_states[button] = MOUSE_BUTTON_STATE::DOWN;
                        strong_this->buttonDown(button);
                    }
                }
                else if(event.type == SDL_MOUSEBUTTONUP)
                {
                    mouse_button_event = true;
                    strong_this->m_button_states[button] = MOUSE_BUTTON_STATE::RELEASED;
                    strong_this->buttonUp(button);
                }
                else if(event.type == SDL_MOUSEWHEEL)
                {
                    strong_this->wheelMotion(event.motion.x, event.motion.y);
                }

                if(mouse_button_event)
                {
                    strong_this->buttonEvent(button);
                }
            }
        };

        onAnyMouseEvent(setMouseState);
    }

}  // namespace cyanide::cyinput
