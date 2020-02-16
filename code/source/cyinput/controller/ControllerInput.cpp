#include "cyinput/controller/ControllerInput.hpp"

namespace cyanide::cyinput
{

    const UMap<String, CONTROLLER_EVENT> ControllerInput::s_event = {
        {"button", CONTROLLER_EVENT::BUTTON},
        {"buttondown", CONTROLLER_EVENT::BUTTON_DOWN},
        {"buttonup", CONTROLLER_EVENT::BUTTON_UP},
        {"buttonpressed", CONTROLLER_EVENT::BUTTON_PRESSED},
        {"stickmotion", CONTROLLER_EVENT::STICK_MOTION},
        {"triggermotion", CONTROLLER_EVENT::TRIGGER_MOTION},
        {"any", CONTROLLER_EVENT::ANY},
    };

    ControllerInput::ControllerInput(const Uint8 id)
    {
        m_controller = SDL_GameControllerOpen(id);
        // todo axis of controller

        m_event_callbacks[CONTROLLER_EVENT::BUTTON]         = Vector<EventCallback>();
        m_event_callbacks[CONTROLLER_EVENT::BUTTON_DOWN]    = Vector<EventCallback>();
        m_event_callbacks[CONTROLLER_EVENT::BUTTON_UP]      = Vector<EventCallback>();
        m_event_callbacks[CONTROLLER_EVENT::BUTTON_PRESSED] = Vector<EventCallback>();
        m_event_callbacks[CONTROLLER_EVENT::STICK_MOTION]   = Vector<EventCallback>();
        m_event_callbacks[CONTROLLER_EVENT::TRIGGER_MOTION] = Vector<EventCallback>();
        m_event_callbacks[CONTROLLER_EVENT::ANY]            = Vector<EventCallback>();
    }

    ControllerInput::~ControllerInput()
    {
        SDL_GameControllerClose(m_controller);
    }

