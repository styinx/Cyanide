#ifndef CYANIDE_SDL_HPP
#define CYANIDE_SDL_HPP

// Windows
#define SDL_MAIN_HANDLED

#include "cystd/Types.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace cyanide::cysystem
{

    class SDL final
    {
    private:
        Uint32 m_sdl_flags = 0;
        Uint32 m_img_flags = 0;
        Uint32 m_mix_flags = 0;

    public:
        SDL()                   = default;
        SDL(const SDL& SDL)     = default;
        SDL(SDL&& SDL) noexcept = default;
        SDL& operator=(const SDL& SDL) = default;
        SDL& operator=(SDL&& SDL) noexcept = default;
        ~SDL()                             = default;

        Uint32 initSDL(const Uint32& flags);
        void   quitSDL(const Uint32& flags);
        Uint32 initIMG(const Uint32& flags);
        void   quitIMG();
        Uint32 initMIX(const Uint32& flags);
        void   quitMIX();
        Uint32 initNET();
        void   quitNET();
        Uint32 initTTF();
        void   quitTTF();
    };

}  // namespace cyanide::cysystem

#endif  // CYANIDE_SDL_HPP
