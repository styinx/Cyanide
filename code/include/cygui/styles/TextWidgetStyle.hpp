#ifndef CYANIDE_TEXTWIDGETSTYLE_HPP
#define CYANIDE_TEXTWIDGETSTYLE_HPP

#include "cygui/styles/Styles.hpp"
#include "cygui/styles/WidgetStyle.hpp"
#include "cyutil/color/RGBAColor.hpp"
#include "cyvideo/SDLTexture.hpp"

namespace cyanide::cygui
{

    namespace Default
    {
        const String            FONT_FAMILY   = "Roboto";
        const Uint8             TEXT_SIZE      = 12;
        const ALIGN             TEXT_ALIGNMENT = ALIGN::MIDDLE_CENTER;
        const cyutil::RGBAColor TEXT_FG_COLOR  = cyutil::RGBAColor{0, 0, 0, 255};
        const cyutil::RGBAColor TEXT_BG_COLOR = cyutil::RGBAColor{255, 255, 255, 255};
    }  // namespace Default

    class TextWidgetStyle
    {
    protected:
        cyvideo::SDLTextureSPtr m_text_texture         = nullptr;
        bool                    m_text_texture_changed = true;
        String                  m_font_family          = Default::FONT_FAMILY;
        Uint8                   m_text_size            = Default::TEXT_SIZE;
        ALIGN                   m_alignment            = Default::TEXT_ALIGNMENT;
        cymath::Point           m_alignment_offset     = {0, 0};
        cyutil::RGBAColor       m_text_fg_color        = Default::TEXT_FG_COLOR;
        cyutil::RGBAColor       m_text_bg_color        = Default::TEXT_BG_COLOR;

        TextWidgetStyle();

    public:
        ~TextWidgetStyle() = default;

        void setFontFamily(const String& family);
        void setTextSize(const Uint8 size);
        void setTextAlignment(const ALIGN alignment);
        void setTextFGColor(const cyutil::RGBAColor& color);
        void setTextBGColor(const cyutil::RGBAColor& color);
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_TEXTWIDGETSTYLE_HPP
