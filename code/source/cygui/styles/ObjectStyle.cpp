#include "cygui/styles/ObjectStyle.hpp"

#include "cygui/GUIObjectManager.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"

namespace cyanide::cygui
{

    ObjectStyle::ObjectStyle()
    {
        using namespace cyvideo;

        auto renderer = GUIObjectManager::getRenderer();
        auto size = getSize();

        m_texture = SDLTextureSPtr(new SDLTexture(renderer, size));
        m_border_texture = SDLTextureSPtr(new SDLTexture(renderer, size + m_margin));
        m_padding_texture = SDLTextureSPtr(new SDLTexture(renderer, size + m_margin + m_border));
        m_content_texture = SDLTextureSPtr(new SDLTexture(renderer, size + m_margin + m_border + m_padding));
    }

    cymath::Rectangle ObjectStyle::getDimension() const
    {
        return m_dimension;
    }

    void ObjectStyle::setDimension(const cymath::Rectangle& dimension)
    {
        if(dimension >= cymath::Rectangle(0, 0, 0, 0))
        {
            m_dimension = dimension;
        }
    }

    cymath::Point cygui::ObjectStyle::getPosition() const
    {
        return m_dimension.topLeft();
    }

    void ObjectStyle::setPosition(const cymath::Point& position)
    {
        m_dimension.set(position.x, position.y, m_dimension.w, m_dimension.h);
    }

    cymath::Size cygui::ObjectStyle::getSize() const
    {
        return m_dimension.getSize();
    }

    void ObjectStyle::setSize(const cymath::Size& size)
    {
        if(size >= cymath::Size(0, 0))
        {
            using namespace cyvideo;

            m_dimension.set(m_dimension.x, m_dimension.y, size.width, size.height);

            auto renderer = GUIObjectManager::getRenderer();
            auto s = size;

            m_content = s + m_margin + m_border + m_padding;

            m_texture         = SDLTextureSPtr(new SDLTexture(renderer, s));
            m_border_texture  = SDLTextureSPtr(new SDLTexture(renderer, s + m_margin));
            m_padding_texture = SDLTextureSPtr(new SDLTexture(renderer, s + m_margin + m_border));
            m_content_texture = SDLTextureSPtr(new SDLTexture(renderer, m_content));
        }
    }

    cymath::Space ObjectStyle::getMargin() const
    {
        return m_margin;
    }

    void ObjectStyle::setMargin(const cymath::Space& margin)
    {
        m_margin = margin;
    }

    cymath::Space ObjectStyle::getBorder() const
    {
        return m_border;
    }

    void ObjectStyle::setBorder(const cymath::Space& border)
    {
        m_border = border;
    }

    cymath::Space ObjectStyle::getPadding() const
    {
        return m_padding;
    }

    void ObjectStyle::setPadding(const cymath::Space& padding)
    {
        m_padding = padding;
    }

    cymath::Size ObjectStyle::getContentSize() const
    {
        return m_content;
    }

    void ObjectStyle::setContentSize(const cymath::Size& content_size)
    {
        if(content_size >= cymath::Size(0, 0))
        {
            using namespace cyvideo;

            m_content = content_size;

            auto renderer = GUIObjectManager::getRenderer();

            m_content_texture = SDLTextureSPtr(new SDLTexture(renderer, m_content));
        }
    }

    void ObjectStyle::drawBorder()
    {
        auto renderer = GUIObjectManager::getRenderer();
        renderer->setDrawColor(m_border_color);
        renderer->setRenderTarget(m_border_texture);
        renderer->drawRectangle({{0, 0}, getSize() + m_margin});   // todo draw rectangle with border size
        renderer->resetRenderTarget();
    }

    void ObjectStyle::drawBackground()
    {
        auto renderer = GUIObjectManager::getRenderer();
        renderer->setDrawColor(m_background_color);
        renderer->setRenderTarget(m_padding_texture);
        renderer->drawFilledRectangle({{0, 0}, m_content - m_padding});
        renderer->resetRenderTarget();
    }

    void ObjectStyle::draw()
    {
        auto renderer = GUIObjectManager::getRenderer();

        renderer->setRenderTarget(m_texture);
        renderer->drawSDLTexture(m_border_texture, {0, 0});
        renderer->drawSDLTexture(m_padding_texture, {0, 0});
        renderer->drawSDLTexture(m_content_texture, {0, 0});
        renderer->resetRenderTarget();
        renderer->drawSDLTexture(m_texture, getPosition());
    }

}  // namespace cyanide::cygui