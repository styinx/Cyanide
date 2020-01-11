#include "cyinput/SDLEventLoop.hpp"

#include "cystd/Enum.hpp"

#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_syswm.h>
#include <iostream>

namespace cyanide::cyinput
{
    SDLEventLoop::SDLEventLoop()
        : m_keyboard(std::make_shared<Keyboard>())
        , m_mouse(std::make_shared<Mouse>())
    {
        // Stop the loop if the close event is called.
        const auto exitLoop = [this]() {
            if(m_event.type == SDL_QUIT)
            {
                m_running = false;
            }
        };

        onAnyAppEvent(exitLoop);

        m_keyboard->defaultKeyboardHandler();
        m_mouse->defaultMouseHandler();
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

                if(m_system_events)
                {
                    if(m_event.type == SDL_SYSWMEVENT)
                    {
                        //TODO
                    }
                }

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
                    m_keyboard->anyKeyEvent(m_event);
                }
                else if(typeRange(type, SDLEventType::SDL_MOUSEEVENT, SDLEventType::SDL_CONTROLLEREVENT))
                {
                    m_mouse->anyMouseEvent(m_event);
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

    SharedPtr<Keyboard>& SDLEventLoop::keyboard()
    {
        return m_keyboard;
    }

    SharedPtr<Mouse>& SDLEventLoop::mouse()
    {
        return m_mouse;
    }

    /*
     * Loop callbacks
     */

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

    /*
     * Input event callbacks
     */

    void SDLEventLoop::onSDLEventType(const Uint16 type, const SDLEventLoop::Callback& callback)
    {
        m_sdl_event_callback[type].emplace_back(callback);
    }

    void SDLEventLoop::onAnyAppEvent(const SDLEventLoop::Callback& callback)
    {
        onSDLEventType(cystd::fromEnum(SDLEventType::SDL_APPEVENT), callback);
    }

    void SDLEventLoop::onAnyWindowEvent(const Callback& callback)
    {
        onSDLEventType(cystd::fromEnum(SDLEventType::SDL_WINDOWEVENT), callback);
    }

    void SDLEventLoop::onAnySystemEvent(const cyanide::cyinput::SDLEventLoop::Callback& callback)
    {
        onSDLEventType(cystd::fromEnum(SDLEventType::SDL_SYSTEMEVENT), callback);
    }

}  // namespace cyanide::cyinput
