#ifndef CYANIDE_CONTROLLERINPUT_HPP
#define CYANIDE_CONTROLLERINPUT_HPP

#include "cyinput/IInputDevice.hpp"
#include "cymath/Point.hpp"

namespace cyanide::cyinput
{

    enum class CONTROLLER_STICK : Byte
    {
        LS = 0x00,
        RS = 0x01,
    };

    enum class CONTROLLER_TRIGGER : Byte
    {
        LT = 0x00,
        RT = 0x01,
    };

    enum class CONTROLLER_EVENT : Byte
    {
        NONE           = 0x00,
        BUTTON         = 0x01,
        BUTTON_DOWN    = 0x02,
        BUTTON_UP      = 0x03,
        BUTTON_PRESSED = 0x04,
        STICK_MOTION   = 0x05,
        TRIGGER_MOTION = 0x06,
        ANY            = 0xF5,
    };

    enum class CONTROLLER_BUTTON_STATE : Byte
    {
        NONE     = 0x00,
        RELEASED = 0x01,
        DOWN     = 0x02,
        PRESSED  = 0x04
    };

    using ControllerButton          = Uint8;
    using ControllerStick           = Uint8;
    using ControllerTrigger         = Uint8;
    using ControllerButtonCallback  = Function<void(const ControllerButton)>;
    using ControllerStickCallback   = Function<void(const Sint16 x, const Sint16 y)>;
    using ControllerTriggerCallback = Function<void(const Sint16 y)>;

    class ControllerInput
        : public IInputDevice
        , public std::enable_shared_from_this<ControllerInput>
    {
    protected:
        static const UMap<String, CONTROLLER_EVENT> s_event;

        SDL_GameController* m_controller = nullptr;

        UMap<ControllerButton, CONTROLLER_BUTTON_STATE> m_button_states;
        UMap<CONTROLLER_STICK, cymath::Point>           m_stick_position;
        UMap<CONTROLLER_TRIGGER, Sint16>                m_trigger_position;

        UMap<CONTROLLER_EVENT, Vector<EventCallback>>               m_event_callbacks;
        UMap<ControllerButton, Vector<ControllerButtonCallback>>    m_button_event_callbacks;
        UMap<ControllerButton, Vector<ControllerButtonCallback>>    m_button_down_callbacks;
        UMap<ControllerButton, Vector<ControllerButtonCallback>>    m_button_up_callbacks;
        UMap<ControllerButton, Vector<ControllerButtonCallback>>    m_button_pressed_callbacks;
        UMap<CONTROLLER_STICK, Vector<ControllerStickCallback>>     m_stick_motion_callbacks;
        UMap<CONTROLLER_TRIGGER, Vector<ControllerTriggerCallback>> m_trigger_motion_callbacks;

        explicit ControllerInput(const Uint8 id);

        void buttonEvent(const ControllerButton button) const;
        void buttonDown(const ControllerButton button) const;
        void buttonUp(const ControllerButton button) const;
        void buttonPressed(const ControllerButton button) const;
        void stickMotion(const CONTROLLER_STICK stick) const;
        void triggerMotion(const CONTROLLER_TRIGGER trigger) const;

    public:
        virtual ~ControllerInput();

        CONTROLLER_BUTTON_STATE getButtonState(const ControllerButton button) const;

        virtual void on(const String& event, const EventCallback& callback) final;
        virtual void on(const CONTROLLER_EVENT event, const EventCallback& callback) final;
        virtual void onAnyControllerEvent(const EventCallback& callback) final;
        virtual void onAnyButtonEvent(const EventCallback& callback) final;
        virtual void onButton(const ControllerButton button, const ControllerButtonCallback& callback) final;
        virtual void onButtonDown(const ControllerButton button, const ControllerButtonCallback& callback) final;
        virtual void onButtonUp(const ControllerButton button, const ControllerButtonCallback& callback) final;
        virtual void onButtonPressed(
            const ControllerButton          button,
            const ControllerButtonCallback& callback) final;
        virtual void onStickMotion(const CONTROLLER_STICK stick, const ControllerStickCallback& callback) final;
        virtual void onTriggerkMotion(
            const CONTROLLER_TRIGGER         trigger,
            const ControllerTriggerCallback& callback) final;

        // TODO

        void         anyControllerEvent(const SDL_Event& event) const;
        virtual void defaultHandler() override;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_CONTROLLERINPUT_HPP
