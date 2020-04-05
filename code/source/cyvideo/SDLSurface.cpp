#include "cyvideo/SDLSurface.hpp"

#include <SDL2/SDL_image.h>

#if SDL_BYTEORDER == SDL_BIG_ENDIAN

const Uint32 R_MASK = 0xff000000;
const Uint32 G_MASK = 0x00Ff0000;
const Uint32 B_MASK = 0x0000Ff00;
const Uint32 A_MASK = 0x000000Ff;

#elif SDL_BYTEORDER == SDL_LIL_ENDIAN

const Uint32 R_MASK = 0x000000Ff;
const Uint32 G_MASK = 0x0000Ff00;
const Uint32 B_MASK = 0x00Ff0000;
const Uint32 A_MASK = 0xff000000;

#endif

namespace cyanide::cyvideo
{

    SDLSurface::SDLSurface(const String& filename)
    {
        m_surface = IMG_Load(filename.c_str());
    }

    SDLSurface::SDLSurface(SDL_Surface* surface)
    {
        if(surface != nullptr)
        {
            m_surface = surface;
            m_size    = {m_surface->w, m_surface->h};
        }
    }

    SDLSurface::SDLSurface(const cymath::Size& size)
        : m_size(size)
    {
        const int depth = sizeof(Uint32);

        m_surface =
            SDL_CreateRGBSurface(0, size.width, size.height, depth, R_MASK, G_MASK, B_MASK, A_MASK);
    }

    SDLSurface::~SDLSurface()
    {
        SDL_FreeSurface(m_surface);
    }

    // Private

    void SDLSurface::loadSurfaceInfo()
    {
    }

    // Public

    SDL_Surface* SDLSurface::getSurface() const
    {
        return m_surface;
    }

    cymath::Size SDLSurface::getSize() const
    {
        return m_size;
    }

    void SDLSurface::setColorKey(const Uint32 key) const
    {
    }

    Uint32 SDLSurface::getColorKey() const
    {
        return 0;
    }

    void SDLSurface::setAlphaMod(const Uint8 alpha) const
    {
    }

    Uint8 SDLSurface::getAlphaMod() const
    {
        return 0;
    }

    void SDLSurface::setBlendMode(const SDL_BlendMode mode) const
    {
        SDL_SetSurfaceBlendMode(m_surface, mode);
    }

    SDL_BlendMode SDLSurface::getBlendMode() const
    {
        SDL_BlendMode mode;
        SDL_GetSurfaceBlendMode(m_surface, &mode);
        return mode;
    }

    void SDLSurface::setColorMod(const SDL_Color& color) const
    {
        SDL_SetSurfaceColorMod(m_surface, color.r, color.g, color.b);
    }

    SDL_Color SDLSurface::getColorMod() const
    {
        SDL_Color color;
        SDL_GetSurfaceColorMod(m_surface, &color.r, &color.g, &color.b);
        return color;
    }

}  // namespace cyanide::cyvideo
