#ifndef CYANIDE_BOX_HPP
#define CYANIDE_BOX_HPP

#include "cygui/layout/IBox.hpp"
#include "cygui/styles/BoxStyle.hpp"
#include "cygui/styles/Styles.hpp"

namespace cyanide::cygui
{

    class Box
        : public IBox
        , public Object
        , public BoxStyle
    {
    protected:
        bool               m_children_changed = false;
        ORIENTATION        m_orientation      = ORIENTATION::HORIZONTAL;
        Vector<ObjectSPtr> m_children;

        explicit Box(ORIENTATION orientation = ORIENTATION::HORIZONTAL);

    public:
        virtual ~Box() = default;

        /*
         * Inherited from IBox
         */
        virtual ORIENTATION getOrientation();
        virtual void        calculateChildren() override;
        virtual bool        empty() const override;
        virtual size_t      size() const override;
        virtual bool        add(const ObjectSPtr& object) override;
        virtual bool        insert(const ObjectSPtr& object, const int index) override;
        virtual bool        remove(const int index) override;
        virtual bool        erase(const ObjectSPtr& object) override;

        /*
         * Inherited from Object
         */
        virtual void draw() override;
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_BOX_HPP
