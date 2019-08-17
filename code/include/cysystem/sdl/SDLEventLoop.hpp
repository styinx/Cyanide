#ifndef CYANIDE_SDLEVENTLOOP_HPP
#define CYANIDE_SDLEVENTLOOP_HPP

#include "cystd/stdPrototypes.hpp"

#include <SDL2/SDL_events.h>
#include <functional>

namespace cyanide::cysystem
{
    class SDLEventLoop final
    {
    private:
        using Callback = std::function<void(void)>;

        bool                                m_running = true;
        SDL_Event                           m_event{};
        UMap<Uint16, std::vector<Callback>> m_callback;

        void call(const Uint16& event);

    public:
        SDLEventLoop()  = default;
        ~SDLEventLoop() = default;

        void run();
        void onWindowEvent(const Callback& callback);
    };
}  // namespace cyanide::cysystem

#endif  // CYANIDE_SDLEVENTLOOP_HPP
