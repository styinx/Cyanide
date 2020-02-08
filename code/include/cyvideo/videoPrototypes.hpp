#ifndef CYANIDE_VIDEOPROTOTYPES_HPP
#define CYANIDE_VIDEOPROTOTYPES_HPP

#include "cystd/Types.hpp"

namespace cyanide::cyvideo
{
    class IFont;
    using IFontSPtr = SharedPtr<IFont>;

    class SDLFont;
    using SDLFontSPtr = SharedPtr<SDLFont>;

    class ISurface;
    using ISurfaceSPtr = SharedPtr<ISurface>;

    class SDLSurface;
    using SDLSurfaceSPtr = SharedPtr<SDLSurface>;

    class ITexture;
    using ITextureSPtr = SharedPtr<ITexture>;

    class SDLTexture;
    using SDLTextureSPtr = SharedPtr<SDLTexture>;

    class IRenderer;
    using IRendererSPtr = SharedPtr<IRenderer>;

    class SDLRenderer;
    using SDLRendererSPtr = SharedPtr<SDLRenderer>;

    class IWindow;
    using IWindowSPtr = SharedPtr<IWindow>;

    class SDLWindow;
    using SDLWindowSPtr = SharedPtr<SDLWindow>;

}

#endif //CYANIDE_VIDEOPROTOTYPES_HPP
