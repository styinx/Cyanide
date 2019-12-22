#ifndef CYANIDE_IINPUTDEVICE_HPP
#define CYANIDE_IINPUTDEVICE_HPP

#include "cystd/stdPrototypes.hpp"

#include <SDL2/SDL_events.h>

namespace cyanide::cyinput
{

    class IInputDevice
    {
    public:
        using Callback = Function<void(void)>;
        using EventCallback = Function<void(const SDL_Event& event)>;

//        virtual void on(const String& event, const EventCallback& callback) = 0;
    };

} // namespace cyanide::cyinput

#endif  // CYANIDE_IINPUTDEVICE_HPP
