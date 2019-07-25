
#include <cyinput/Key.hpp>

#include "cyinput/Key.hpp"

namespace cyanide
{
namespace cyinput
{

    cyinput::Key::Key(const Uint32 key)
    {

    }

    cyinput::Key::Key(const KEY key)
    {

    }

    bool Key::isReleased(SDL_Event* event)
    {
        return false;
    }

    bool Key::isDown(SDL_Event* event)
    {
        return false;
    }

    bool Key::isPressed(SDL_Event* event)
    {
        return false;
    }

    Uint32 Key::getValue() const
    {
        return code;
    }

    Key& Key::setCode(const Uint32 key)
    {
        code = key;
        return *this;
    }

    Key& Key::setCode(const KEY key)
    {
        code = static_cast<Uint32>(key);
        return *this;
    }

    Key& Key::setCode(const Key& key)
    {
        code = key.getValue();
        return *this;
    }

    Key& Key::setCode(const SDL_Keycode& key)
    {
        code = static_cast<Uint32>(key);
        return *this;
    }

}  // namespace cyinput
}  // namespace cyanide