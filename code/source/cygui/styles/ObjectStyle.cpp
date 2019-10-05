#include "cygui/styles/ObjectStyle.hpp"

#include "cygui/GUIRenderManager.hpp"
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
            using cyvideo::SDLTexture;
            using cyvideo::SDLTextureSPtr;
            using cymath::Size;

            auto renderer = GUIRenderManager::getRenderer();

            m_texture        = SDLTextureSPtr(new SDLTexture(renderer, m_size));
            m_border_texture = SDLTextureSPtr(new SDLTexture(renderer, m_size - m_margin));
            m_padding_texture = SDLTextureSPtr(new SDLTexture(renderer, m_size - m_margin - m_border));
            m_content_texture = SDLTextureSPtr(new SDLTexture(renderer, m_content));

            m_requires_texture_reload = false;
        }
    }

    // Public

    cymath::Rectangle ObjectStyle::getDimension() const
    {
        return {m_position, m_size};
    }

    void ObjectStyle::setDimension(const cymath::Rectangle& dimension)
    {
        if(dimension.getSize() >= cymath::Size(0, 0))
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
        auto min_size = cymath::Size{0, 0};

        if(size >= min_size)
        {
            m_size = size;

            auto content_size = m_size - m_margin - m_border - m_padding;
            m_content = cymath::Size::max(min_size, content_size);

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

    void ObjectStyle::setContentSize(const cymath::Size& content_size)
    {
        if(content_size >= cymath::Size(0, 0))
        {
            m_content = content_size;
            m_size = m_content + m_padding + m_border + m_margin;

            m_requires_texture_reload = true;
        }
    }

    void ObjectStyle::drawBorder()
    {
        auto renderer = GUIRenderManager::getRenderer();
        renderer->setDrawColor(m_border_color);
        renderer->setRenderTarget(m_border_texture);
        renderer->drawRectangle({{0, 0}, getSize() - m_margin});
        renderer->resetRenderTarget();
    }

    void ObjectStyle::drawBackground()
    {
        auto renderer = GUIRenderManager::getRenderer();
        renderer->setDrawColor(m_background_color);
        renderer->setRenderTarget(m_padding_texture);
        renderer->drawFilledRectangle({{0, 0}, m_content + m_padding});
        renderer->resetRenderTarget();
    }

}  // namespace cyanide::cygui
