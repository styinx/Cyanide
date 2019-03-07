#ifndef CYANIDE_SDLMUSIC_HPP
#define CYANIDE_SDLMUSIC_HPP

#include <SDL2/SDL_mixer.h>

#include "IMedium.hpp"

namespace Cyanide
{
namespace cyaudio
{

    class SDLMusic : public IMedium
    {
    private:
        const char* resource = "";
        Mix_Music*  music    = nullptr;

    public:
        SDLMusic() = default;

        explicit SDLMusic(const char* resource);

        ~SDLMusic() = default;

        Mix_Music* getMusic() const;

        virtual const char* getResource() const override;

        virtual void setResource(const char* new_resource) override;
    };

}  // namespace cyaudio
}  // namespace Cyanide

#endif  // CYANIDE_SDLMUSIC_HPP
