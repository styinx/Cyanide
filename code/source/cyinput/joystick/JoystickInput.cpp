#include "cyinput/joystick/JoystickInput.hpp"

#include "cyutil/logging/Logging.hpp"

#include <iostream>

namespace cyanide::cyinput
{

    const UMap<String, JOYSTICK_EVENT> JoystickInput::s_event = {
        {"button", JOYSTICK_EVENT::BUTTON},
        {"buttondown", JOYSTICK_EVENT::BUTTON_DOWN},
        {"buttonup", JOYSTICK_EVENT::BUTTON_UP},
        {"buttonpressed", JOYSTICK_EVENT::BUTTON_PRESSED},
        {"axismotion", JOYSTICK_EVENT::AXIS_MOTION},
        {"hatmotion", JOYSTICK_EVENT::HAT_MOTION},
        {"ballmotion", JOYSTICK_EVENT::BALL_MOTION},
        {"any", JOYSTICK_EVENT::ANY},
    };

    JoystickInput::JoystickInput(const Uint8 id)
    {
        m_joystick = SDL_JoystickOpen(id);

        for(Uint8 axis = 0; axis < SDL_JoystickNumAxes(m_joystick); ++axis)
        {
            m_axis_position[axis] = 0;
        }

        for(Uint8 hat = 0; hat < SDL_JoystickNumHats(m_joystick); ++hat)
        {
            m_hat_position[hat] = 0;
        }

        for(Uint8 ball = 0; ball < SDL_JoystickNumBalls(m_joystick); ++ball)
        {
            m_axis_position[ball] = 0;
        }

        m_event_callbacks[JOYSTICK_EVENT::BUTTON]         = Vector<EventCallback>();
        m_event_callbacks[JOYSTICK_EVENT::BUTTON_DOWN]    = Vector<EventCallback>();
        m_event_callbacks[JOYSTICK_EVENT::BUTTON_UP]      = Vector<EventCallback>();
        m_event_callbacks[JOYSTICK_EVENT::BUTTON_PRESSED] = Vector<EventCallback>();
        m_event_callbacks[JOYSTICK_EVENT::AXIS_MOTION]    = Vector<EventCallback>();
        m_event_callbacks[JOYSTICK_EVENT::BALL_MOTION]    = Vector<EventCallback>();
        m_event_callbacks[JOYSTICK_EVENT::HAT_MOTION]     = Vector<EventCallback>();
        m_event_callbacks[JOYSTICK_EVENT::ANY]            = Vector<EventCallback>();
    }

    JoystickInput::~JoystickInput()
    {
        SDL_JoystickClose(m_joystick);
    }

