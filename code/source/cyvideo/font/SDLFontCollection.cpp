#include "cyvideo/font/SDLFontCollection.hpp"

namespace cyanide::cyvideo
{

    UMap<String, SDLFont*> SDLFontCollection::s_fonts = {};

    /*static*/
    void SDLFontCollection::clearFont(const String& name)
    {
        if(s_fonts.count(name))
        {
            s_fonts.erase(name);
        }
    }

    /*static*/
    SDLFont* SDLFontCollection::getFont(const String& name)
    {
        return s_fonts[name];
    }

    /*static*/
    void SDLFontCollection::setFont(const String& name, SDLFont* font)
    {
        s_fonts[name] = font;
    }

}
