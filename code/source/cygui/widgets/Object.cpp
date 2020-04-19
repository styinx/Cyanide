#include "cygui/widgets/Object.hpp"

#include "cystd/Enum.hpp"
#include "cyvideo/renderer/GUIRenderManager.hpp"
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

        auto renderer = cyvideo::GUIRenderManager::getRenderer();
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

    void Object::pollEvent(cyinput::SDLEventLoop& loop)
    {
        loop.mouse()->onAnyMouseEvent([this](const SDL_Event& event) {
            m_event_mask ^= cystd::fromEnum(EVENT::FOCUS_GAINED);
            m_event_mask ^= cystd::fromEnum(EVENT::FOCUS_LOST);
            m_event_mask ^= cystd::fromEnum(EVENT::ENTER);
            m_event_mask ^= cystd::fromEnum(EVENT::LEAVE);

            if(event.type == SDL_MOUSEMOTION)
            {
                cymath::Point     mouse{event.motion.x, event.motion.y};
                cymath::Rectangle dim{m_position, m_size};
                if(mouse >= dim.topLeft() && mouse <= dim.bottomRight())
                {
                    if(!m_is_hovered)
                    {
                        if(!(m_event_mask & cystd::fromEnum(EVENT::ENTER)))
                        {
                            m_is_hovered = true;
                            m_event_mask |= cystd::fromEnum(EVENT::ENTER);
                            enter();
                        }
                    }

                    // Logging::print("on move\n");
                }
                else
                {
                    if(m_is_hovered)
                    {
                        m_is_hovered = false;
                        m_event_mask |= cystd::fromEnum(EVENT::LEAVE);
                        // Logging::print("on leave\n");
                    }
                }
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                cymath::Point     mouse{event.motion.x, event.motion.y};
                cymath::Rectangle dim{m_position, m_size};
                if(mouse >= dim.topLeft() && mouse <= dim.bottomRight())
                {
                    m_event_mask |= cystd::fromEnum(EVENT::CLICK);
                    click();

                    if(!m_has_focus)
                    {
                        m_has_focus = true;
                        m_event_mask |= cystd::fromEnum(EVENT::FOCUS_GAINED);
                        focusGained();
                    }
                }
                else
                {
                    if(m_has_focus)
                    {
                        m_has_focus = false;
                        m_event_mask |= cystd::fromEnum(EVENT::FOCUS_LOST);
                        // Logging::print("on focus lost\n");
                    }
                }
            }
            else if(event.type == SDL_MOUSEBUTTONUP)
            {
                cymath::Point     mouse{event.motion.x, event.motion.y};
                cymath::Rectangle dim{m_position, m_size};
                if(mouse >= dim.topLeft() && mouse <= dim.bottomRight())
                {
                    m_event_mask ^= cystd::fromEnum(EVENT::CLICK);
                    // Logging::print("on click up\n");
                }
            }
        });
    }
    void Object::onFocus(const cyinput::Callback& callback)
    {
        m_focus_callback = callback;
    }

    void Object::onHover(const cyinput::Callback& callback)
    {
        m_hover_callback = callback;
    }

    void Object::onClick(const cyinput::Callback& callback)
    {
        m_click_callback = callback;
    }

}  // namespace cyanide::cygui
