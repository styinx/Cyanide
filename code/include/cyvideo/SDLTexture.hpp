#ifndef CYANIDE_SDLTEXTURE_HPP
#define CYANIDE_SDLTEXTURE_HPP

#include "cymath/Size.hpp"
#include "cyvideo/ITexture.hpp"
#include "cyvideo/videoPrototypes.hpp"

#include <SDL2/SDL_render.h>

namespace cyanide::cyvideo
{

    namespace Default
    {
        const int TEXTURE_FORMAT = SDL_PIXELFORMAT_RGBA32;
        const int TEXTURE_ACCESS = SDL_TEXTUREACCESS_TARGET;
    }  // namespace Default

    class SDLTexture final : public ITexture
    {
    private:
        SDL_Texture* m_texture = nullptr;
        Uint32       m_format  = Default::TEXTURE_FORMAT;
        int          m_access  = Default::TEXTURE_ACCESS;
        cymath::Size m_size    = {0, 0};

        void loadTextureInfo();

    public:
        explicit SDLTexture(const SDLRendererSPtr& renderer, const SDLSurfaceSPtr& surface);
        explicit SDLTexture(const SDLRendererSPtr& renderer, const cymath::Size& size);
        ~SDLTexture() override;

        void         createTexture(const SDLRendererSPtr& renderer, const SDLSurfaceSPtr& surface);
        SDL_Texture* getTexture() const;
        cymath::Size getSize() const;

        void          setBlendMode(const SDL_BlendMode mode);
        SDL_BlendMode getBlendMode() const;
        void          setAlphaMod(const Uint8 alpha);
        Uint8         getAlphaMod() const;
        void          setColorMod(const SDL_Color color);
        SDL_Color     getColorMod() const;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLTEXTURE_HPP
