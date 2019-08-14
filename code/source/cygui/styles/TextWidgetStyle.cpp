#include "cygui/styles/TextWidgetStyle.hpp"

#include "cygui/GUIObjectManager.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"

namespace cyanide::cygui
{

    TextWidgetStyle::TextWidgetStyle()
        : WidgetStyle()
    {
        using namespace cyvideo;

        m_text_texture = SDLTextureSPtr(new SDLTexture(
            GUIObjectManager::getRenderer(),
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

    void TextWidgetStyle::setFGColor(const cyvideo::RGBAColor& color)
    {
        m_fg_color = color;
    }

    void TextWidgetStyle::setBGColor(const cyvideo::RGBAColor& color)
    {
        m_bg_color = color;
    }

    void TextWidgetStyle::drawText()
    {
        auto renderer = GUIObjectManager::getRenderer();
        renderer->setRenderTarget(m_content_texture);
        renderer->drawSDLTexture(m_text_texture, {0, 0});
        renderer->resetRenderTarget();
    }

}  // namespace cyanide::cygui