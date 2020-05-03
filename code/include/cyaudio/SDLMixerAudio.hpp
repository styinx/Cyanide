#ifndef CYANIDE_SDLMIXERAUDIO_HPP
#define CYANIDE_SDLMIXERAUDIO_HPP

#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"
#include "cystd/Types.hpp"

#include <SDL2/SDL_mixer.h>

namespace cyanide::cyaudio
{

    class SDLMixerAudio
        : public cystd::NonCopyable
        , public cystd::NonMoveable
    {
    private:
        static Uint8             music_volume;
        static Map<Uint8, Uint8> channel_volume;

    public:
        static void play(Mix_Music* music, const Uint32 fadein = 0, const Uint32 loops = 0);
        static void pause();
        static void stop(const Uint32 fadeout = 0);
        static void
                     play(Mix_Chunk* chunk, const Uint8 channel, const Uint32 fadein = 0, const Uint32 loops = 0);
        static void  pause(const Uint8 channel);
        static void  stop(const Uint8 channel, const Uint32 fadeout = 0);
        static Uint8 getMusicVolume();
        static void  setMusicVolume(const Uint8 volume);
        static bool  isMusicMuted();
        static void  muteMusic();
        static void  unmuteMusic();
        static Uint8 getChannelVolume(const Uint8 channel);
        static void  setChannelVolume(const Uint8 channel, const Uint8 volume);
        static bool  isChannelMuted(const Uint8 channel);
        static void  muteChannel(const Uint8 channel);
        static void  unmuteChannel(const Uint8 channel);
    };

}  // namespace cyanide::cyaudio

#endif  // CYANIDE_SDLMIXERAUDIO_HPP
