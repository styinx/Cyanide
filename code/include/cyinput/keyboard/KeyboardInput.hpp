#ifndef CYANIDE_KEYBOARDINPUT_HPP
#define CYANIDE_KEYBOARDINPUT_HPP

#include "cyinput/IInputDevice.hpp"
#include "cyinput/keyboard/Keys.hpp"

namespace cyanide::cyinput
{

    class KeyboardInput
        : public IInputDevice
        , public std::enable_shared_from_this<KeyboardInput>
    {
    public:
        enum class KEYBOARD_EVENT : Byte
        {
            NONE    = 0x00,
            DOWN    = 0x01,
            UP      = 0x02,
            PRESSED = 0x04,
            ANY     = 0x07,
        };

        enum class KEY_STATE : Byte
        {
            NONE     = 0x00,
            RELEASED = 0x01,
            DOWN     = 0x02,
            PRESSED  = 0x04,
            ANY      = 0x07
        };

        using KeyCode     = Uint16;
        using KeyCallback = Function<void(const KeyCode)>;

    protected:
        static const UMap<String, KEYBOARD_EVENT> s_event;

        UMap<KeyCode, KEY_STATE> m_keys_states;

        UMap<KEYBOARD_EVENT, Vector<EventCallback>> m_event_callbacks;
        UMap<KeyCode, Vector<KeyCallback>>          m_key_event_callbacks;
        UMap<KeyCode, Vector<KeyCallback>>          m_key_down_callbacks;
        UMap<KeyCode, Vector<KeyCallback>>          m_key_up_callbacks;
        UMap<KeyCode, Vector<KeyCallback>>          m_key_pressed_callbacks;

        KeyboardInput();

        virtual void keyEvent(const KeyCode key) const final;
        virtual void keyDown(const KeyCode key) const final;
        virtual void keyUp(const KeyCode key) const final;
        virtual void keyPressed(const KeyCode key) const final;

    public:
        virtual ~KeyboardInput() = default;

        KEY_STATE getKeyState(const KeyCode key) const;

        virtual void on(const String& event, const EventCallback& callback) final;
        virtual void on(const KEYBOARD_EVENT event, const EventCallback& callback) final;
        virtual void on(const String& event, const KeyCode key, const KeyCallback& callback) final;
        virtual void on(const KEYBOARD_EVENT event, const KeyCode key, const KeyCallback& callback) final;
        virtual void onAnyKeyEvent(const EventCallback& callback) final;
        virtual void onKey(const KeyCode key, const KeyCallback& callback) final;
        virtual void onKeyDown(const KeyCode key, const KeyCallback& callback) final;
        virtual void onKeyUp(const KeyCode key, const KeyCallback& callback) final;
        virtual void onKeyPressed(const KeyCode key, const KeyCallback& callback) final;

        virtual void anyKeyEvent(const SDL_Event& event) const final;
        virtual void defaultHandler() override;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_KEYBOARDINPUT_HPP
