#ifndef CYANIDE_OBJECT_HPP
#define CYANIDE_OBJECT_HPP

#include "cygui/styles/ObjectStyle.hpp"

namespace cyanide
{
namespace cygui
{

    class Object : public ObjectStyle
    {
    private:
        Object* m_parent = nullptr;
        Object* m_child = nullptr;

    public:
        Object() = default;
        Object(Object* parent);
        Object(const Object& object) = default;
        Object(Object&& object) noexcept = default;
        Object& operator=(const Object& object) = default;
        Object& operator=(Object&& object) noexcept = default;
        virtual ~Object() = default;

        virtual Object& setParent(Object* const parent);
        virtual Object* getParent() const;
        virtual Object& setChild(Object* const child);
        virtual Object* getChild() const;
    };

}  // namespace cygui
}  // namespace cyanide

#endif  // CYANIDE_OBJECT_HPP
