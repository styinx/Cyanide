#include "cyvideo/font/SDLFont.hpp"

#include "cyvideo/font/SDLFontCollection.hpp"

namespace cyanide::cyvideo
{

    SDLFont::SDLFont(const String& path, const Uint8 size)
    {
        openFont(path, size);

        //        Uint16 max_glyph = 255;
        //        for(Uint16 glyph = 0; glyph < max_glyph; ++glyph)
        //        {
        //            m_metrics[glyph] = getMetrics(glyph);
        //        }
    }

    SDLFont::~SDLFont()
    {
        closeFont();
    }

    // Private

    void SDLFont::loadFontInfo()
    {
        m_font_info.face_family = TTF_FontFaceFamilyName(m_font);
        m_font_info.face_style  = TTF_FontFaceStyleName(m_font);
        m_font_info.height      = static_cast<Uint32>(TTF_FontHeight(m_font));
        m_font_info.ascent      = static_cast<Uint32>(TTF_FontAscent(m_font));
        m_font_info.descent     = TTF_FontDescent(m_font);
        m_font_info.lineskip    = static_cast<Uint32>(TTF_FontLineSkip(m_font));
        m_font_info.faces       = static_cast<Uint64>(TTF_FontFaces(m_font));
        m_font_info.fixed       = (TTF_FontFaceIsFixedWidth(m_font) > 0);
        m_font_info.style       = static_cast<FONT_STYLE>(TTF_GetFontStyle(m_font));
        m_font_info.hinting     = static_cast<FONT_HINTING>(TTF_GetFontHinting(m_font));
        m_font_info.outline     = static_cast<Uint32>(TTF_GetFontOutline(m_font));
        m_font_info.kerning     = static_cast<Uint32>(TTF_GetFontKerning(m_font));
    }

    // Public

    SDLFont::operator bool()
    {
        return m_font != nullptr;
    }

    TTF_Font* SDLFont::getFont() const
    {
        return m_font;
    }

    void SDLFont::openFont(const String& path, const Uint8 size)
    {
        m_font             = TTF_OpenFont(path.c_str(), size);
        m_font_info.size_pt = size;

        if(m_font != nullptr)
        {
            loadFontInfo();
            SDLFontCollection::setFont(m_font_info.face_family, this);
        }
        else
        {
            //err
            int i = 0;
        }
    }

    void SDLFont::closeFont()
    {
        if(m_font != nullptr)
        {
            SDLFontCollection::clearFont(m_font_info.face_family);
            TTF_CloseFont(m_font);
            m_font = nullptr;
            m_font_info = SDLFontInfo{};
            m_metrics.clear();
        }
    }

    void SDLFont::setFontSize(const Uint8 size)
    {
        closeFont();
        openFont(m_font_info.path, size);
    }

    Uint8 SDLFont::getFontSize() const
    {
        return m_font_info.size_pt;
    }

    Uint32 SDLFont::getFontHeight() const
    {
        return m_font_info.height;
    }

    Uint32 SDLFont::getFontAscent() const
    {
        return m_font_info.ascent;
    }

    Sint32 SDLFont::getFontDescent() const
    {
        return m_font_info.descent;
    }

    Uint32 SDLFont::getFontLineSkip() const
    {
        return m_font_info.lineskip;
    }

    Uint64 SDLFont::getFontFaces() const
    {
        return m_font_info.faces;
    }

    bool SDLFont::isFixedWith() const
    {
        return m_font_info.fixed;
    }

    std::string SDLFont::getFontFamilyName() const
    {
        return m_font_info.face_family;
    }

    std::string SDLFont::getFontStyleName() const
    {
        return m_font_info.face_style;
    }

    FONT_STYLE SDLFont::getFontStyle() const
    {
        return m_font_info.style;
    }

    void SDLFont::setFontStyle(const FONT_STYLE& style)
    {
        TTF_SetFontStyle(m_font, static_cast<int>(style));
        m_font_info.style = style;
    }

    Uint32 SDLFont::getFontOutline() const
    {
        return m_font_info.outline;
    }

    void SDLFont::setFontOutline(const Sint32 outline)
    {
        TTF_SetFontOutline(m_font, outline);
        m_font_info.outline = static_cast<Uint32>(outline);
    }

    FONT_HINTING SDLFont::getFontHinting() const
    {
        return m_font_info.hinting;
    }

    void SDLFont::setFontHinting(const FONT_HINTING& hinting)
    {
        TTF_SetFontHinting(m_font, static_cast<int>(hinting));
        m_font_info.hinting = hinting;
    }

    Uint32 SDLFont::getFontKerning() const
    {
        return m_font_info.kerning;
    }

    void SDLFont::setFontKerning(const Sint32 kerning)
    {
        TTF_SetFontKerning(m_font, kerning);
        m_font_info.kerning = static_cast<Uint32>(kerning);
    }

    bool SDLFont::hasGlyph(const Uint16 character) const
    {
        return (TTF_GlyphIsProvided(m_font, character) > 0);
    }

    SDLCharMetrics SDLFont::getMetrics(const Uint16 character) const
    {
        SDLCharMetrics m = {};
        m.character = character;

        if(TTF_GlyphMetrics(m_font, m.character, &m.min_x, &m.max_x, &m.min_y, &m.max_y, &m.advance) == -1)
        {
            // err
        }

        return m;
    }

    cymath::Size SDLFont::getUTF8TextSize(const std::string& text) const
    {
        cymath::Size size{};

        if(TTF_SizeText(m_font, text.c_str(), &size.width, &size.height) == -1)
        {
            // err
        }

        return size;
    }

    cymath::Size SDLFont::getUnicodeTextSize(const WString& text) const
    {
        cymath::Size size{};

        std::vector<Uint16> characters(text.begin(), text.end());
        if(TTF_SizeUNICODE(m_font, characters.data(), &size.width, &size.height) == -1)
        {
            // err
        }

        return size;
    }
}
