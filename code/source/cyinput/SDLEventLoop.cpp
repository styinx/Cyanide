#include "cyinput/SDLEventLoop.hpp"

#include "cystd/Enum.hpp"

#include <SDL2/SDL_timer.h>

namespace cyanide::cyinput
{
    SDLEventLoop::SDLEventLoop()
    {
        // Set the key state based on the event.
        const auto setKeyState = [this]() {
            const auto key  = m_event.key.keysym.sym;
            const auto type = m_event.type;

            if(!m_keys.count(key))
            {
                m_keys[key] = KEY_STATE::NONE;
            }

            switch(type)
            {
            case SDL_KEYDOWN:
            {
                // If key is already down set the state to pressed.
                if(m_keys[key] == KEY_STATE::DOWN)
                {
                    m_keys[key] = KEY_STATE::PRESSED;
                }
                // If the key is not pressed or down set the status to down.
                else if(m_keys[key] != KEY_STATE::PRESSED)
                {
                    m_keys[key] = KEY_STATE::DOWN;
                }
                break;
            }
            case SDL_KEYUP:
            {
                m_keys[key] = KEY_STATE::RELEASED;
                break;
            }
            default:
            {
                m_keys[key] = KEY_STATE::NONE;
            }
            }
        };

        // Set the key state based on the event.
        const auto setMouseState = [this]() {
            const auto button = m_event.button.button;
            const auto motion = m_event.motion;
            const auto type   = m_event.type;

            if(!m_mouse_buttons.count(button))
            {
                m_mouse_buttons[button] = MOUSE_BUTTON_STATE::NONE;
            }

            switch(type)
            {
            case SDL_MOUSEBUTTONDOWN:
            {
                // If button is already down set the state to pressed.
                if(m_mouse_buttons[button] == MOUSE_BUTTON_STATE::DOWN)
                {
                    m_mouse_buttons[button] = MOUSE_BUTTON_STATE::PRESSED;
                }
                // If the button is not pressed or down set the status to down.
                else if(m_mouse_buttons[button] != MOUSE_BUTTON_STATE::PRESSED)
                {
                    m_mouse_buttons[button] = MOUSE_BUTTON_STATE::DOWN;
                }
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
                m_mouse_buttons[button] = MOUSE_BUTTON_STATE::RELEASED;
                break;
            }
            case SDL_MOUSEWHEEL:
            {
                // TODO
                break;
            }
            case SDL_MOUSEMOTION:
            {
                m_mouse_position.x = motion.x;
                m_mouse_position.y = motion.y;
                break;
            }
            default:
            {
                m_mouse_buttons[button] = MOUSE_BUTTON_STATE::NONE;
            }
            }
        };

        // Stop the loop if the close event is called.
        const auto exitLoop = [this]() {
            if(m_event.type == SDL_QUIT)
            {
                m_running = false;
            }
        };

        onAnyAppEvent(exitLoop);
        onAnyKeyEvent(setKeyState);
        onAnyMouseEvent(setMouseState);
    }

    // Private

    void SDLEventLoop::callLoopEvent(const LoopEvent event)
    {
        for(const auto& callback : m_loop_event_callback[event])
        {
            callback();
        }
    }

    void SDLEventLoop::callSDLEvent(const Uint16 event)
    {
        for(const auto& callback : m_sdl_event_callback[event])
        {
            callback();
        }
    }

    void SDLEventLoop::callKeyEvent(const KeyCode key)
    {
        for(const auto& callback : m_key_event_callback[key])
        {
            callback();
        }
    }

    void SDLEventLoop::callKeyDown(const SDLEventLoop::KeyCode key)
    {
        for(const auto& callback : m_key_down_callback[key])
        {
            callback();
        }
    }

    void SDLEventLoop::callKeyUp(const SDLEventLoop::KeyCode key)
    {
        for(const auto& callback : m_key_up_callback[key])
        {
            callback();
        }
    }

    void SDLEventLoop::callMouseButtonEvent(const MouseButtonCode key)
    {
        for(const auto& callback : m_mouse_button_event_callback[key])
        {
            callback();
        }
    }

    void SDLEventLoop::callMouseButtonDown(const MouseButtonCode key)
    {
        for(const auto& callback : m_mouse_button_down_callback[key])
        {
            callback();
        }
    }

    void SDLEventLoop::callMouseButtonUp(const MouseButtonCode key)
    {
        for(const auto& callback : m_mouse_button_up_callback[key])
        {
            callback();
        }
    }

    // Public

