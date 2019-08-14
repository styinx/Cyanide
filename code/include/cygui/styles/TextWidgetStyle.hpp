#ifndef CYANIDE_TEXTWIDGETSTYLE_HPP
#define CYANIDE_TEXTWIDGETSTYLE_HPP

#include "cygui/styles/Styles.hpp"
#include "cygui/styles/WidgetStyle.hpp"
#include "cyvideo/SDLTexture.hpp"
#include "cyvideo/color/RGBAColor.hpp"

namespace cyanide::cygui
{

    namespace Default
    {
        const String             FONT_FAMILY   = "Roboto";
        const Uint8              TEXT_SIZE     = 12;
        const ALIGN              TEXT_AIGNMENT = ALIGN::TOP_LEFT;
        const cyvideo::RGBAColor TEXT_FG_COLOR = cyvideo::RGBAColor{255, 0, 0, 255};
        const cyvideo::RGBAColor TEXT_BG_COLOR = cyvideo::RGBAColor{255, 255, 255, 255};
    }  // namespace Default

    class TextWidgetStyle : public WidgetStyle
    {
    protected:
        cyvideo::SDLTextureSPtr m_text_texture = nullptr;
        String                  m_font_family  = Default::FONT_FAMILY;
        Uint8                   m_text_size    = Default::TEXT_SIZE;
        ALIGN                   m_alignment    = Default::TEXT_AIGNMENT;
        cyvideo::RGBAColor      m_fg_color     = Default::TEXT_FG_COLOR;
        cyvideo::RGBAColor      m_bg_color     = Default::TEXT_BG_COLOR;

        TextWidgetStyle();

    public:
        void setFontFamily(const String& family);
        void setTextSize(const Uint8 size);
        void setTextAlignment(const ALIGN alignment);
        void setFGColor(const cyvideo::RGBAColor& color);
        void setBGColor(const cyvideo::RGBAColor& color);

        void drawText();
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_TEXTWIDGETSTYLE_HPP
