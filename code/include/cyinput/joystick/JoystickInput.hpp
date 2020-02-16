#ifndef CYANIDE_JOYSTICKINPUT_HPP
#define CYANIDE_JOYSTICKINPUT_HPP

#include "cyinput/IInputDevice.hpp"

#include <cymath/Point.hpp>

namespace cyanide::cyinput
{

    enum class JOYSTICK_EVENT : Byte
    {
        NONE           = 0x00,
        BUTTON         = 0x01,
        BUTTON_DOWN    = 0x02,
        BUTTON_UP      = 0x03,
        BUTTON_PRESSED = 0x04,
        AXIS_MOTION    = 0x05,
        BALL_MOTION    = 0x06,
        HAT_MOTION     = 0x07,
        ANY            = 0xFC,
    };

    enum class JOYSTICK_BUTTON_STATE : Byte
    {
        NONE     = 0x00,
        RELEASED = 0x01,
        DOWN     = 0x02,
        PRESSED  = 0x04,
        ANY      = 0x07
    };

    using JoystickButton         = Uint8;
    using JoystickAxis           = Uint8;
    using JoystickHat            = Uint8;
    using JoystickBall           = Uint8;
    using JoystickButtonCallback = Function<void(const JoystickButton)>;
    using JoystickAxisCallback   = Function<void(const Sint16 val)>;
    using JoystickHatCallback    = Function<void(const Sint16 val)>;
    using JoystickBallCallback   = Function<void(const Sint16 x, const Sint16 y)>;

    class JoystickInput
        : public IInputDevice
        , public std::enable_shared_from_this<JoystickInput>
    {
    protected:
        static const UMap<String, JOYSTICK_EVENT> s_event;

        SDL_Joystick* m_joystick = nullptr;

        UMap<JoystickButton, JOYSTICK_BUTTON_STATE> m_button_states;
        UMap<JoystickAxis, Sint16>                  m_axis_position;
        UMap<JoystickHat, Sint16>                   m_hat_position;
        UMap<JoystickBall, cymath::Point>           m_ball_diff;

        UMap<JOYSTICK_EVENT, Vector<EventCallback>>          m_event_callbacks;
        UMap<JoystickButton, Vector<JoystickButtonCallback>> m_button_event_callbacks;
        UMap<JoystickButton, Vector<JoystickButtonCallback>> m_button_down_callbacks;
        UMap<JoystickButton, Vector<JoystickButtonCallback>> m_button_up_callbacks;
        UMap<JoystickButton, Vector<JoystickButtonCallback>> m_button_pressed_callbacks;
        UMap<JoystickAxis, Vector<JoystickAxisCallback>>     m_axis_callbacks;
        UMap<JoystickHat, Vector<JoystickHatCallback>>       m_hat_callbacks;
        UMap<JoystickBall, Vector<JoystickBallCallback>>     m_ball_callbacks;

        explicit JoystickInput(const Uint8 id);

        void buttonEvent(const JoystickButton button) const;
        void buttonDown(const JoystickButton button) const;
        void buttonUp(const JoystickButton button) const;
        void buttonPressed(const JoystickButton button) const;
        void axisMotion(const JoystickAxis axis) const;
        void hatMotion(const JoystickHat hat) const;
        void ballMotion(const JoystickBall ball) const;

    public:
        virtual ~JoystickInput();

        JOYSTICK_BUTTON_STATE getButtonState(const JoystickButton button) const;

        virtual void on(const String& event, const EventCallback& callback) final;
        virtual void on(const JOYSTICK_EVENT event, const EventCallback& callback) final;
        virtual void onAnyJoystickEvent(const EventCallback& callback) final;
        virtual void onAnyButtonEvent(const EventCallback& callback) final;
        virtual void onButton(const JoystickButton button, const JoystickButtonCallback& callback) final;
        virtual void onButtonDown(const JoystickButton button, const JoystickButtonCallback& callback) final;
        virtual void onButtonUp(const JoystickButton button, const JoystickButtonCallback& callback) final;
        virtual void onButtonPressed(const JoystickButton button, const JoystickButtonCallback& callback) final;
        virtual void onAxisMotion(const JoystickAxis axis, const JoystickAxisCallback& callback) final;
        virtual void onHatMotion(const JoystickHat hat, const JoystickHatCallback& callback) final;
        virtual void onBallMotion(const JoystickBall ball, const JoystickBallCallback& callback) final;

        // TODO

        void         anyJoystickEvent(const SDL_Event& event) const;
        virtual void defaultHandler() override;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_JOYSTICKINPUT_HPP
