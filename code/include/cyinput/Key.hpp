#ifndef CYANIDE_KEY_HPP
#define CYANIDE_KEY_HPP

#include "SDL2/SDL_keycode.h"
#include "SDL2/SDL_events.h"

#include "cyinput/IKey.hpp"

namespace cyanide
{
namespace cyinput
{

    class Key final : public IKey
    {
    private:
        Uint32 code = 0;

    public:
        Key() = default;
        ~Key() = default;
        explicit Key(const Uint32 key);
        explicit Key(const KEY key);
        explicit Key(const Key& key) = default;
        explicit Key(Key&& key) noexcept = default;
        Key& operator=(const Key& key) = default;
        Key& operator=(Key&& key) noexcept = default;
        static bool isReleased(SDL_Event* event);
        static bool isDown(SDL_Event* event);
        static bool isPressed(SDL_Event* event);
        Uint32 getValue() const;
        Key& setCode(const Uint32 key);
        Key& setCode(const KEY key);
        Key& setCode(const Key& key);
        Key& setCode(const SDL_Keycode& key);
    };

}  // namespace cyinput
}  // namespace cyanide

#endif  // CYANIDE_KEY_HPP
