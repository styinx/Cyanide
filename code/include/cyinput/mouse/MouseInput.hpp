#ifndef CYANIDE_MOUSEINPUT_HPP
#define CYANIDE_MOUSEINPUT_HPP

#include "cyinput/IInputDevice.hpp"
#include "cyinput/keyboard/Keys.hpp"
#include "cymath/Point.hpp"

namespace cyanide::cyinput
{

    class MouseInput
        : public IInputDevice
        , public std::enable_shared_from_this<MouseInput>
    {
    public:
        enum class MOUSE_EVENT : Byte
        {
            MOTION         = 0x01,
            BUTTON         = 0x02,
            BUTTON_DOWN    = 0x03,
            BUTTON_UP      = 0x04,
            BUTTON_PRESSED = 0x05,
            WHEEL_MOTION   = 0x06,
            ANY,
        };

        enum class MOUSE_BUTTON_STATE : Byte
        {
            NONE     = 0x00,
            RELEASED = 0x01,
            DOWN     = 0x02,
            PRESSED  = 0x04
        };

        using MouseButtonCode     = Uint8;
        using MouseButtonCallback = Function<void(const MouseButtonCode)>;
        using MouseMotionCallback = Function<void(const Sint32 x, const Sint32 y)>;
        using MouseWheelCallback  = Function<void(const Sint32 z)>;

    protected:
        static const UMap<String, MOUSE_EVENT> s_event;

        UMap<MouseButtonCode, MOUSE_BUTTON_STATE> m_button_states;
        cymath::Point                             m_mouse_position;

        UMap<MOUSE_EVENT, Vector<EventCallback>>           m_event_callbacks;
        Vector<MouseMotionCallback>                        m_motion_callbacks;
        UMap<MouseButtonCode, Vector<MouseButtonCallback>> m_button_event_callbacks;
        UMap<MouseButtonCode, Vector<MouseButtonCallback>> m_button_down_callbacks;
        UMap<MouseButtonCode, Vector<MouseButtonCallback>> m_button_up_callbacks;
        UMap<MouseButtonCode, Vector<MouseButtonCallback>> m_button_pressed_callbacks;
        Vector<MouseMotionCallback>                        m_wheel_motion_callbacks;

        MouseInput();

        void motion(const Sint32 x, const Sint32 y) const;
        void buttonEvent(const MouseButtonCode button) const;
        void buttonDown(const MouseButtonCode button) const;
        void buttonUp(const MouseButtonCode button) const;
        void buttonPressed(const MouseButtonCode button) const;
        void wheelMotion(const Sint32 x, const Sint32 y) const;

    public:
        virtual ~MouseInput() = default;

        MOUSE_BUTTON_STATE getButtonState(const MouseButtonCode button) const;

        virtual void on(const String& event, const EventCallback& callback) final;
        virtual void on(const MOUSE_EVENT event, const EventCallback& callback) final;
        virtual void onAnyMouseEvent(const EventCallback& callback) final;
        virtual void onMotion(const MouseMotionCallback& callback) final;
        virtual void onAnyButtonEvent(const EventCallback& callback) final;
        virtual void onButton(const MouseButtonCode button, const MouseButtonCallback& callback) final;
        virtual void onButtonDown(const MouseButtonCode button, const MouseButtonCallback& callback) final;
        virtual void onButtonUp(const MouseButtonCode button, const MouseButtonCallback& callback) final;
        virtual void onButtonPressed(const MouseButtonCode button, const MouseButtonCallback& callback) final;
        virtual void onWheelMotion(const MouseMotionCallback& callback) final;

        void anyMouseEvent(const SDL_Event& event) const;
        void defaultMouseHandler();
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_MOUSEINPUT_HPP
