#include "cyinput/keyboard/SDLKey.hpp"

namespace cyanide::cyinput
{

    SDLKey::SDLKey(const SDL_Keycode code)
        : Key(static_cast<KeyCode>(code))
    {
    }

    void SDLKey::setCode(const SDL_Keycode code)
    {
        m_key_code = static_cast<KeyCode>(code);
    }

} // namespace cyanide::cyinput
