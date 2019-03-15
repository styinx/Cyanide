#ifndef CYANIDE_SDLMUSIC_HPP
#define CYANIDE_SDLMUSIC_HPP

#include <SDL2/SDL_mixer.h>

#include "IMedium.hpp"

namespace cyanide
{
namespace cyaudio
{

    class SDLMusic : public IMedium
    {
    private:
        const char* m_resource = "";
        Mix_Music*  m_music    = nullptr;

    public:
        SDLMusic() = default;

        explicit SDLMusic(const char* resource);

        ~SDLMusic() = default;

        Mix_Music* getMusic() const;

        virtual const char* getResource() const override;

        virtual void setResource(const char* new_resource) override;
    };

}  // namespace cyaudio
}  // namespace cyanide

#endif  // CYANIDE_SDLMUSIC_HPP
