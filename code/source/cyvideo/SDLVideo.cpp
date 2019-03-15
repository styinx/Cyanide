
#include <cyvideo/SDLVideo.hpp>

namespace cyanide
{
namespace cyvideo
{

    SDL_DisplayMode SDLVideo::getDisplayMode()
    {
        return SDL_DisplayMode();
    }

    SDL_DisplayMode SDLVideo::getClosestDisplayMode()
    {
        return SDL_DisplayMode();
    }

    SDL_DisplayMode SDLVideo::getDesktopDisplayMode()
    {
        return SDL_DisplayMode();
    }

    Uint32 SDLVideo::getNumberOfDisplayModes(const Uint32 display_id)
    {
        int display_modes = SDL_GetNumDisplayModes(display_id);

        if(display_modes > 0)
            return static_cast<Uint32>(display_modes);
        else
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

    String SDLVideo::getVideoDriverName(const Uint32 id)
    {
        return String(SDL_GetVideoDriver(id));
    }

    String SDLVideo::getCurrentVideoDriverName()
    {
        return String(SDL_GetCurrentVideoDriver());
    }

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

}
}  // namespace cyanide