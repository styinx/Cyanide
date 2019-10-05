#include "cygui/widgets/Object.hpp"

#include "cygui/GUIRenderManager.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"

namespace cyanide::cygui
{

    Object::Object()
        : ObjectStyle()
        , m_parent(nullptr)
        , m_child(nullptr)
    {
    }

    Object::Object(Object* parent)
        : ObjectStyle()
        , m_parent(parent)
        , m_child(nullptr)
    {
    }

    Object& Object::setParent(Object* const parent)
    {
        m_parent = parent;
        if(parent->getChild() != this)
        {
            parent->setChild(this);
        }
        return *this;
    }

    Object* Object::getParent() const
    {
        return m_parent;
    }

    Object& Object::setChild(Object* const child)
    {
        m_child = child;
        if(child->getParent() != this)
        {
            child->setParent(this);
        }
        return *this;
    }

    Object* Object::getChild() const
    {
        return m_child;
    }

    void Object::draw()
    {
        calculateTextures();

        drawBorder();
        drawBackground();

        auto renderer = GUIRenderManager::getRenderer();
        auto offset   = cymath::Point(0, 0);

        renderer->setRenderTarget(m_texture);

        offset += {m_margin.left, m_margin.top};
        renderer->drawSDLTexture(m_border_texture, offset);
        offset += {m_border.left, m_border.top};
        renderer->drawSDLTexture(m_padding_texture, offset);
        offset += {m_padding.left, m_padding.top};
        renderer->drawSDLTexture(m_content_texture, offset);

        renderer->resetRenderTarget();
        renderer->drawSDLTexture(m_texture, getPosition());
    }

}  // namespace cyanide::cygui
