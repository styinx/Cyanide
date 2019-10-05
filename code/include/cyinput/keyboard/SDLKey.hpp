#ifndef CYANIDE_SDLKEY_HPP
#define CYANIDE_SDLKEY_HPP

#include "Key.hpp"

namespace cyanide::cyinput
{

    class SDLKey final : public Key
    {
    public:
        explicit SDLKey(const SDL_Keycode code);
        SDLKey()  = default;
        ~SDLKey() = default;

        void setCode(const SDL_Keycode code);
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_SDLKEY_HPP
