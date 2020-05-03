#include "cyaudio/player/Playlist.hpp"

namespace cyanide::cyaudio
{

    Playlist::Playlist(const String& path)
        : m_path(path)
    {
    }

    Mix_Music* Playlist::getMusic()
    {
        return Mix_LoadMUS(m_path.c_str());
    }

    void Playlist::next()
    {
        if(m_forward)
        {
            m_index++;
        }
        else
        {
            m_index--;
        }
    }

    void Playlist::previous()
    {
        if(m_forward)
        {
            m_index--;
        }
        else
        {
            m_index++;
        }
    }

    void Playlist::setForward()
    {
        m_forward = true;
    }

    void Playlist::setReverse()
    {
        m_forward = false;
    }

    bool Playlist::isShuffle() const
    {
        return m_shuffle;
    }

    void Playlist::setShuffle(const bool shuffle)
    {
        m_shuffle = shuffle;
    }

    bool Playlist::isRepeat() const
    {
        return m_repeat;
    }

    void Playlist::setRepeat(const bool repeat)
    {
        m_repeat = repeat;
    }

}  // namespace cyanide::cyaudio
