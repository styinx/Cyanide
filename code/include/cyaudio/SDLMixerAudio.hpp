#ifndef CYANIDE_SDLMIXERAUDIO_HPP
#define CYANIDE_SDLMIXERAUDIO_HPP

#include <SDL2/SDL_mixer.h>

#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"
#include "cystd/stdPrototypes.hpp"

namespace cyanide
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
        static void setMusicVolume(const Uint8 volume);
        static bool isMusicMuted();
        static void muteMusic();
        static void unmuteMusic();
        static Uint8 getChannelVolume(const Uint8 channel);
        static void setChannelVolume(const Uint8 channel, const Uint8 volume);
        static bool isChannelMuted(const Uint8 channel);
        static void muteChannel(const Uint8 channel);
        static void unmuteChannel(const Uint8 channel);
    };

}  // namespace cyaudio
}  // namespace cyanide

#endif  // CYANIDE_SDLMIXERAUDIO_HPP
