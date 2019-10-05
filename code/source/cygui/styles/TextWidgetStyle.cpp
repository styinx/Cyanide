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
        m_font_family = family;
    }

    void TextWidgetStyle::setTextSize(const Uint8 size)
    {
        m_text_size = size;
    }

    void TextWidgetStyle::setTextAlignment(const ALIGN alignment)
    {
        m_alignment = alignment;
    }

    void TextWidgetStyle::setFGColor(const cyutil::RGBAColor& color)
    {
        m_fg_color = color;
    }

    void TextWidgetStyle::setBGColor(const cyutil::RGBAColor& color)
    {
        m_bg_color = color;
    }

}  // namespace cyanide::cygui
