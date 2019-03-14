
#include <cygui/widgets/Object.hpp>

namespace Cyanide
{
namespace cygui
{

    Object& Object::setParent(Object* const parent)
    {
        m_parent = parent;
        if(parent->getChild() != this)
            parent->setChild(this);
        return *this;
    }

    Object* Object::getParent() const
    {
        return nullptr;
    }

    Object& Object::setChild(Object* const child)
    {
        m_child = child;
        if(child->getParent() != this)
            child->setParent(this);
        return *this;
    }

    Object* Object::getChild() const
    {
        return nullptr;
    }

}  // namespace cygui
}  // namespace Cyanide