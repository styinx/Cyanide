#include "cygui/styles/ObjectStyle.hpp"

#include "cyvideo/renderer/GUIRenderManager.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"

namespace cyanide::cygui
{

    ObjectStyle::ObjectStyle()
    {
        calculateTextures();
    }

    // Private

    void ObjectStyle::calculateTextures()
    {
        if(m_requires_texture_reload)
        {
            using cymath::Size;
            using cyvideo::SDLTexture;
            using cyvideo::SDLTextureSPtr;

            auto renderer = cyvideo::GUIRenderManager::getRenderer();

            if(renderer)
            {
                calculateSizes();

                m_texture         = SDLTexture::Create(renderer, m_size);
                m_border_texture  = SDLTexture::Create(renderer, m_size - m_margin);
                m_padding_texture = SDLTexture::Create(renderer, m_size - m_margin - m_border);
                m_content_texture = SDLTexture::Create(renderer, m_content);
            }

            m_requires_texture_reload = false;
        }
    }

    void ObjectStyle::calculateSizes()
    {
        if(m_content)
        {
            m_size = m_content + m_padding + m_border + m_margin;
        }
        else if(m_size)
        {
            const auto desired_content_size = m_size - m_margin - m_border - m_padding;
            if(desired_content_size)
            {
                m_content = desired_content_size;
            }
        }
    }

    // Public

    cymath::Rectangle ObjectStyle::getDimension() const
    {
        return {m_position, m_size};
    }

    void ObjectStyle::setDimension(const cymath::Rectangle& dimension)
    {
        if(dimension.getSize())
        {
            setPosition(dimension.getPosition());
            setSize(dimension.getSize());
        }
    }

    cymath::Point cygui::ObjectStyle::getPosition() const
    {
        return m_position;
    }

    void ObjectStyle::setPosition(const cymath::Point& position)
    {
        m_position = position;
    }

    cymath::Size cygui::ObjectStyle::getSize() const
    {
        return m_size;
    }

    void ObjectStyle::setSize(const cymath::Size& size)
    {
        if(size)
        {
            m_size = size;

            m_requires_texture_reload = true;
        }
    }

    cymath::Space ObjectStyle::getMargin() const
    {
        return m_margin;
    }

    void ObjectStyle::setMargin(const cymath::Space& margin)
    {
        m_margin = margin;

        m_requires_texture_reload = true;
    }

    cymath::Space ObjectStyle::getBorder() const
    {
        return m_border;
    }

    void ObjectStyle::setBorder(const cymath::Space& border)
    {
        m_border = border;

        m_requires_texture_reload = true;
    }

    cymath::Space ObjectStyle::getPadding() const
    {
        return m_padding;
    }

    void ObjectStyle::setPadding(const cymath::Space& padding)
    {
        m_padding = padding;

        m_requires_texture_reload = true;
    }

    cymath::Size ObjectStyle::getContentSize() const
    {
        return m_content;
    }

    void ObjectStyle::setBackgroundColor(const cyutil::RGBAColor& color)
    {
        m_background_color = color;
    }

    cyutil::RGBAColor ObjectStyle::getBackgroundColor() const
    {
        return m_background_color;
    }

    void ObjectStyle::setBorderColor(const cyutil::RGBAColor& color)
    {
        m_border_color = color;
    }

    cyutil::RGBAColor ObjectStyle::getBorderColor() const
    {
        return m_border_color;
    }

    void ObjectStyle::setContentSize(const cymath::Size& content_size)
    {
        if(content_size)
        {
            m_content = content_size;

            m_requires_texture_reload = true;
        }
    }

    void ObjectStyle::drawBorder()
    {
        auto renderer = cyvideo::GUIRenderManager::getRenderer();
        renderer->setDrawColor(m_border_color);
        renderer->setRenderTarget(m_border_texture);
        renderer->drawRectangle({{0, 0}, getSize() - m_margin});
        renderer->resetRenderTarget();
    }

    void ObjectStyle::drawBackground()
    {
        auto renderer = cyvideo::GUIRenderManager::getRenderer();
        renderer->setDrawColor(m_background_color);
        renderer->setRenderTarget(m_padding_texture);
        renderer->drawFilledRectangle({{0, 0}, m_content + m_padding});
        renderer->resetRenderTarget();
    }

}  // namespace cyanide::cygui