    void JoystickInput::buttonEvent(const JoystickButton button) const
    {
        if(m_button_event_callbacks.count(button))
        {
            for(const auto& callback : m_button_event_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void JoystickInput::buttonDown(const JoystickButton button) const
    {
        if(m_button_down_callbacks.count(button))
        {
            for(const auto& callback : m_button_down_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void JoystickInput::buttonUp(const JoystickButton button) const
    {
        if(m_button_up_callbacks.count(button))
        {
            for(const auto& callback : m_button_up_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void JoystickInput::buttonPressed(const JoystickButton button) const
    {
        if(m_button_pressed_callbacks.count(button))
        {
            for(const auto& callback : m_button_pressed_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void JoystickInput::axisMotion(const JoystickAxis axis) const
    {
        if(m_axis_callbacks.count(axis))
        {
            const auto val = m_axis_position.at(axis);
            for(const auto& callback : m_axis_callbacks.at(axis))
            {
                callback(val);
            }
        }
    }

    void JoystickInput::hatMotion(const JoystickHat hat) const
    {
        if(m_hat_callbacks.count(hat))
        {
            const auto val = m_hat_position.at(hat);
            for(const auto& callback : m_hat_callbacks.at(hat))
            {
                callback(val);
            }
        }
    }

    void JoystickInput::ballMotion(const JoystickBall ball) const
    {
        if(m_ball_callbacks.count(ball))
        {
            const auto diff = m_ball_diff.at(ball);
            for(const auto& callback : m_ball_callbacks.at(ball))
            {
                callback(diff.x, diff.y);
            }
        }
    }

    JOYSTICK_BUTTON_STATE JoystickInput::getButtonState(const JoystickButton button) const
    {
        if(m_button_states.count(button))
        {
            return m_button_states.at(button);
        }
        return JOYSTICK_BUTTON_STATE::NONE;
    }

    void JoystickInput::on(const String& event, const EventCallback& callback)
    {
        if(JoystickInput::s_event.count(event))
        {
            on(JoystickInput::s_event.at(event), callback);
        }
    }

    void JoystickInput::on(const JOYSTICK_EVENT event, const EventCallback& callback)
    {
        m_event_callbacks[event].emplace_back(callback);
    }

    void JoystickInput::onAnyJoystickEvent(const EventCallback& callback)
    {
        m_event_callbacks[JOYSTICK_EVENT::ANY].emplace_back(callback);
    }

    void JoystickInput::onAnyButtonEvent(const EventCallback& callback)
    {
        m_event_callbacks[JOYSTICK_EVENT::BUTTON].emplace_back(callback);
    }

    void JoystickInput::onButton(const JoystickButton button, const JoystickButtonCallback& callback)
    {
        if(!m_button_event_callbacks.count(button))
        {
            m_button_event_callbacks[button] = Vector<JoystickButtonCallback>();
        }
        m_button_event_callbacks[button].emplace_back(callback);
    }

    void JoystickInput::onButtonDown(const JoystickButton button, const JoystickButtonCallback& callback)
    {
        if(!m_button_down_callbacks.count(button))
        {
            m_button_down_callbacks[button] = Vector<JoystickButtonCallback>();
        }
        m_button_down_callbacks[button].emplace_back(callback);
    }

    void JoystickInput::onButtonUp(const JoystickButton button, const JoystickButtonCallback& callback)
    {
        if(!m_button_up_callbacks.count(button))
        {
            m_button_up_callbacks[button] = Vector<JoystickButtonCallback>();
        }
        m_button_up_callbacks[button].emplace_back(callback);
    }

    void JoystickInput::onButtonPressed(const JoystickButton button, const JoystickButtonCallback& callback)
    {
        if(!m_button_pressed_callbacks.count(button))
        {
            m_button_pressed_callbacks[button] = Vector<JoystickButtonCallback>();
        }
        m_button_pressed_callbacks[button].emplace_back(callback);
    }

    void JoystickInput::onAxisMotion(const JoystickAxis axis, const JoystickAxisCallback& callback)
    {
        if(!m_axis_callbacks.count(axis))
        {
            m_axis_callbacks[axis] = Vector<JoystickAxisCallback>();
        }
        m_axis_callbacks[axis].emplace_back(callback);
    }

    void JoystickInput::onHatMotion(const JoystickHat hat, const JoystickHatCallback& callback)
    {
        if(!m_hat_callbacks.count(hat))
        {
            m_hat_callbacks[hat] = Vector<JoystickHatCallback>();
        }
        m_hat_callbacks[hat].emplace_back(callback);
    }

    void JoystickInput::onBallMotion(const JoystickBall ball, const JoystickBallCallback& callback)
    {
        if(!m_ball_callbacks.count(ball))
        {
            m_ball_callbacks[ball] = Vector<JoystickBallCallback>();
        }
        m_ball_callbacks[ball].emplace_back(callback);
    }

    void JoystickInput::anyJoystickEvent(const SDL_Event& event) const
    {
        for(const auto& callback : m_event_callbacks.at(JOYSTICK_EVENT::ANY))
        {
            callback(event);
        }
    }

    void JoystickInput::defaultHandler()
    {
        const WeakPtr<JoystickInput> weak_this = shared_from_this();

        const auto setJoystickState = [weak_this](const SDL_Event& event) {
            if(const SharedPtr<JoystickInput> strong_this = weak_this.lock())
            {
                const auto button       = event.jbutton.button;
                const auto axis         = event.jaxis.axis;
                const auto ball         = event.jball.ball;
                const auto hat          = event.jhat.hat;
                bool       button_event = false;

                if(event.type == SDL_JOYBUTTONDOWN)
                {
                    button_event = true;
                    if(strong_this->m_button_states[button] == JOYSTICK_BUTTON_STATE::DOWN)
                    {
                        strong_this->m_button_states[button] = JOYSTICK_BUTTON_STATE::PRESSED;
                    }

                    if(strong_this->m_button_states[button] == JOYSTICK_BUTTON_STATE::PRESSED)
                    {
                        strong_this->buttonPressed(button);
                    }
                    else
                    {
                        strong_this->m_button_states[button] = JOYSTICK_BUTTON_STATE::DOWN;
                        strong_this->buttonDown(button);
                    }
                }
                else if(event.type == SDL_JOYBUTTONUP)
                {
                    button_event                         = true;
                    strong_this->m_button_states[button] = JOYSTICK_BUTTON_STATE::RELEASED;
                    strong_this->buttonUp(button);
                }
                else if(event.type == SDL_JOYAXISMOTION)
                {
                    strong_this->m_axis_position[axis] = event.jaxis.value;
                    strong_this->axisMotion(axis);
                }
                else if(event.type == SDL_JOYHATMOTION)
                {
                    strong_this->m_hat_position[hat] = event.jhat.value;
                    strong_this->hatMotion(hat);
                }
                else if(event.type == SDL_JOYBALLMOTION)
                {
                    strong_this->m_ball_diff[ball].x = event.jball.xrel;
                    strong_this->m_ball_diff[ball].y = event.jball.yrel;
                    strong_this->ballMotion(ball);
                }

                if(button_event)
                {
                    strong_this->buttonEvent(button);
                }
            }
        };

        onAnyJoystickEvent(setJoystickState);
    }

}  // namespace cyanide::cyinput
