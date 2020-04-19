#ifndef CYANIDE_OBJECT_HPP
#define CYANIDE_OBJECT_HPP

#include "cygui/input/ObjectInput.hpp"
#include "cygui/styles/ObjectStyle.hpp"

namespace cyanide::cygui
{

    /**
     * @brief Base class for any other widget class in the cygui namespace.
     */
    class Object
        : public ObjectStyle
        , public ObjectInput
    {
    protected:
        Object* m_parent = nullptr;
        Object* m_child  = nullptr;

        Object();
        explicit Object(Object* parent);

    public:
        virtual Object& setParent(Object* const parent);
        virtual Object* getParent() const;
        virtual Object& setChild(Object* const child);
        virtual Object* getChild() const;
        virtual void    draw();

        /*
         * Inherited from IObjectInput
         */
        virtual void pollEvent(cyinput::SDLEventLoop& loop) override;
        virtual void onFocus(const cyinput::Callback& callback) override;
        virtual void onHover(const cyinput::Callback& callback) override;
        virtual void onClick(const cyinput::Callback& callback) override;
    };

    using ObjectSPtr = SharedPtr<Object>;

}  // namespace cyanide::cygui

#endif  // CYANIDE_OBJECT_HPP
