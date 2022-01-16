#ifndef CYANIDE_SDLDISPLAY_HPP
#define CYANIDE_SDLDISPLAY_HPP

#include "IDisplay.hpp"
#include "cymath/Size.hpp"

#include <SDL2/SDL_video.h>

namespace cyanide::cyvideo
{

    class SDLDisplay final : public IDisplay
    {
    private:
        static Uint32    s_display_index;
        Uint32           m_index = 0;
        SDL_DisplayMode* m_mode  = nullptr;

    public:
        SDLDisplay();
        ~SDLDisplay() = default;
        cymath::Size getDisplaySize() const;
        Uint32       getRefreshrate() const;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLDISPLAY_HPP
