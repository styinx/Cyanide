#include "cysystem/sdl/SDLEventLoop.hpp"

#include <SDL2/SDL_timer.h>

namespace cyanide::cysystem
{

    void SDLEventLoop::call(const Uint16& event)
    {
        for(auto callback : m_callback[event])
        {
            callback();
        }
    }

    // Public

    void SDLEventLoop::run()
    {
        while(m_running)
        {
            while(SDL_PollEvent(&m_event))
            {
                if(m_event.type == SDL_QUIT)
                {
                    m_running = false;
                }
                else if(m_event.type == SDL_WINDOWEVENT)
                {
                }
            }
            SDL_Delay(1);
        }
    }

    void SDLEventLoop::onWindowEvent(const Callback& callback)
    {
        m_callback[SDL_WINDOWEVENT].emplace_back(callback);
    }

}