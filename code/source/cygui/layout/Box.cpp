#include "cygui/layout/Box.hpp"

namespace cyanide::cygui
{

    Box::Box(ORIENTATION orientation)
        : m_orientation(orientation)
    {

    }

    ORIENTATION Box::getOrientation()
    {
        return m_orientation;
    }

    void Box::calculateChildren()
    {
        if(m_children_changed)
        {
            cymath::Point     child_offset = m_position;
            cymath::Rectangle child_dimension;

            // Store the offset of a child in x,y and the size of a child in w,h.
            if(m_orientation == ORIENTATION::HORIZONTAL)
            {
                float width = static_cast<float>(m_size.width) / m_children.size();
                child_dimension.w = static_cast<Sint32>(width);
                child_dimension.h = m_size.height;
                child_dimension.x = child_dimension.w;

                child_dimension.setPosition({child_dimension.w, 0});
            }
            else if(m_orientation == ORIENTATION::VERTICAL)
            {
                float height = static_cast<float>(m_size.height) / m_children.size();
                child_dimension.w = m_size.width;
                child_dimension.h = static_cast<Sint32>(height);
                child_dimension.y = child_dimension.h;

                child_dimension.setPosition({0, child_dimension.h});
            }

            for(const auto& child: m_children)
            {
                child->setDimension(cymath::Rectangle(child_offset, child_dimension.getSize()));

                child_offset += child_dimension.topLeft();
            }

            m_children_changed = false;
        }
    }

    bool Box::empty() const
    {
        return m_children.empty();
    }

    size_t Box::size() const
    {
        return m_children.size();
    }

    bool Box::add(const ObjectSPtr& object)
    {
        if(object != nullptr)
        {
            m_children.emplace_back(object);

            m_children_changed = true;
            calculateChildren();

            return true;
        }
        return false;
    }

    bool Box::insert(const ObjectSPtr& object, const int index)
    {
        if(object != nullptr)
        {
            if(index < 0)
            {
                m_children.insert(std::max(m_children.begin(), m_children.end() + index), object);
            }
            else
            {
                m_children.insert(std::min(m_children.begin() + index, m_children.end()), object);
            }

            m_children_changed = true;
            calculateChildren();

            return true;
        }
        return false;
    }

    bool Box::remove(const int index)
    {
        if(!m_children.empty())
        {
            if(index < 0)
            {
                m_children.erase(std::max(m_children.begin(), m_children.end() + index));
            }
            else
            {
                m_children.erase(std::min(m_children.begin() + index, m_children.end()));
            }

            m_children_changed = true;
            calculateChildren();

            return true;
        }
        return false;
    }

    bool Box::erase(const ObjectSPtr& object)
    {
        if(object != nullptr)
        {
            m_children.erase(std::find(m_children.begin(), m_children.end(), object));

            m_children_changed = true;
            calculateChildren();

            return true;
        }
        return false;
    }

    void Box::draw()
    {
        calculateChildren();

        for(const auto& child : m_children)
        {
            child->draw();
        }
    }

}