    void ControllerInput::buttonEvent(ControllerButton button) const
    {
        if(m_button_event_callbacks.count(button))
        {
            for(const auto& callback : m_button_event_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void ControllerInput::buttonDown(ControllerButton button) const
    {
        if(m_button_down_callbacks.count(button))
        {
            for(const auto& callback : m_button_down_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void ControllerInput::buttonUp(ControllerButton button) const
    {
        if(m_button_up_callbacks.count(button))
        {
            for(const auto& callback : m_button_up_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void ControllerInput::buttonPressed(ControllerButton button) const
    {
        if(m_button_pressed_callbacks.count(button))
        {
            for(const auto& callback : m_button_pressed_callbacks.at(button))
            {
                callback(button);
            }
        }
    }

    void ControllerInput::stickMotion(const CONTROLLER_STICK stick) const
    {
        if(m_stick_motion_callbacks.count(stick))
        {
            const auto stick_pos = m_stick_position.at(stick);
            for(const auto& callback : m_stick_motion_callbacks.at(stick))
            {
                callback(stick_pos.x, stick_pos.y);
            }
        }
    }

    void ControllerInput::triggerMotion(const CONTROLLER_TRIGGER trigger) const
    {
        if(m_trigger_motion_callbacks.count(trigger))
        {
            const auto trigger_pos = m_trigger_position.at(trigger);
            for(const auto& callback : m_trigger_motion_callbacks.at(trigger))
            {
                callback(trigger_pos);
            }
        }
    }

    CONTROLLER_BUTTON_STATE ControllerInput::getButtonState(ControllerButton button) const
    {
        if(m_button_states.count(button))
        {
            return m_button_states.at(button);
        }
        return CONTROLLER_BUTTON_STATE::NONE;
    }

    void ControllerInput::on(const String& event, const EventCallback& callback)
    {
        if(ControllerInput::s_event.count(event))
        {
            on(ControllerInput::s_event.at(event), callback);
        }
    }

    void ControllerInput::on(CONTROLLER_EVENT event, const EventCallback& callback)
    {
        m_event_callbacks[event].emplace_back(callback);
    }

    void ControllerInput::onAnyControllerEvent(const EventCallback& callback)
    {
        m_event_callbacks[CONTROLLER_EVENT::ANY].emplace_back(callback);
    }

    void ControllerInput::onAnyButtonEvent(const EventCallback& callback)
    {
        m_event_callbacks[CONTROLLER_EVENT::BUTTON].emplace_back(callback);
    }

    void ControllerInput::onButton(const ControllerButton button, const ControllerButtonCallback& callback)
    {
        if(!m_button_event_callbacks.count(button))
        {
            m_button_event_callbacks[button] = Vector<ControllerButtonCallback>();
        }
        m_button_event_callbacks[button].emplace_back(callback);
    }

    void ControllerInput::onButtonDown(const ControllerButton button, const ControllerButtonCallback& callback)
    {
        if(!m_button_down_callbacks.count(button))
        {
            m_button_down_callbacks[button] = Vector<ControllerButtonCallback>();
        }
        m_button_down_callbacks[button].emplace_back(callback);
    }

    void ControllerInput::onButtonUp(const ControllerButton button, const ControllerButtonCallback& callback)
    {
        if(!m_button_up_callbacks.count(button))
        {
            m_button_up_callbacks[button] = Vector<ControllerButtonCallback>();
        }
        m_button_up_callbacks[button].emplace_back(callback);
    }

    void ControllerInput::onButtonPressed(const ControllerButton button, const ControllerButtonCallback& callback)
    {
        if(!m_button_pressed_callbacks.count(button))
        {
            m_button_pressed_callbacks[button] = Vector<ControllerButtonCallback>();
        }
        m_button_pressed_callbacks[button].emplace_back(callback);
    }

    void ControllerInput::onStickMotion(const CONTROLLER_STICK stick, const ControllerStickCallback& callback)
    {
        if(!m_stick_motion_callbacks.count(stick))
        {
            m_stick_motion_callbacks[stick] = Vector<ControllerStickCallback>();
        }
        m_stick_motion_callbacks[stick].emplace_back(callback);
    }

    void ControllerInput::onTriggerkMotion(
        const CONTROLLER_TRIGGER         trigger,
        const ControllerTriggerCallback& callback)
    {
        if(!m_trigger_motion_callbacks.count(trigger))
        {
            m_trigger_motion_callbacks[trigger] = Vector<ControllerTriggerCallback>();
        }
        m_trigger_motion_callbacks[trigger].emplace_back(callback);
    }

    void ControllerInput::anyControllerEvent(const SDL_Event& event) const
    {
        for(const auto& callback : m_event_callbacks.at(CONTROLLER_EVENT::ANY))
        {
            callback(event);
        }
    }

    void ControllerInput::defaultHandler()
    {
        const WeakPtr<ControllerInput> weak_this = shared_from_this();

        const auto setControllerState = [weak_this](const SDL_Event& event) {
            if(const SharedPtr<ControllerInput> strong_this = weak_this.lock())
            {
                const auto button       = event.cbutton.button;
                bool       button_event = false;

                if(event.type == SDL_CONTROLLERBUTTONDOWN)
                {
                    button_event = true;
                    if(strong_this->m_button_states[button] == CONTROLLER_BUTTON_STATE::DOWN)
                    {
                        strong_this->m_button_states[button] = CONTROLLER_BUTTON_STATE::PRESSED;
                    }

                    if(strong_this->m_button_states[button] == CONTROLLER_BUTTON_STATE::PRESSED)
                    {
                        strong_this->buttonPressed(button);
                    }
                    else
                    {
                        strong_this->m_button_states[button] = CONTROLLER_BUTTON_STATE::DOWN;
                        strong_this->buttonDown(button);
                    }
                }
                else if(event.type == SDL_CONTROLLERBUTTONUP)
                {
                    button_event                         = true;
                    strong_this->m_button_states[button] = CONTROLLER_BUTTON_STATE::RELEASED;
                    strong_this->buttonUp(button);
                }
                else if(event.type == SDL_CONTROLLERAXISMOTION)
                {
                    bool trigger_motion = false;
                    bool left           = false;

                    if(event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX)
                    {
                        left = true;

                        strong_this->m_stick_position[CONTROLLER_STICK::LS].x = event.caxis.value;
                    }
                    else if(event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY)
                    {
                        left = true;

                        strong_this->m_stick_position[CONTROLLER_STICK::LS].y = event.caxis.value;
                    }
                    else if(event.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTX)
                    {
                        strong_this->m_stick_position[CONTROLLER_STICK::RS].x = event.caxis.value;
                    }
                    else if(event.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTY)
                    {
                        strong_this->m_stick_position[CONTROLLER_STICK::RS].y = event.caxis.value;
                    }
                    else if(event.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
                    {
                        left           = true;
                        trigger_motion = true;

                        strong_this->m_trigger_position[CONTROLLER_TRIGGER::LT] = event.caxis.value;
                    }
                    else if(event.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
                    {
                        trigger_motion = true;

                        strong_this->m_trigger_position[CONTROLLER_TRIGGER::RT] = event.caxis.value;
                    }
                    else
                    {
                        // todo invalid axis
                        return;
                    }

                    if(!trigger_motion)
                    {
                        if(left)
                        {
                            strong_this->stickMotion(CONTROLLER_STICK::LS);
                        }
                        else
                        {
                            strong_this->stickMotion(CONTROLLER_STICK::RS);
                        }
                    }
                    else
                    {
                        if(left)
                        {
                            strong_this->triggerMotion(CONTROLLER_TRIGGER::LT);
                        }
                        else
                        {
                            strong_this->triggerMotion(CONTROLLER_TRIGGER::RT);
                        }
                    }
                }

                if(button_event)
                {
                    strong_this->buttonEvent(button);
                }
            }
        };

        onAnyControllerEvent(setControllerState);
    }

}  // namespace cyanide::cyinput
