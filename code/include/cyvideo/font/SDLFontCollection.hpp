#ifndef CYANIDE_SDLFONTCOLLECTION_HPP
#define CYANIDE_SDLFONTCOLLECTION_HPP

#include "cyvideo/videoPrototypes.hpp"

namespace cyanide::cyvideo
{

    class SDLFontCollection final
    {
    private:
        static UMap<String, SDLFont*> s_fonts;

        SDLFontCollection() = default;

    public:
        virtual ~SDLFontCollection() = default;

        static void     clearFont(const String& name);
        static SDLFont* getFont(const String& name, const Uint8 size = 0);
        static void     setFont(const String& name, SDLFont* font);
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLFONTCOLLECTION_HPP
