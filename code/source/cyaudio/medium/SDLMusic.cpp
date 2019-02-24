#include "cyaudio/medium/SDLMusic.hpp"

namespace Cyanide
{
namespace cyaudio
{

    SDLMusic::SDLMusic(const char* resource)
    {
        setResource(resource);
    }

    Mix_Music* SDLMusic::getMusic() const
    {
        return music;
    }

    const char* SDLMusic::getResource() const
    {
        return resource;
    }

    void SDLMusic::setResource(const char* new_resource)
    {
        resource = new_resource;
        if(music != nullptr)
        {
            Mix_FreeMusic(music);
        }
        music = Mix_LoadMUS(resource);
    }

}  // namespace cyaudio
}  // namespace Cyanide