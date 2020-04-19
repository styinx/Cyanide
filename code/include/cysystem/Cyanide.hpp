#ifndef CYANIDE_CYANIDE_HPP
#define CYANIDE_CYANIDE_HPP

#include "cystd/Enum.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"

namespace cyanide::cysystem
{

    enum class MODULE : Uint8
    {
        AUDIO  = 0x00,
        GUI    = 0x01,
        INPUT  = 0x02,
        MATH   = 0x03,
        NET    = 0x04,
        STD    = 0x05,
        SYSTEM = 0x06,
        UTIL   = 0x07,
        VIDEO  = 0x08
    };

    MODULE operator++(MODULE& m);

    class Cyanide final
    {
    private:
        Map<MODULE, bool> m_module_state;
        SDL               m_sdl;

    public:
        Cyanide();

        void initGUI();
        void initNET();
        void initVideo();
    };

}  // namespace cyanide::cysystem

#endif  // CYANIDE_CYANIDE_HPP
