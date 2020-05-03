#ifndef CYANIDE_PLAYLIST_HPP
#define CYANIDE_PLAYLIST_HPP

#include "cyaudio/medium/IMedium.hpp"
#include "cystd/Types.hpp"

#include <SDL2/SDL_mixer.h>

namespace cyanide::cyaudio
{

    class Playlist final
    {
    private:
        bool m_forward = false;
        bool m_shuffle = false;
        bool m_repeat  = false;

        Uint32              m_index;
        Vector<IMediumSPtr> m_queue;
        String              m_path;

    public:
        Playlist() = default;
        explicit Playlist(const String& path);
        virtual ~Playlist() = default;

        Mix_Music* getMusic();

        void next();
        void previous();
        void setForward();
        void setReverse();

        bool isShuffle() const;
        void setShuffle(const bool shuffle);
        bool isRepeat() const;
        void setRepeat(const bool repeat);
    };

    using PlaylistSPtr = SharedPtr<Playlist>;

}  // namespace cyanide::cyaudio

#endif  // CYANIDE_PLAYLIST_HPP
