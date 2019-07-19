#include "cygui/styles/TextStyle.hpp"

namespace cyanide::cygui
{

    void TextStyle::setTextSize(const Uint8 size)
    {
        m_text_size = size;
    }

    void TextStyle::setTextAlignment(const ALIGN alignment)
    {
        m_alignment = alignment;
    }

}  // namespace cyanide::cygui