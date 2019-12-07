#ifndef CYANIDE_SDLMUSIC_HPP
#define CYANIDE_SDLMUSIC_HPP

#include "IMedium.hpp"

#include <SDL2/SDL_mixer.h>

namespace cyanide::cyaudio
{

    class SDLMusic : public IMedium
    {
    private:
        String     m_resource;
        Mix_Music* m_music = nullptr;

    public:
        SDLMusic() = default;
        explicit SDLMusic(const char* resource);
        ~SDLMusic() = default;

        Mix_Music*           getMusic() const;
        virtual const String getResource() const override;
        virtual void         setResource(const String& new_resource) override;
    };

}  // namespace cyanide::cyaudio

#endif  // CYANIDE_SDLMUSIC_HPP
