#include "cyvideo/SDLSurface.hpp"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN

const Uint32 R_MASK = 0xff000000;
const Uint32 G_MASK = 0x00ff0000;
const Uint32 B_MASK = 0x0000ff00;
const Uint32 A_MASK = 0x000000ff;

#elif SDL_BYTEORDER == SDL_LIL_ENDIAN

const Uint32 R_MASK = 0x000000ff;
const Uint32 G_MASK = 0x0000ff00;
const Uint32 B_MASK = 0x00ff0000;
const Uint32 A_MASK = 0xff000000;

#endif

namespace cyanide::cyvideo
{
    SDLSurface::SDLSurface(SDL_Surface* surface)
    {
        if(surface != nullptr)
        {
            m_surface = surface;
        }
    }

    SDLSurface::SDLSurface(const cymath::Size& size)
        : m_size(size)
    {
        const int depth = sizeof(Uint32);

        m_surface = SDL_CreateRGBSurface(0, size.width, size.height, depth, R_MASK, G_MASK, B_MASK, A_MASK);
    }

    SDLSurface::~SDLSurface()
    {
        SDL_FreeSurface(m_surface);
    }

    SDL_Surface* SDLSurface::getSurface() const
    {
        return m_surface;
    }

    cymath::Size SDLSurface::getSize() const
    {
        return m_size;
    }

}  // namespace cyanide::cyvideo
