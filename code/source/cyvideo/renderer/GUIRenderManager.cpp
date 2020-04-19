#include "cyvideo/renderer/GUIRenderManager.hpp"

namespace cyanide::cyvideo
{

    cyvideo::SDLRendererSPtr GUIRenderManager::s_renderer = nullptr;

    void GUIRenderManager::createInstance(const cyvideo::SDLRendererSPtr& renderer)
    {
        GUIRenderManager::s_renderer = renderer;
    }

    cyvideo::SDLRendererSPtr& GUIRenderManager::getRenderer()
    {
        return GUIRenderManager::s_renderer;
    }

}  // namespace cyanide::cyvideo
