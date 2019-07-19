#ifndef CYANIDE_TEXTSTYLE_HPP
#define CYANIDE_TEXTSTYLE_HPP

#include "cygui/styles/Style.hpp"

namespace cyanide::cygui
{

    namespace Default
    {
        const Uint8 TEXT_SIZE = 12;
        const ALIGN TEXT_AIGNMENT = ALIGN::TOP_LEFT;
    }


    class TextStyle
    {
    private:
        Uint8 m_text_size = Default::TEXT_SIZE;
        ALIGN m_alignment = Default::TEXT_AIGNMENT;

    public:
        void setTextSize(const Uint8 size);
        void setTextAlignment(const ALIGN alignment);
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_TEXTSTYLE_HPP
