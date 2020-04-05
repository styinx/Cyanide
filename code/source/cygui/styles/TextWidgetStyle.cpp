#include "cygui/styles/TextWidgetStyle.hpp"

#include "cygui/GUIRenderManager.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"

namespace cyanide::cygui
{

    TextWidgetStyle::TextWidgetStyle()
    {
        using namespace cyvideo;

        m_text_texture = SDLTextureSPtr(new SDLTexture(
            GUIRenderManager::getRenderer(),
            cymath::Size{0, 0}));
    }

    void TextWidgetStyle::setFontFamily(const String& family)
    {
        m_font_family          = family;
        m_text_texture_changed = true;
    }

    void TextWidgetStyle::setTextSize(const Uint8 size)
    {
        m_text_size            = size;
        m_text_texture_changed = true;
    }

    void TextWidgetStyle::setTextAlignment(const ALIGN alignment)
    {
        m_alignment            = alignment;
        m_text_texture_changed = true;
    }

    void TextWidgetStyle::setFGColor(const cyutil::RGBAColor& color)
    {
        m_fg_color             = color;
        m_text_texture_changed = true;
    }

    void TextWidgetStyle::setBGColor(const cyutil::RGBAColor& color)
    {
        m_bg_color             = color;
        m_text_texture_changed = true;
    }

}  // namespace cyanide::cygui
