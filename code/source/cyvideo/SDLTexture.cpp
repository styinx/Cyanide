#include "cyvideo/SDLTexture.hpp"

#include "cyvideo/SDLRenderer.hpp"

namespace cyanide::cyvideo
{
    SDLTexture::SDLTexture(const SDLRendererSPtr& renderer, const cymath::Size& size)
        : m_size(size)
    {
        const int format = SDL_PIXELFORMAT_RGBA32;
        const int access = SDL_TEXTUREACCESS_TARGET;

        SDL_CreateTexture(renderer->getRenderer(), format, access, size.width, size.height);
    }

    SDLTexture::~SDLTexture()
    {
        SDL_DestroyTexture(m_texture);
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
}
