#ifndef CYANIDE_ILAYOUT_HPP
#define CYANIDE_ILAYOUT_HPP

#include "cygui/widgets/Object.hpp"

namespace cyanide::cygui
{

    class ILayout
    {
    public:
        virtual ~ILayout() = default;

        virtual void calculateChildren() = 0;
        virtual bool empty() const = 0;
        virtual size_t size() const = 0;
        virtual bool add(const ObjectSPtr& object) = 0;
        virtual bool insert(const ObjectSPtr& object, const int index) = 0;
        virtual bool remove(const int index) = 0;
        virtual bool erase(const ObjectSPtr& object) = 0;
    };

}

#endif //CYANIDE_ILAYOUT_HPP
