#ifndef CYANIDE_SDLFONT_HPP
#define CYANIDE_SDLFONT_HPP

#include "cymath/Size.hpp"
#include "cyutil/color/RGBAColor.hpp"
#include "cyvideo/font/IFont.hpp"
#include "cyvideo/videoPrototypes.hpp"

#include <SDL2/SDL_ttf.h>
#include <string>

namespace cyanide::cyvideo
{

    /**
     * Hinting is responsible for edge smoothing and contrast
     */
    enum class FONT_HINTING : Byte
    {
        NORMAL = TTF_HINTING_NORMAL,
        LIGHT  = TTF_HINTING_LIGHT,
        MONO   = TTF_HINTING_MONO,
        NONE   = TTF_HINTING_NONE,
    };

    /**
     * Font style defines the appearance of letters.
     */
    enum class FONT_STYLE : Byte
    {
        NORMAL                  = TTF_STYLE_NORMAL,
        BOLD                    = TTF_STYLE_BOLD,
        ITALIC                  = TTF_STYLE_ITALIC,
        UNDERLINED              = TTF_STYLE_UNDERLINE,
        STRIKED                 = TTF_STYLE_STRIKETHROUGH,
        BOLD_UNDERLINED         = TTF_STYLE_BOLD | TTF_STYLE_UNDERLINE,
        BOLD_STRIKED            = TTF_STYLE_BOLD | TTF_STYLE_STRIKETHROUGH,
        BOLD_UNDERLINED_STRIKED = TTF_STYLE_BOLD | TTF_STYLE_UNDERLINE | TTF_STYLE_STRIKETHROUGH,
        BOLD_ITALIC             = TTF_STYLE_BOLD | TTF_STYLE_ITALIC,
        BOLD_ITALIC_UNDERLINED  = TTF_STYLE_BOLD | TTF_STYLE_ITALIC | TTF_STYLE_UNDERLINE,
        BOLD_ITALIC_STRIKED     = TTF_STYLE_BOLD | TTF_STYLE_ITALIC | TTF_STYLE_STRIKETHROUGH,
        BOLD_ITALIC_UNDERLINED_STRIKED =
            TTF_STYLE_BOLD | TTF_STYLE_ITALIC | TTF_STYLE_UNDERLINE | TTF_STYLE_STRIKETHROUGH,
        ITALIC_UNDERLINED         = TTF_STYLE_ITALIC | TTF_STYLE_UNDERLINE,
        ITALIC_STRIKED            = TTF_STYLE_ITALIC,
        ITALIC_UNDERLINED_STRIKED = TTF_STYLE_ITALIC | TTF_STYLE_UNDERLINE | TTF_STYLE_STRIKETHROUGH,
        UNDERLINED_STRIKED        = TTF_STYLE_UNDERLINE | TTF_STYLE_STRIKETHROUGH
    };

    enum class RENDER_TYPE : Byte
    {
        SOLID   = 0x00,
        SHADED  = 0x01,
        BLENDED = 0x02
    };

    namespace Default
    {
        const Uint8        SIZE_PT = 12;
        const FONT_STYLE   STYLE   = FONT_STYLE::NORMAL;
        const FONT_HINTING HININTG = FONT_HINTING::NORMAL;
    }  // namespace Default

    struct SDLFontInfo
    {
        String       face_family;
        String       face_style;
        String       path;
        Uint8        size_pt  = Default::SIZE_PT;
        Uint32       height   = 0;
        Uint32       ascent   = 0;
        Sint32       descent  = 0;
        Uint32       lineskip = 0;
        Uint64       faces    = 0;
        bool         fixed    = false;
        FONT_STYLE   style    = Default::STYLE;
        FONT_HINTING hinting  = Default::HININTG;
        Uint32       outline  = 0;
        Uint32       kerning  = 0;
    };

    struct SDLCharMetrics
    {
        wchar_t character;
        Sint32  min_x;    // left starting position of the character
        Sint32  max_x;    // right ending position of the character
        Sint32  min_y;    // bottom starting position of the character
        Sint32  max_y;    // top ending position of the character
        Sint32  advance;  // complete vertical space a character consumes
    };

    class SDLFont final : public IFont
    {
    private:
        TTF_Font*                    m_font = nullptr;
        SDLFontInfo                  m_font_info{};
        UMap<Uint16, SDLCharMetrics> m_metrics;

        void loadFontInfo();

    public:
        explicit SDLFont(const String& path, const Uint8 size);
        virtual ~SDLFont();

        explicit operator bool();

        void           openFont(const String& path, const Uint8 size);
        void           closeFont();
        TTF_Font*      getFont() const;
        void           setFontSize(const Uint8 size);
        Uint8          getFontSize() const;
        Uint32         getFontHeight() const;
        Uint32         getFontAscent() const;
        Sint32         getFontDescent() const;
        Uint32         getFontLineSkip() const;
        Uint64         getFontFaces() const;
        bool           isFixedWith() const;
        String         getFontFamilyName() const;
        String         getFontStyleName() const;
        FONT_STYLE     getFontStyle() const;
        void           setFontStyle(const FONT_STYLE& style);
        Uint32         getFontOutline() const;
        void           setFontOutline(const Sint32 outline);
        FONT_HINTING   getFontHinting() const;
        void           setFontHinting(const FONT_HINTING& hinting);
        Uint32         getFontKerning() const;
        void           setFontKerning(const Sint32 kerning);
        bool           hasGlyph(const Uint16 character) const;
        SDLCharMetrics getMetrics(const Uint16 character) const;
        cymath::Size   getUTF8TextSize(const String& text) const;
        cymath::Size   getUnicodeTextSize(const WString& text) const;

        SDLTextureSPtr render(const String& text, const cyutil::RGBAColor& color, const RENDER_TYPE type) const;
        SDLTextureSPtr render(const WString& text, const cyutil::RGBAColor& color, const RENDER_TYPE type) const;
    };

    using SDLFontSPtr = SharedPtr<SDLFont>;

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLFONT_HPP
