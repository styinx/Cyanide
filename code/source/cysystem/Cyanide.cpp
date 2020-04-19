#include "cysystem/Cyanide.hpp"

namespace cyanide::cysystem
{

    MODULE operator++(MODULE& m)
    {
        m = static_cast<MODULE>(cystd::fromEnum(m) + 1);
        return m;
    }

    Cyanide::Cyanide()
    {
        m_sdl = SDL{};
        m_sdl.initSDL(SDL_INIT_EVERYTHING);

        for(MODULE m = MODULE::AUDIO; m <= MODULE::VIDEO; ++m)
        {
            m_module_state[m] = false;
        }
    }

    void Cyanide::initGUI()
    {
        initVideo();

        if(!m_module_state[MODULE::GUI])
        {
            m_sdl.initTTF();
            m_module_state[MODULE::GUI] = true;
        }
    }

    void Cyanide::initNET()
    {
        if(!m_module_state[MODULE::NET])
        {
            m_sdl.initNET();
            m_module_state[MODULE::NET] = true;
        }
    }

    void Cyanide::initVideo()
    {
        if(!m_module_state[MODULE::VIDEO])
        {
            m_sdl.initIMG(IMG_INIT_PNG);
            m_module_state[MODULE::VIDEO] = true;
        }
    }

}  // namespace cyanide::cysystem
