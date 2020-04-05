#ifndef CYANIDE_OBJECTSTYLE_HPP
#define CYANIDE_OBJECTSTYLE_HPP

#include "cymath/Point.hpp"
#include "cymath/Rectangle.hpp"
#include "cymath/Size.hpp"
#include "cymath/Space.hpp"
#include "cystd/Types.hpp"
#include "cyutil/color/RGBAColor.hpp"
#include "cyvideo/SDLTexture.hpp"

namespace cyanide::cygui
{

    namespace Default
    {
        static const cymath::Space MARGIN  = cymath::Space{1, 1, 1, 1};
        static const cymath::Space BORDER  = cymath::Space{1, 1, 1, 1};
        static const cymath::Space PADDING = cymath::Space{1, 1, 1, 1};

        static const cyutil::RGBAColor BACKGROUND_COLOR = cyutil::RGBAColor{245, 245, 245, 255};
        static const cyutil::RGBAColor BORDER_COLOR     = cyutil::RGBAColor{200, 200, 200, 255};
    }  // namespace Default

    class ObjectStyle
    {
    protected:
        cymath::Point m_position;
        cymath::Size  m_size;
        cymath::Space m_margin  = Default::MARGIN;
        cymath::Space m_border  = Default::BORDER;
        cymath::Space m_padding = Default::PADDING;
        cymath::Size  m_content;

        bool m_requires_texture_reload = true;

        cyvideo::SDLTextureSPtr m_texture         = nullptr;
        cyvideo::SDLTextureSPtr m_border_texture  = nullptr;
        cyvideo::SDLTextureSPtr m_padding_texture = nullptr;
        cyvideo::SDLTextureSPtr m_content_texture = nullptr;

        cyutil::RGBAColor m_background_color = Default::BACKGROUND_COLOR;
        cyutil::RGBAColor m_border_color     = Default::BORDER_COLOR;

        ObjectStyle();

        /**
         * @brief Calculates new texture dimensions when sizes changes.
         */
        virtual void calculateTextures();

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
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_OBJECTSTYLE_HPP
