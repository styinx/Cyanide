#include "cyinput/SDLEventLoop.hpp"

#include "cystd/Enum.hpp"

#include <SDL2/SDL_syswm.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

namespace cyanide::cyinput
{
    SDLEventLoop::SDLEventLoop()
        : m_keyboard(std::make_shared<Keyboard>())
        , m_mouse(std::make_shared<Mouse>())
    {
        m_keyboard->defaultHandler();
        m_mouse->defaultHandler();

        for(Uint8 id = 0; id < SDL_NumJoysticks(); ++id)
        {
            switch(SDL_JoystickGetDeviceType(id))
            {
            case SDL_JOYSTICK_TYPE_GAMECONTROLLER:
            {
                const auto controller = std::make_shared<Controller>(id);
                m_controllers.emplace_back(controller);
                controller->defaultHandler();
                break;
            }
            case SDL_JOYSTICK_TYPE_UNKNOWN:
            case SDL_JOYSTICK_TYPE_WHEEL:
            case SDL_JOYSTICK_TYPE_ARCADE_STICK:
            case SDL_JOYSTICK_TYPE_FLIGHT_STICK:
            case SDL_JOYSTICK_TYPE_DANCE_PAD:
            case SDL_JOYSTICK_TYPE_GUITAR:
            case SDL_JOYSTICK_TYPE_DRUM_KIT:
            case SDL_JOYSTICK_TYPE_ARCADE_PAD:
            case SDL_JOYSTICK_TYPE_THROTTLE:
            default:
                const auto joystick = std::make_shared<Joystick>(id);
                m_joysticks.emplace_back(joystick);
                joystick->defaultHandler();
            }
        }

        // Stop the loop if the close event is called.
        const auto exitLoop = [this]() {
            if(m_event.type == SDL_QUIT)
            {
                m_running = false;
            }
        };

        onAnyAppEvent(exitLoop);
    }

    // Private

    void SDLEventLoop::callLoopEvent(const LoopEvent type, const SDL_Event& event)
    {
        for(const auto& callback : m_loop_event_callback[type])
        {
            callback(event);
        }
    }

    void SDLEventLoop::callSDLEvent(const Uint16 type)
    {
        for(const auto& callback : m_sdl_event_callback[type])
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

        callLoopEvent(LoopEvent::START, m_event);
        while(m_running)
        {
            callLoopEvent(LoopEvent::BEGIN, m_event);

            // Check if any events happened.
            while(SDL_PollEvent(&m_event))
            {
                callLoopEvent(LoopEvent::SDL_EVENT_BEGIN, m_event);

                const auto type = m_event.type;
                callSDLEvent(type);

                if(m_system_events)
                {
                    if(m_event.type == SDL_SYSWMEVENT)
                    {
                        // TODO
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
                else if(typeRange(type, SDLEventType::SDL_MOUSEEVENT, SDLEventType::SDL_JOYSTICKEVENT))
                {
                    m_mouse->anyMouseEvent(m_event);
                }
                else if(typeRange(
                            type, SDLEventType::SDL_JOYSTICKEVENT, SDLEventType::SDL_CONTROLLEREVENT))
                {
                    for(const auto& joystick : m_joysticks)
                    {
                        joystick->anyJoystickEvent(m_event);
                    }
                }
                else if(typeRange(type, SDLEventType::SDL_CONTROLLEREVENT, SDLEventType::SDL_TOUCHEVENT))
                {
                    for(const auto& controller : m_controllers)
                    {
                        controller->anyControllerEvent(m_event);
                    }
                }

                callLoopEvent(LoopEvent::SDL_EVENT_END, m_event);
            }

            SDL_Delay(1);
            callLoopEvent(LoopEvent::END, m_event);
        }
        callLoopEvent(LoopEvent::STOP, m_event);
    }

    SharedPtr<Keyboard>& SDLEventLoop::keyboard()
    {
        return m_keyboard;
    }

    SharedPtr<Mouse>& SDLEventLoop::mouse()
    {
        return m_mouse;
    }

    SharedPtr<Joystick>& SDLEventLoop::joystick(const Uint8 id)
    {
        if(id < m_joysticks.size())
        {
            return m_joysticks.at(id);
        }
        return m_joysticks.front();
    }

    SharedPtr<Controller>& SDLEventLoop::controller(const Uint8 id)
    {
        if(id < m_controllers.size())
        {
            return m_controllers.at(id);
        }
        return m_controllers.front();
    }

    /*
     * Loop callbacks
     */

    void SDLEventLoop::onLoopEvent(const LoopEvent event, const EventCallback& callback)
    {
        m_loop_event_callback[event].emplace_back(callback);
    }

    void SDLEventLoop::onLoopStart(const EventCallback& callback)
    {
        onLoopEvent(LoopEvent::START, callback);
    }

    void SDLEventLoop::onLoopBegin(const EventCallback& callback)
    {
        onLoopEvent(LoopEvent::BEGIN, callback);
    }

    void SDLEventLoop::onLoopEnd(const EventCallback& callback)
    {
        onLoopEvent(LoopEvent::END, callback);
    }

    void SDLEventLoop::onLoopStop(const EventCallback& callback)
    {
        onLoopEvent(LoopEvent::STOP, callback);
    }

    void SDLEventLoop::onAnySDLEventBegin(const EventCallback& callback)
    {
        onLoopEvent(LoopEvent::SDL_EVENT_BEGIN, callback);
    }

    void SDLEventLoop::onAnySDLEventEnd(const EventCallback& callback)
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
