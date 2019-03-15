
#include <cygui/widgets/Object.hpp>

namespace cyanide
{
namespace cygui
{

    Object::Object(Object* parent)
        : m_parent(parent)
    {
    }

    Object& Object::setParent(Object* const parent)
    {
        m_parent = parent;
        if(parent->getChild() != this) parent->setChild(this);
        return *this;
    }

    Object* Object::getParent() const { return m_parent; }

    Object& Object::setChild(Object* const child)
    {
        m_child = child;
        if(child->getParent() != this) child->setParent(this);
        return *this;
    }

    Object* Object::getChild() const { return m_child; }

}  // namespace cygui
}  // namespace cyanide