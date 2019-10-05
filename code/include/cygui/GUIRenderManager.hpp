#ifndef CYANIDE_GUIRENDERMANAGER_HPP
#define CYANIDE_GUIRENDERMANAGER_HPP

#include "cyvideo/videoPrototypes.hpp"

namespace cyanide::cygui
{

    class GUIRenderManager final
    {
    private:
        static cyvideo::SDLRendererSPtr s_renderer;

        GUIRenderManager() = default;

    public:
        explicit GUIRenderManager(const cyvideo::SDLRendererSPtr& renderer);
        GUIRenderManager(const GUIRenderManager& GUIObjectManager)     = default;
        GUIRenderManager(GUIRenderManager&& GUIObjectManager) noexcept = default;
        GUIRenderManager& operator=(const GUIRenderManager& GUIObjectManager) = default;
        GUIRenderManager& operator=(GUIRenderManager&& GUIObjectManager) noexcept = default;
        virtual ~GUIRenderManager()                                               = default;

        static cyvideo::SDLRendererSPtr& getRenderer();
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_GUIRENDERMANAGER_HPP
