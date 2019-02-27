#ifndef CYANIDE_IOBJECT_HPP
#define CYANIDE_IOBJECT_HPP

#include "cygui/styles/ObjectStyle.hpp"

namespace Cyanide
{
namespace cygui
{

    class Object : public ObjectStyle
    {
    private:
        Object* parent = nullptr;
        Object* child = nullptr;

    public:
        virtual ~Object() = default;

        virtual Object& setParent(const Object* parent);
        virtual Object* getParent() const;
        virtual Object& setChild(const Object* child);
        virtual Object* getChild() const;
    };

}  // namespace cygui
}  // namespace Cyanide

#endif  // CYANIDE_IOBJECT_HPP
