#include "cyaudio/SDLMixerAudio.hpp"

namespace Cyanide
{
namespace cyaudio
{
    Uint8             SDLMixerAudio::music_volume   = 0;
    Map<Uint8, Uint8> SDLMixerAudio::channel_volume = Map<Uint8, Uint8>();

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
}  // namespace cyaudio
}  // namespace Cyanide