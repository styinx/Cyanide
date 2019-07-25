#ifndef CYANIDE_SDLTEXTURE_HPP
#define CYANIDE_SDLTEXTURE_HPP

#include "cyvideo/ITexture.hpp"

#include "cyvideo/videoPrototypes.hpp"
#include "cymath/Size.hpp"

#include <SDL2/SDL_render.h>

namespace cyanide::cyvideo
{

    class SDLTexture final : public ITexture
    {
    private:
        SDL_Texture* m_texture = nullptr;
        cymath::Size m_size = {};

    public:
        explicit SDLTexture(const SDLRendererSPtr& renderer, const cymath::Size& size);
        ~SDLTexture() override;

        SDL_Texture* getTexture() const;
        cymath::Size getSize() const;

        void setBlendMode(const SDL_BlendMode mode);
        SDL_BlendMode getBlendMode() const;
        void setAlphaMod(const Uint8 alpha);
        Uint8 getAlphaMod() const;
        void setColorMod(const SDL_Color color);
        SDL_Color getColorMod() const;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLTEXTURE_HPP
