#include "cyvideo/SDLTexture.hpp"

#include "SDL2/SDL_render.h"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/SDLSurface.hpp"

namespace cyanide::cyvideo
{
    SDLTexture::SDLTexture(const SDLRendererSPtr& renderer, const SDLSurfaceSPtr& surface)
    {
        createTexture(renderer, surface);
    }

    SDLTexture::SDLTexture(const SDLRendererSPtr& renderer, const cymath::Size& size)
        : m_size(size)
    {
        createTexture(renderer, nullptr);
    }

    SDLTexture::~SDLTexture()
    {
        SDL_DestroyTexture(m_texture);
    }

    // Private

    void SDLTexture::loadTextureInfo()
    {
        if(m_texture != nullptr)
        {
            SDL_QueryTexture(m_texture, &m_format, &m_access, &m_size.width, &m_size.height);
        }
    }

    // Public

    void SDLTexture::createTexture(
        const cyanide::cyvideo::SDLRendererSPtr& renderer,
        const cyanide::cyvideo::SDLSurfaceSPtr&  surface)
    {
        if(surface != nullptr)
        {
            m_texture = SDL_CreateTextureFromSurface(renderer->getRenderer(), surface->getSurface());
        }
        else
        {
            m_texture = SDL_CreateTexture(
                renderer->getRenderer(), m_format, m_access, m_size.width, m_size.height);
        }
        loadTextureInfo();
    }

    SDL_Texture* SDLTexture::getTexture() const
    {
        return m_texture;
    }

    cymath::Size SDLTexture::getSize() const
    {
        return m_size;
    }

    void SDLTexture::setBlendMode(const SDL_BlendMode mode)
    {
        SDL_SetTextureBlendMode(m_texture, mode);
    }

    SDL_BlendMode SDLTexture::getBlendMode() const
    {
        SDL_BlendMode mode;
        SDL_GetTextureBlendMode(m_texture, &mode);
        return mode;
    }

    void SDLTexture::setAlphaMod(Uint8 alpha_mod)
    {
        SDL_SetTextureAlphaMod(m_texture, alpha_mod);
    }

    Uint8 SDLTexture::getAlphaMod() const
    {
        Uint8 mod;
        SDL_GetTextureAlphaMod(m_texture, &mod);
        return mod;
    }

    void SDLTexture::setColorMod(SDL_Color color_mod)
    {
        SDL_SetTextureColorMod(m_texture, color_mod.r, color_mod.g, color_mod.r);
    }

    SDL_Color SDLTexture::getColorMod() const
    {
        SDL_Color mod;
        SDL_GetTextureColorMod(m_texture, &mod.r, &mod.g, &mod.b);
        return mod;
    }
}  // namespace cyanide::cyvideo
