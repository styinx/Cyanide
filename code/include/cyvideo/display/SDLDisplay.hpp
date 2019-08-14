#ifndef CYANIDE_SDLDISPLAY_HPP
#define CYANIDE_SDLDISPLAY_HPP

#include "IDisplay.hpp"

#include <SDL2/SDL_video.h>

#include "cymath/Size.hpp"

namespace cyanide::cyvideo
{

    class SDLDisplay final : public IDisplay
    {
    private:
        static Uint32 display_index;
        Uint32 index = 0;
        SDL_DisplayMode* mode = nullptr;

    public:
        SDLDisplay();
        ~SDLDisplay() = default;
        cymath::Size getDisplaySize() const;
        Uint32 getRefreshrate() const;
    };

}  // namespace cyanide

#endif  // CYANIDE_SDLDISPLAY_HPP
