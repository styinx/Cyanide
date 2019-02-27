#ifndef CYANIDE_SDLMIXERAUDIO_HPP
#define CYANIDE_SDLMIXERAUDIO_HPP

#include <SDL2/SDL_mixer.h>

#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"
#include "cystd/stdPrototypes.hpp"

namespace Cyanide
{
namespace cyaudio
{

    class SDLMixerAudio
        : public cystd::NonCopyable
        , public cystd::NonMoveable
    {
    private:
        static Uint8 music_volume;
        static Map<Uint8, Uint8> channel_volume;

    public:
        static Uint8 getMusicVolume();
        static void setMusicVolume(Uint8 volume);
        static bool isMusicMuted();
        static void muteMusic();
        static void unmuteMusic();
        static Uint8 getChannelVolume(Uint8 channel);
        static void setChannelVolume(Uint8 channel, Uint8 volume);
        static bool isChannelMuted(Uint8 channel);
        static void muteChannel(Uint8 channel);
        static void unmuteChannel(Uint8 channel);
    };

}  // namespace cyaudio
}  // namespace Cyanide

#endif  // CYANIDE_SDLMIXERAUDIO_HPP
