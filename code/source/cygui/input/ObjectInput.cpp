#include "cygui/input/ObjectInput.hpp"

namespace cyanide::cygui
{

    void ObjectInput::focusGained()
    {
        if(m_focus_callback)
        {
            m_focus_callback();
        }
    }

    void ObjectInput::focusLost()
    {
    }

    void ObjectInput::enter()
    {
        if(m_hover_callback)
        {
            m_hover_callback();
        }
    }

    void ObjectInput::leave()
    {
    }

    void ObjectInput::click()
    {
        if(m_click_callback)
        {
            m_click_callback();
        }
    }

}  // namespace cyanide::cygui
