#include "cygui/widgets/TextWidget.hpp"

#include "cygui/GUIRenderManager.hpp"
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
        : Widget()
    {
        m_text_texture = cyvideo::SDLTextureSPtr(
            new cyvideo::SDLTexture(GUIRenderManager::getRenderer(), cymath::Size{0, 0}));
    }

    TextWidget::TextWidget(const String& text)
        : Widget()
        , m_text(text)
    {
        initTextTexture();
    }

    // Private

    void TextWidget::initTextTexture()
    {
        using namespace cyvideo;

        const SDLFont* font = SDLFontCollection::getFont(m_font_family);

        if(font != nullptr)
        {
            // If widget does not have a size set it to the size of the text.
            if(!m_content)
            {
                SDL_Surface* text_surface = TTF_RenderText_Blended(
                    font->getFont(),
                    m_text.c_str(),
                    {m_fg_color.r, m_fg_color.g, m_fg_color.b, m_fg_color.a});

                auto surface = std::make_shared<SDLSurface>(text_surface);
                m_text_texture =
                    std::make_shared<SDLTexture>(GUIRenderManager::getRenderer(), surface);

                const auto size = m_text_texture->getSize() + getPadding() + getBorder() + getMargin();
                setSize(size);

                // Clear the temporary surface
                surface.reset();
            }
            else
            {
                // TODO
            }
        }
        else
        {
            // err
        }
    }

    // Public

    void TextWidget::setText(const String& text)
    {
        m_text                 = text;
        m_text_texture_changed = true;
    }

    String TextWidget::getText() const
    {
        return m_text;
    }

    void TextWidget::drawText()
    {
        calculateTextures();

        auto renderer = GUIRenderManager::getRenderer();
        auto offset = cymath::Point(0, 0);

        offset += {m_margin.left, m_margin.top};
        offset += {m_border.left, m_border.top};
        offset += {m_padding.left, m_padding.top};

        renderer->setRenderTarget(m_content_texture);
        renderer->drawSDLTexture(m_text_texture, offset);
        renderer->resetRenderTarget();
    }

    void TextWidget::draw()
    {
        if(m_text_texture_changed)
        {
            initTextTexture();
            m_text_texture_changed = false;
        }

        drawText();

        Object::draw();
    }

}  // namespace cyanide::cygui
