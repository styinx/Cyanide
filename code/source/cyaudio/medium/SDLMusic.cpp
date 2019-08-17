#include "cyaudio/medium/SDLMusic.hpp"

namespace cyanide::cyaudio
{

    SDLMusic::SDLMusic(const char* resource)
    {
        setResource(resource);
    }

    Mix_Music* SDLMusic::getMusic() const
    {
        return m_music;
    }

    const String SDLMusic::getResource() const
    {
        return m_resource;
    }

    void SDLMusic::setResource(const String& new_resource)
    {
        m_resource = new_resource;
        if(m_music != nullptr)
        {
            Mix_FreeMusic(m_music);
        }
        m_music = Mix_LoadMUS(m_resource.c_str());
    }

}  // namespace cyanide::cyaudio