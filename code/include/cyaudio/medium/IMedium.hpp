#ifndef CYANIDE_IMEDIUM_HPP
#define CYANIDE_IMEDIUM_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cyaudio
{

    class IMedium
    {
    public:
        virtual ~IMedium()                                       = default;
        virtual const String getResource() const                 = 0;
        virtual void         setResource(const String& resource) = 0;
    };

    using IMediumPtr = SharedPtr<IMedium>;

}  // namespace cyanide::cyaudio

#endif  // CYANIDE_IMEDIUM_HPP
