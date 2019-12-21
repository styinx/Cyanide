#ifndef CYANIDE_SDLEVENTLOOP_HPP
#define CYANIDE_SDLEVENTLOOP_HPP

#include "cyinput/keyboard/SDLKey.hpp"
#include "cystd/stdPrototypes.hpp"

#include <SDL2/SDL_events.h>
#include <cymath/Point.hpp>
#include <functional>

namespace cyanide::cyinput
{
    class SDLEventLoop final
    {
    public:
        enum class LoopEvent : Byte
        {
            START = 0,
            BEGIN,
            END,
            STOP,
            SDL_EVENT_BEGIN,
            SDL_EVENT_END
        };

    private:
        using Callback            = Function<void(void)>;
        using MouseMotionCallback = Function<void(const Uint32 x, const Uint32 y)>;
        using KeyCode             = cyinput::KeyCode;
        using MouseButtonCode     = cyinput::MouseButtonCode;

        enum class SDLEventType : Uint16
        {
            SDL_NOEVENT         = 0x0000,
            SDL_APPEVENT        = 0x0100,
            SDL_MOBILEEVENT     = 0x0101,
            SDL_WINDOWEVENT     = 0x0200,
            SDL_SYSTEMEVENT     = 0x0201,
            SDL_KEYEVENT        = 0x0300,
            SDL_MOUSEEVENT      = 0x0400,
            SDL_CONTROLLEREVENT = 0x0600,
            SDL_TOUCHEVENT      = 0x0700,
            SDL_GESTUREEVENT    = 0x0800,
            SDL_CLIPBOARDEVENT  = 0x0900,
            SDL_DRAGDROPEVENT   = 0x1000,
            SDL_AUDIOEVENT      = 0x1100,
            SDL_RENDEREVENT     = 0x2000,
            SDL_USEREVENT       = 0x8000,
        };

        bool      m_running       = true;
        bool      m_system_events = true;
        SDL_Event m_event{};

        /*
         * Events
         */
        UMap<LoopEvent, Vector<Callback>>       m_loop_event_callback;
        UMap<Uint16, Vector<Callback>>          m_sdl_event_callback;
        UMap<KeyCode, Vector<Callback>>         m_key_event_callback;
        UMap<KeyCode, Vector<Callback>>         m_key_down_callback;
        UMap<KeyCode, Vector<Callback>>         m_key_up_callback;
        UMap<MouseButtonCode, Vector<Callback>> m_mouse_button_event_callback;
        UMap<MouseButtonCode, Vector<Callback>> m_mouse_button_down_callback;
        UMap<MouseButtonCode, Vector<Callback>> m_mouse_button_up_callback;
        Vector<MouseMotionCallback>             m_mouse_motion_callback;

        /*
         * Keyboard and mouse
         */
        UMap<KeyCode, KEY_STATE>                  m_keys;
        UMap<MouseButtonCode, MOUSE_BUTTON_STATE> m_mouse_buttons;
        cymath::Point                             m_mouse_position;

        void callLoopEvent(const LoopEvent event);
        void callSDLEvent(const Uint16 event);
        void callKeyEvent(const KeyCode key);
        void callKeyDown(const KeyCode key);
        void callKeyUp(const KeyCode key);
        void callMouseButtonEvent(const MouseButtonCode key);
        void callMouseButtonDown(const MouseButtonCode key);
        void callMouseButtonUp(const MouseButtonCode key);
        void callMouseMotion();

    public:
        SDLEventLoop();
        ~SDLEventLoop() = default;

        void run();

        /*
         * Loop callbacks
         */
        void onLoopEvent(const LoopEvent event, const Callback& callback);
        // Is triggered when the loop is about to start.
        void onLoopStart(const Callback& callback);
        // Is triggered on the beginning of each new loop iteration.
        void onLoopBegin(const Callback& callback);
        // Is triggered on the ending of each new loop iteration.
        void onLoopEnd(const Callback& callback);
        // Is triggered when the loop is about to stop.
        void onLoopStop(const Callback& callback);
        // Is triggered when any sdl event is received.
        void onAnySDLEventBegin(const Callback& callback);
        void onAnySDLEventEnd(const Callback& callback);

        /*
         * Input event callbacks
         */
        void onSDLEventType(const Uint16 type, const Callback& callback);
        void onAnyAppEvent(const Callback& callback);
        void onAnyWindowEvent(const Callback& callback);
        void onAnySystemEvent(const Callback& callback);
        void onAnyKeyEvent(const Callback& callback);
        void onKeyEvent(const KeyCode key, const Callback& callback);
        void onKeyDown(const KeyCode key, const Callback& callback);
        void onKeyUp(const KeyCode key, const Callback& callback);
        void onAnyMouseEvent(const Callback& callback);
        void onMouseButtonEvent(const MouseButtonCode button, const Callback& callback);
        void onMouseButtonDown(const MouseButtonCode button, const Callback& callback);
        void onMouseButtonUp(const MouseButtonCode button, const Callback& callback);
        void onMouseMotion(const MouseMotionCallback& callback);
    };
}  // namespace cyanide::cyinput

#endif  // CYANIDE_SDLEVENTLOOP_HPP
