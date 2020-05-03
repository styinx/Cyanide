#include "cyaudio/SDLMixerAudio.hpp"

namespace cyanide::cyaudio
{
    Uint8             SDLMixerAudio::music_volume   = 0;
    Map<Uint8, Uint8> SDLMixerAudio::channel_volume = Map<Uint8, Uint8>();

    void SDLMixerAudio::play(Mix_Music* music, const Uint32 fadein, const Uint32 loops)
    {
        if(fadein == 0)
        {
            Mix_PlayMusic(music, loops);
        }
        else
        {
            Mix_FadeInMusic(music, loops, fadein);
        }
    }

    void SDLMixerAudio::pause()
    {
        Mix_PauseMusic();
    }

    void SDLMixerAudio::stop(const Uint32 fadeout)
    {
        if(fadeout == 0)
        {
            Mix_HaltMusic();
        }
        else
        {
            Mix_FadeOutMusic(fadeout);
        }
    }

    void SDLMixerAudio::play(Mix_Chunk* chunk, const Uint8 channel, Uint32 fadein, Uint32 loops)
    {
        if(fadein == 0)
        {
            Mix_PlayChannel(channel, chunk, loops);
        }
        else
        {
            Mix_FadeInChannel(channel, chunk, loops, fadein);
        }
    }

    void SDLMixerAudio::pause(const Uint8 channel)
    {
        Mix_Pause(channel);
    }

    void SDLMixerAudio::stop(const Uint8 channel, Uint32 fadeout)
    {
        if(fadeout == 0)
        {
            Mix_HaltChannel(channel);
        }
        else
        {
            Mix_FadeOutChannel(channel, fadeout);
        }
    }

    Uint8 SDLMixerAudio::getMusicVolume()
    {
        return static_cast<Uint8>(Mix_VolumeMusic(-1));
    }

    void SDLMixerAudio::setMusicVolume(const Uint8 volume)
    {
        Mix_VolumeMusic(volume);
    }

    bool SDLMixerAudio::isMusicMuted()
    {
        return SDLMixerAudio::getMusicVolume() == 0;
    }

    void SDLMixerAudio::muteMusic()
    {
        Uint8 volume = SDLMixerAudio::getMusicVolume();

        if(volume > 0)
        {
            SDLMixerAudio::music_volume = volume;
            SDLMixerAudio::setMusicVolume(0);
        }
    }

    void SDLMixerAudio::unmuteMusic()
    {
        if(SDLMixerAudio::getMusicVolume() == 0)
        {
            SDLMixerAudio::setMusicVolume(SDLMixerAudio::music_volume);
        }
    }

    Uint8 SDLMixerAudio::getChannelVolume(const Uint8 channel)
    {
        return static_cast<Uint8>(Mix_Volume(channel, -1));
    }

    void SDLMixerAudio::setChannelVolume(const Uint8 channel, const Uint8 volume)
    {
        Mix_Volume(channel, volume);
    }

    bool SDLMixerAudio::isChannelMuted(const Uint8 channel)
    {
        return SDLMixerAudio::getChannelVolume(channel) == 0;
    }

    void SDLMixerAudio::muteChannel(const Uint8 channel)
    {
        Uint8 volume = SDLMixerAudio::getChannelVolume(channel);

        if(volume > 0)
        {
            SDLMixerAudio::channel_volume[channel] = volume;
            SDLMixerAudio::setChannelVolume(channel, 0);
        }
    }

    void SDLMixerAudio::unmuteChannel(const Uint8 channel)
    {
        if(SDLMixerAudio::getChannelVolume(channel) == 0)
        {
            SDLMixerAudio::setChannelVolume(channel, SDLMixerAudio::channel_volume[channel]);
        }
    }
}  // namespace cyanide
