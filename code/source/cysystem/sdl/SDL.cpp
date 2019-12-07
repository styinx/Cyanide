#include "cysystem/sdl/SDL.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_ttf.h>

namespace cyanide::cysystem
{

    Uint32 SDL::initSDL(const Uint32& flags)
    {
        if(m_sdl_flags == 0)
        {
            if(SDL_Init(flags) == 0)
            {
                m_sdl_flags |= flags;
            }
        }
        else
        {
            if(SDL_InitSubSystem((flags ^ m_sdl_flags) & flags) == 0)
            {
                m_sdl_flags |= flags;
            }
        }

        return m_sdl_flags;
    }

    void SDL::quitSDL(const Uint32& flags)
    {
        if(flags == 0)
        {
            SDL_Quit();
        }
        else
        {
            if((flags & m_sdl_flags) != 0)
            {
                SDL_QuitSubSystem(flags);
            }
        }
    }

    Uint32 SDL::initIMG(const Uint32& flags)
    {
        return m_img_flags = IMG_Init(flags);
    }

    void SDL::quitIMG()
    {
        if(m_img_flags != 0)
        {
            IMG_Quit();
        }
    }

    Uint32 SDL::initMIX(const Uint32& flags)
    {
        return m_mix_flags = Mix_Init(flags);
    }

    void SDL::quitMIX()
    {
        if(m_mix_flags != 0)
        {
            Mix_Quit();
        }
    }

    Uint32 SDL::initNET()
    {
        if(m_sdl_flags)
        {
            return SDLNet_Init() == 0;
        }
        return 0;
    }

    void SDL::quitNET()
    {
        SDLNet_Quit();
    }

    Uint32 SDL::initTTF()
    {
        return TTF_Init() == 0;
    }

    void SDL::quitTTF()
    {
        TTF_Quit();
    }

}
