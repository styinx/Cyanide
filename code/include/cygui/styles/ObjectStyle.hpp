#ifndef CYANIDE_OBJECTSTYLE_HPP
#define CYANIDE_OBJECTSTYLE_HPP

#include "cymath/Point.hpp"
#include "cymath/Size.hpp"
#include "cymath/Space.hpp"
#include "cystd/stdPrototypes.hpp"
#include "cyvideo/SDLTexture.hpp"
#include "cyvideo/color/RGBAColor.hpp"

#include <cymath/Rectangle.hpp>

namespace cyanide::cygui
{

    namespace Default
    {
        const cymath::Space MARGIN  = cymath::Space{1, 1, 1, 1};
        const cymath::Space BORDER  = cymath::Space{1, 1, 1, 1};
        const cymath::Space PADDING = cymath::Space{1, 1, 1, 1};

        const cyvideo::RGBAColor BACKGROUND_COLOR = cyvideo::RGBAColor{245, 245, 245, 255};
        const cyvideo::RGBAColor BORDER_COLOR     = cyvideo::RGBAColor{200, 200, 200, 255};
    }  // namespace Default

    class ObjectStyle
    {
    protected:
        cymath::Rectangle m_dimension;
        cymath::Space     m_margin  = Default::MARGIN;
        cymath::Space     m_border  = Default::BORDER;
        cymath::Space     m_padding = Default::PADDING;
        cymath::Size      m_content;

        cyvideo::SDLTextureSPtr m_texture         = nullptr;
        cyvideo::SDLTextureSPtr m_border_texture  = nullptr;
        cyvideo::SDLTextureSPtr m_padding_texture = nullptr;
        cyvideo::SDLTextureSPtr m_content_texture = nullptr;

        cyvideo::RGBAColor m_background_color = Default::BACKGROUND_COLOR;
        cyvideo::RGBAColor m_border_color     = Default::BORDER_COLOR;

        ObjectStyle();

    public:
        virtual ~ObjectStyle() = default;

        virtual cymath::Rectangle getDimension() const;
        virtual void              setDimension(const cymath::Rectangle& dimension);
        virtual cymath::Point     getPosition() const;
        virtual void              setPosition(const cymath::Point& position);
        virtual cymath::Size      getSize() const;
        virtual void              setSize(const cymath::Size& size);
        virtual cymath::Space     getMargin() const;
        virtual void              setMargin(const cymath::Space& margin);
        virtual cymath::Space     getBorder() const;
        virtual void              setBorder(const cymath::Space& border);
        virtual cymath::Space     getPadding() const;
        virtual void              setPadding(const cymath::Space& padding);
        virtual cymath::Size      getContentSize() const;

        /**
         * @brief   Sets the inner content to the given size. This modifies also the
         *          available space of the whole object.
         * @param content_size
         */
        virtual void setContentSize(const cymath::Size& content_size);

        /**
         * @brief Draws the border onto the border texture.
         */
        virtual void drawBorder();

        /**
         * @brief Draws the background color onto the background texture.
         */
        virtual void drawBackground();
        virtual void draw();
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_OBJECTSTYLE_HPP
