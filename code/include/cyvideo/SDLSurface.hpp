#ifndef CYANIDE_SDLSURFACE_HPP
#define CYANIDE_SDLSURFACE_HPP

#include "cymath/Size.hpp"
#include "cyvideo/ISurface.hpp"

#include <SDL2/SDL_surface.h>

namespace cyanide::cyvideo
{

    /**
     * @brief Manages the lifetime of a SDL_Surface.
     */
    class SDLSurface final : public ISurface
    {
    private:
        SDL_Surface* m_surface = nullptr;
        cymath::Size m_size{0, 0};

        SDLSurface() = default;
        void loadSurfaceInfo();

    public:
        explicit SDLSurface(const String& filename);
        explicit SDLSurface(SDL_Surface* surface);
        explicit SDLSurface(const cymath::Size& size);
        ~SDLSurface() override;

        SDL_Surface* getSurface() const;
        cymath::Size getSize() const;

        void          setColorKey(const Uint32 key) const;
        Uint32        getColorKey() const;
        void          setAlphaMod(const Uint8 alpha) const;
        Uint8         getAlphaMod() const;
        void          setBlendMode(const SDL_BlendMode mode) const;
        SDL_BlendMode getBlendMode() const;
        void          setColorMod(const SDL_Color& color) const;
        SDL_Color     getColorMod() const;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLSURFACE_HPP
