#ifndef CYANIDE_AUDIOPLAYER_HPP
#define CYANIDE_AUDIOPLAYER_HPP

#include "cyaudio/player/Playlist.hpp"
#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"
#include "cystd/Types.hpp"

namespace cyanide::cyaudio
{

    class AudioPlayer final
        : public cystd::NonCopyable
        , public cystd::NonMoveable
    {
    private:
        enum class PLAYBACK_STATE : Uint8
        {
            STOPPED = 0x00,
            PAUSED  = 0x01,
            PLAYING = 0x02
        };

        Uint32         m_fadein  = 500;
        Uint32         m_fadeout = 500;
        Uint8          m_volume  = 128;
        PLAYBACK_STATE m_state   = PLAYBACK_STATE::STOPPED;

        // Playlist
        PlaylistSPtr m_playlist;

    public:
        AudioPlayer();
        explicit AudioPlayer(const PlaylistSPtr& playlist);
        virtual ~AudioPlayer() = default;

        void play();
        bool isPlaying() const;
        void pause();
        bool isPaused() const;
        void resume();
        void stop();
        bool isStopped() const;
        void setPlayback();
        void togglePlayback();

        void mute();
        void unmute();
        bool isMuted() const;
        void setVolume(const Uint8 volume);
        void setFadein(const Uint32 millis);
        void setFadeout(const Uint32 millis);

        void rewind();
        void next();
        void previous();
        void forward(const Uint64 skip);
        void seek(const Uint64 position);
        void backward(const Uint64 skip);
    };

}  // namespace cyanide::cyaudio

#endif  // CYANIDE_AUDIOPLAYER_HPP
