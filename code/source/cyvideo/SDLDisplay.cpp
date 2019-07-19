#include "cyvideo/SDLDisplay.hpp"

#include "cyvideo/SDLVideo.hpp"

namespace cyanide
{
namespace cyvideo
{

    Uint32 SDLDisplay::display_index = 0;

    SDLDisplay::SDLDisplay()
        : index(display_index++)
    {
        mode = SDLVideo::getCurrentDesktopDisplayMode(index);
    }

    cymath::Size SDLDisplay::getDisplaySize() const
    {
        return cymath::Size(mode->w, mode->h);
    }

    Uint32 SDLDisplay::getRefreshrate() const
    {
        return static_cast<Uint32>(mode->refresh_rate);
    }

}  // namespace cyvideo
}  // namespace cyanide