#include "cyvideo/display/SDLDisplay.hpp"

#include "cyvideo/SDLVideo.hpp"

namespace cyanide::cyvideo
{

    Uint32 SDLDisplay::s_display_index = 0;

    SDLDisplay::SDLDisplay()
        : m_index(s_display_index++)
    {
        m_mode = SDLVideo::getCurrentDesktopDisplayMode(m_index);
    }

    cymath::Size SDLDisplay::getDisplaySize() const
    {
        return cymath::Size(m_mode->w, m_mode->h);
    }

    Uint32 SDLDisplay::getRefreshrate() const
    {
        return static_cast<Uint32>(m_mode->refresh_rate);
    }

}  // namespace cyanide
