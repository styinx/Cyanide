#include "cyaudio/player/AudioPlayer.hpp"

#include "cyaudio/SDLMixerAudio.hpp"

namespace cyanide::cyaudio
{

    AudioPlayer::AudioPlayer(const PlaylistSPtr& playlist)
        : m_playlist(playlist)
    {
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
    }

    bool AudioPlayer::isPaused() const
    {
        return m_state == PLAYBACK_STATE::PAUSED;
    }

    void AudioPlayer::resume()
    {
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
    }

    void AudioPlayer::unmute()
    {
    }

    bool AudioPlayer::isMuted() const
    {
    }

    void AudioPlayer::setVolume(const Uint32 volume)
    {
        SDLMixerAudio::setMusicVolume(volume);
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
    }

    void AudioPlayer::next()
    {
    }

    void AudioPlayer::previous()
    {
    }

    void AudioPlayer::forward(const Uint32 skip)
    {
    }

    void AudioPlayer::seek(const Uint32 position)
    {
    }

    void AudioPlayer::backward(const Uint32 skip)
    {
    }

}  // namespace cyanide::cyaudio
