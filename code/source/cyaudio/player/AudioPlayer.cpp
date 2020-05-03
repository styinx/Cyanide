#include "cyaudio/player/AudioPlayer.hpp"

#include "cyaudio/SDLMixerAudio.hpp"

namespace cyanide::cyaudio
{

    AudioPlayer::AudioPlayer()
    {
        SDLMixerAudio::open();
    }

    AudioPlayer::AudioPlayer(const PlaylistSPtr& playlist)
        : m_playlist(playlist)
    {
        SDLMixerAudio::open();
    }

    void AudioPlayer::play()
    {
        SDLMixerAudio::play(m_playlist->getMusic(), m_fadein);
    }

    bool AudioPlayer::isPlaying() const
    {
        return m_state == PLAYBACK_STATE::PLAYING;
    }

    void AudioPlayer::pause()
    {
        SDLMixerAudio::pause();
        m_state = PLAYBACK_STATE::PAUSED;
    }

    bool AudioPlayer::isPaused() const
    {
        return m_state == PLAYBACK_STATE::PAUSED;
    }

    void AudioPlayer::resume()
    {
        SDLMixerAudio::resume();
        m_state = PLAYBACK_STATE::PLAYING;
    }

    void AudioPlayer::stop()
    {
        SDLMixerAudio::stop(m_fadeout);
    }

    bool AudioPlayer::isStopped() const
    {
        return m_state == PLAYBACK_STATE::STOPPED;
    }

    void AudioPlayer::setPlayback()
    {
    }

    void AudioPlayer::togglePlayback()
    {
    }

    void AudioPlayer::mute()
    {
        SDLMixerAudio::setMusicVolume(0);
    }

    void AudioPlayer::unmute()
    {
        SDLMixerAudio::setMusicVolume(m_volume);
    }

    bool AudioPlayer::isMuted() const
    {
        return SDLMixerAudio::getMusicVolume() == 0;
    }

    void AudioPlayer::setVolume(const Uint8 volume)
    {
        SDLMixerAudio::setMusicVolume(volume);
        m_volume = volume;
    }

    void AudioPlayer::setFadein(const Uint32 millis)
    {
        m_fadein = millis;
    }

    void AudioPlayer::setFadeout(const Uint32 millis)
    {
        m_fadeout = millis;
    }

    void AudioPlayer::rewind()
    {
        SDLMixerAudio::rewind();
    }

    void AudioPlayer::next()
    {
        m_playlist->next();
    }

    void AudioPlayer::previous()
    {
        m_playlist->previous();
    }

    void AudioPlayer::forward(const Uint64 skip)
    {
    }

    void AudioPlayer::seek(const Uint64 position)
    {
        SDLMixerAudio::seek(position);
    }

    void AudioPlayer::backward(const Uint64 skip)
    {
    }

}  // namespace cyanide::cyaudio
