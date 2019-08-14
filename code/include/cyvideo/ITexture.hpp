#ifndef CYANIDE_ITEXTURE_HPP
#define CYANIDE_ITEXTURE_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cyvideo
{

    class ITexture
    {
    public:
        virtual ~ITexture() = default;
    };

    using ITextureSPtr = SharedPtr<ITexture>;

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_ITEXTURE_HPP
