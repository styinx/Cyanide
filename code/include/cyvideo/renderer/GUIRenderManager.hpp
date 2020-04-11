#ifndef CYANIDE_GUIRENDERMANAGER_HPP
#define CYANIDE_GUIRENDERMANAGER_HPP

#include "cyvideo/videoPrototypes.hpp"

namespace cyanide::cyvideo
{

    class GUIRenderManager final
    {
    private:
        static cyvideo::SDLRendererSPtr s_renderer;

        GUIRenderManager() = default;

    public:
        static void                      createInstance(const cyvideo::SDLRendererSPtr& renderer);
        static cyvideo::SDLRendererSPtr& getRenderer();
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_GUIRENDERMANAGER_HPP