    void SDLEventLoop::run()
    {
        using cystd::fromEnum;

        const auto typeRange = [](const Uint32 sdlType, const SDLEventType from, const SDLEventType to) {
            return sdlType >= fromEnum(from) && sdlType < fromEnum(to);
        };

        callLoopEvent(LoopEvent::START);
        while(m_running)
        {
            callLoopEvent(LoopEvent::BEGIN);

            // Check if any events happened.
            while(SDL_PollEvent(&m_event))
            {
                callLoopEvent(LoopEvent::SDL_EVENT_BEGIN);

                const auto type = m_event.type;
                callSDLEvent(type);

                if(typeRange(type, SDLEventType::SDL_APPEVENT, SDLEventType::SDL_WINDOWEVENT))
                {
                    callSDLEvent(fromEnum(SDLEventType::SDL_APPEVENT));
                }
                else if(typeRange(type, SDLEventType::SDL_WINDOWEVENT, SDLEventType::SDL_KEYEVENT))
                {
                    callSDLEvent(fromEnum(SDLEventType::SDL_WINDOWEVENT));
                }
                else if(typeRange(type, SDLEventType::SDL_KEYEVENT, SDLEventType::SDL_MOUSEEVENT))
                {
                    callSDLEvent(fromEnum(SDLEventType::SDL_KEYEVENT));

                    const auto key = m_event.key.keysym.sym;
                    callKeyEvent(key);

                    if(type == SDL_KEYDOWN)
                    {
                        callKeyDown(key);
                    }
                    else if(type == SDL_KEYUP)
                    {
                        callKeyUp(key);
                    }
                }
                else if(typeRange(type, SDLEventType::SDL_MOUSEEVENT, SDLEventType::SDL_CONTROLLEREVENT))
                {
                    callSDLEvent(fromEnum(SDLEventType::SDL_MOUSEEVENT));

                    const auto button = m_event.button.button;
                    callMouseButtonEvent(button);

                    if(type == SDL_MOUSEBUTTONDOWN)
                    {
                        callMouseButtonDown(button);
                    }
                    else if(type == SDL_MOUSEBUTTONUP)
                    {
                        callMouseButtonUp(button);
                    }
                }
                else if(typeRange(type, SDLEventType::SDL_CONTROLLEREVENT, SDLEventType::SDL_TOUCHEVENT))
                {
                    callSDLEvent(fromEnum(SDLEventType::SDL_CONTROLLEREVENT));
                }

                callLoopEvent(LoopEvent::SDL_EVENT_END);
            }

            SDL_Delay(1);
            callLoopEvent(LoopEvent::END);
        }
        callLoopEvent(LoopEvent::STOP);
    }

    void SDLEventLoop::onLoopEvent(const LoopEvent event, const SDLEventLoop::Callback& callback)
    {
        m_loop_event_callback[event].emplace_back(callback);
    }

    void SDLEventLoop::onLoopStart(const Callback& callback)
    {
        onLoopEvent(LoopEvent::START, callback);
    }

    void SDLEventLoop::onLoopBegin(const Callback& callback)
    {
        onLoopEvent(LoopEvent::BEGIN, callback);
    }

    void SDLEventLoop::onLoopEnd(const Callback& callback)
    {
        onLoopEvent(LoopEvent::END, callback);
    }

    void SDLEventLoop::onLoopStop(const Callback& callback)
    {
        onLoopEvent(LoopEvent::STOP, callback);
    }

    void SDLEventLoop::onAnySDLEventBegin(const SDLEventLoop::Callback& callback)
    {
        onLoopEvent(LoopEvent::SDL_EVENT_BEGIN, callback);
    }

    void SDLEventLoop::onAnySDLEventEnd(const SDLEventLoop::Callback& callback)
    {
        onLoopEvent(LoopEvent::SDL_EVENT_END, callback);
    }

    void SDLEventLoop::onSDLEventType(const Uint16 type, const SDLEventLoop::Callback& callback)
    {
        m_sdl_event_callback[type].emplace_back(callback);
    }

    void SDLEventLoop::onAnyAppEvent(const SDLEventLoop::Callback& callback)
    {
        onSDLEventType(cystd::fromEnum(SDLEventType::SDL_APPEVENT), callback);
    }

    void SDLEventLoop::onAnyKeyEvent(const SDLEventLoop::Callback& callback)
    {
        onSDLEventType(cystd::fromEnum(SDLEventType::SDL_KEYEVENT), callback);
    }

    void SDLEventLoop::onAnyMouseEvent(const cyanide::cyinput::SDLEventLoop::Callback& callback)
    {
        onSDLEventType(cystd::fromEnum(SDLEventType::SDL_MOUSEEVENT), callback);
    }

    void SDLEventLoop::onKeyEvent(const KeyCode key, const SDLEventLoop::Callback& callback)
    {
        m_key_event_callback[key].emplace_back(callback);
    }

    void SDLEventLoop::onKeyDown(const KeyCode key, const SDLEventLoop::Callback& callback)
    {
        m_key_down_callback[key].emplace_back(callback);
    }

    void SDLEventLoop::onKeyUp(const KeyCode key, const SDLEventLoop::Callback& callback)
    {
        m_key_up_callback[key].emplace_back(callback);
    }

    void
    SDLEventLoop::onMouseButtonEvent(const MouseButtonCode button, const SDLEventLoop::Callback& callback)
    {
        m_mouse_button_event_callback[button].emplace_back(callback);
    }

    void
    SDLEventLoop::onMouseButtonDown(const MouseButtonCode button, const SDLEventLoop::Callback& callback)
    {
        m_mouse_button_down_callback[button].emplace_back(callback);
    }

    void
    SDLEventLoop::onMouseButtonUp(const MouseButtonCode button, const SDLEventLoop::Callback& callback)
    {
        m_mouse_button_up_callback[button].emplace_back(callback);
    }

    void SDLEventLoop::onAnyWindowEvent(const Callback& callback)
    {
        onSDLEventType(cystd::fromEnum(SDLEventType::SDL_WINDOWEVENT), callback);
    }

}  // namespace cyanide::cyinput
