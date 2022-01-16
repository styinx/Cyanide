#include "cygui/widgets/TextWidget.hpp"

#include "cymath/Space.hpp"
#include "cymath/scaling.hpp"
#include "cystd/Enum.hpp"
#include "cyvideo/SDLSurface.hpp"
#include "cyvideo/SDLTexture.hpp"
#include "cyvideo/font/SDLFont.hpp"
#include "cyvideo/font/SDLFontCollection.hpp"
#include "cyvideo/renderer/GUIRenderManager.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"

namespace cyanide::cygui
{

    TextWidget::TextWidget()
        : Widget()
    {
        m_text_texture =
            cyvideo::SDLTexture::Create(cyvideo::GUIRenderManager::getRenderer(), cymath::Size{0, 0});
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

        const SDLFont* font = SDLFontCollection::getFont(m_font_family, m_text_size);

        if(font)
        {
            m_text_texture = font->render(m_text, m_text_fg_color, RENDER_TYPE::BLENDED);

            // If widget does not have a size set it to the size of the text.
            if(!m_content)
            {
                setContentSize(m_text_texture->getSize());
            }
        }
    }

    void TextWidget::calculateTextAlignment()
    {
        const auto   original_size   = m_text_texture->getSize();
        const auto   available_space = m_content;
        cymath::Size new_size        = original_size;

        // Text texture is bigger than the content, so it must be scaled down.
        if(original_size > available_space)
        {
            const float x_scale = cymath::scale(available_space.width, original_size.width);
            const float y_scale = cymath::scale(available_space.height, original_size.height);

            if(x_scale < y_scale)
            {
                new_size = original_size * x_scale;
            }
            else if(y_scale < x_scale)
            {
                new_size = original_size * y_scale;
            }
        }

        // When there is space left between text and the padding space we need to adjust the
        // alignment of the text. The default case of alignment top left is handled implicitly.
        {
            const auto horizontal_space = available_space.width - new_size.width;
            if(horizontal_space > 0)
            {
                const auto center = cystd::fromEnum(ALIGN::CENTER);
                const auto right  = cystd::fromEnum(ALIGN::RIGHT);

                if((cystd::fromEnum(m_alignment) & center) == center)
                {
                    m_alignment_offset.add(horizontal_space / 2, 0);
                }
                else if((cystd::fromEnum(m_alignment) & right) == right)
                {
                    m_alignment_offset.add(horizontal_space, 0);
                }
            }

            const auto vertical_space = available_space.height - new_size.height;
            if(vertical_space > 0)
            {
                const auto middle = cystd::fromEnum(ALIGN::MIDDLE);
                const auto bottom = cystd::fromEnum(ALIGN::BOTTOM);

                if((cystd::fromEnum(m_alignment) & middle) == middle)
                {
                    m_alignment_offset.add(0, vertical_space / 2);
                }
                else if((cystd::fromEnum(m_alignment) & bottom) == bottom)
                {
                    m_alignment_offset.add(0, vertical_space);
                }
            }
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
        calculateTextAlignment();

        auto renderer = cyvideo::GUIRenderManager::getRenderer();
        auto offset   = cymath::Point(0, 0);

        offset += {m_margin.left, m_margin.top};
        offset += {m_border.left, m_border.top};
        offset += {m_padding.left, m_padding.top};

        renderer->setRenderTarget(m_content_texture);

        // Draw background color of text.
        renderer->setDrawColor(m_text_bg_color);
        renderer->drawFilledRectangle({{0, 0}, m_content_texture->getSize()});

        offset += m_alignment_offset;

        // Draw the text.
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
