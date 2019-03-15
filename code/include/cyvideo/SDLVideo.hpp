#ifndef CYANIDE_SDLVIDEO_HPP
#define CYANIDE_SDLVIDEO_HPP

#include <SDL2/SDL_video.h>

#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"
#include "cystd/stdPrototypes.hpp"

namespace cyanide
{
namespace cyvideo
{

    class SDLVideo
        : public cystd::NonCopyable
        , public cystd::NonMoveable
    {
    public:
        static SDL_DisplayMode getDisplayMode();
        static SDL_DisplayMode getClosestDisplayMode();
        static SDL_DisplayMode getDesktopDisplayMode();
        static Uint32          getNumberOfDisplayModes(const Uint32 display_id);
        static Uint32          getNumberOfVideoDisplays();
        static Uint32          getVideoDriverId(const String name);
        static String          getVideoDriverName(const Uint32 id);
        static String          getCurrentVideoDriverName();
        static Uint32          getNumberOfVideoDrivers();
        static List<String>    getVideoDriverNames();
    };

}  // namespace cyvideo
}  // namespace cyanide

#endif  // CYANIDE_SDLVIDEO_HPP
