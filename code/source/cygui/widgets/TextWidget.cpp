#include "cygui/widgets/TextWidget.hpp"

#include "cygui/GUIObjectManager.hpp"
#include "cymath/Space.hpp"
#include "cyvideo/SDLSurface.hpp"
#include "cyvideo/SDLTexture.hpp"
#include "cyvideo/font/SDLFont.hpp"
#include "cyvideo/font/SDLFontCollection.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/videoPrototypes.hpp"

namespace cyanide::cygui
{
    TextWidget::TextWidget()
    {
        m_text_texture = cyvideo::SDLTextureSPtr(new cyvideo::SDLTexture(
            GUIObjectManager::getRenderer(),
            cymath::Size{0, 0}));
    }

    TextWidget::TextWidget(const String& text)
        : Widget()
        , m_text(text)
    {
        using namespace cyvideo;

        SDL_Surface* text_surface = TTF_RenderText_Blended(
            SDLFontCollection::getFont(m_font_family)->getFont(),
            text.c_str(),
            {m_fg_color.r, m_fg_color.g, m_fg_color.b});

        auto surface = std::make_shared<SDLSurface>(text_surface);
        m_text_texture = std::make_shared<SDLTexture>(GUIObjectManager::getRenderer(), surface);

        surface.reset();

        // If widget does not have a size set it to the size of the text.
        if(m_content == cymath::Size(0, 0))
        {
            setSize(m_text_texture->getSize());
        }

        drawBorder();
        drawBackground();
        drawText();
    }

    void TextWidget::setText(const String& text)
    {
        m_text = text;
    }

    String TextWidget::getText() const
    {
        return m_text;
    }
}