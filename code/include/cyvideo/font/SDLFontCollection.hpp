#ifndef CYANIDE_SDLFONTCOLLECTION_HPP
#define CYANIDE_SDLFONTCOLLECTION_HPP

#include <cyvideo/videoPrototypes.hpp>

namespace cyanide::cyvideo
{

    class SDLFontCollection final
    {
    private:
        static UMap<String, SDLFontSPtr> s_fonts;

        SDLFontCollection() = default;

    public:
        virtual ~SDLFontCollection() = default;

        static void         clearFont(const String& name);
        static SDLFontSPtr& getFont(const String& name);
        static void         setFont(const String& name, const SDLFontSPtr& font);
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLFONTCOLLECTION_HPP
