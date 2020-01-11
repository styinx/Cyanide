
#include "cyvideo/SDLVideo.hpp"

#include <iostream>

namespace cyanide::cyvideo
{

    SDL_DisplayMode* SDLVideo::getDesktopDisplayModeById(const Uint32 display_id, const Uint32 mode_id)
    {
        SDL_DisplayMode* mode = nullptr;
        if(display_id < SDLVideo::getNumberOfVideoDisplays() && mode_id < SDLVideo::getNumberOfDisplayModes(display_id))
        {
            if(SDL_GetDisplayMode(display_id, mode_id, mode) == 0)
            {
                //Todo
            }
        }
        return mode;
    }

    SDL_DisplayMode* SDLVideo::getCurrentDesktopDisplayMode(const Uint32 display_id)
    {
        SDL_DisplayMode* current = nullptr;

        if(display_id < SDLVideo::getNumberOfVideoDisplays())
        {
            if(SDL_GetCurrentDisplayMode(display_id, current) != 0)
            {
                std::cout << SDL_GetError() << "error\n";
            }
            std::cout << SDL_GetError() << "\n";
        }
        return current;
    }

    SDL_DisplayMode* SDLVideo::getClosestDesktopDisplayMode(const Uint32 display_id, const SDL_DisplayMode* mode)
    {
        SDL_DisplayMode* closest = nullptr;

        if(display_id < SDLVideo::getNumberOfVideoDisplays())
        {
            if(SDL_GetClosestDisplayMode(display_id, mode, closest) != nullptr)
            {
                //todo
            }
        }
        return closest;
    }

    SDL_DisplayMode* SDLVideo::getDesktopDisplayMode(const Uint32 display_id)
    {
        SDL_DisplayMode* mode = nullptr;
        if(display_id < SDLVideo::getNumberOfVideoDisplays())
        {
            if(SDL_GetDesktopDisplayMode(display_id, mode) == 0)
            {
                //todo
            }
        }
        return mode;
    }

    Uint32 SDLVideo::getNumberOfDisplayModes(const Uint32 display_id)
    {
        if(display_id < SDLVideo::getNumberOfVideoDisplays())
        {
            int display_modes = SDL_GetNumDisplayModes(display_id);

            if(display_modes > 0)
                return static_cast<Uint32>(display_modes);
        }
        return 0;
    }

    Uint32 SDLVideo::getNumberOfVideoDisplays()
    {
        int video_displays = SDL_GetNumVideoDisplays();

        if(video_displays > 0)
            return static_cast<Uint32>(video_displays);
        else
            return 0;
    }

    Uint32 SDLVideo::getVideoDriverId(const String name)
    {
        // TODO
        return 0;
    }

    String SDLVideo::getVideoDriverName(const Uint32 id) { return String(SDL_GetVideoDriver(id)); }

    String SDLVideo::getCurrentVideoDriverName() { return String(SDL_GetCurrentVideoDriver()); }

    Uint32 SDLVideo::getNumberOfVideoDrivers()
    {
        int video_drivers = SDL_GetNumVideoDrivers();

        if(video_drivers > 0)
            return static_cast<Uint32>(video_drivers);
        else
            return 0;
    }

    List<String> SDLVideo::getVideoDriverNames()
    {
        List<String> video_drivers;

        for(Uint32 id = 0; id < SDLVideo::getNumberOfVideoDrivers(); ++id)
        {
            video_drivers.emplace_back(SDLVideo::getVideoDriverName(id));
        }

        return video_drivers;
    }

}  // namespace cyanide
