#ifndef CYANIDE_OBJECTINPUT_HPP
#define CYANIDE_OBJECTINPUT_HPP

#include "cyinput/SDLEventLoop.hpp"
#include "cystd/Types.hpp"

namespace cyanide::cygui
{

    enum class EVENT : Byte
    {
        ENTER        = 0x01,
        LEAVE        = 0x02,
        SCROLL       = 0x08,
        CLICK        = 0x0F,
        DOUBLE_CLICK = 0x10,
        FOCUS_GAINED = 0x40,
        FOCUS_LOST   = 0x80,
        KEY          = 0xF0
    };

    class ObjectInput
    {
    protected:
        Byte m_event_mask = 0;
        bool m_has_focus  = false;
        bool m_is_hovered = false;

        cyinput::Callback m_focus_callback;
        cyinput::Callback m_hover_callback;
        cyinput::Callback m_click_callback;

        ObjectInput() = default;
        void focusGained();
        void focusLost();
        void enter();
        void leave();
        void click();

    public:
        virtual ~ObjectInput()                                  = default;
        virtual void pollEvent(cyinput::SDLEventLoop& loop)     = 0;
        virtual void onFocus(const cyinput::Callback& callback) = 0;
        virtual void onHover(const cyinput::Callback& callback) = 0;
        virtual void onClick(const cyinput::Callback& callback) = 0;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_OBJECTINPUT_HPP
