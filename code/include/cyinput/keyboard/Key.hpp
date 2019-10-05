#ifndef CYANIDE_KEY_HPP
#define CYANIDE_KEY_HPP

#include "IKey.hpp"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keycode.h"

namespace cyanide::cyinput
{

    class Key : public IKey
    {
    protected:
        KeyCode   m_key_code  = 0;
        KEY_STATE m_key_state = KEY_STATE::NONE;

    public:
        Key()          = default;
        virtual ~Key() = default;
        explicit Key(const KeyCode key);
        Key(const Key& other);
        Key(Key&& other) noexcept;
        Key& operator=(const Key& other);
        Key& operator=(Key&& other) noexcept;

        KEY_STATE getKeyState() const;
        bool      isReleased(const KeyCode key) const;
        bool      isDown(const KeyCode key) const;
        bool      isPressed(const KeyCode key) const;

        /*
         * Inherited from IKey
         */
        virtual KeyCode getCode() const override;
        virtual void    setCode(const KeyCode key) override;
    };

}  // namespace cyanide::cyinput

#endif  // CYANIDE_KEY_HPP
