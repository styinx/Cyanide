#ifndef CYANIDE_SDLSURFACE_HPP
#define CYANIDE_SDLSURFACE_HPP

#include "cyvideo/ISurface.hpp"

#include "cymath/Size.hpp"

#include <SDL2/SDL_surface.h>

namespace cyanide::cyvideo
{

    class SDLSurface final : public ISurface
    {
    private:
        SDL_Surface* m_surface = nullptr;
        cymath::Size m_size{};

        SDLSurface() = default;

    public:
        explicit SDLSurface(const cymath::Size& size);
        ~SDLSurface() override;

        SDL_Surface* getSurface() const;
        cymath::Size getSize() const;
    };

}

#endif //CYANIDE_SDLSURFACE_HPP
