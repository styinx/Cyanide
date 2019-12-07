#ifndef CYANIDE_IBOX_HPP
#define CYANIDE_IBOX_HPP

#include "cygui/layout/ILayout.hpp"

namespace cyanide::cygui
{

    class IBox : public ILayout
    {
    public:
        /*
         * Inherited from ILayout
         */
        virtual void   calculateChildren() = 0;
        virtual bool   empty() const = 0;
        virtual size_t size() const = 0;
        virtual bool   add(const ObjectSPtr& object) = 0;
        virtual bool   insert(const ObjectSPtr& object, const int index) = 0;
        virtual bool   remove(const int index) = 0;
        virtual bool   erase(const ObjectSPtr& object) = 0;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_IBOX_HPP
