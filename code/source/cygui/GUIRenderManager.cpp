#include "cygui/GUIRenderManager.hpp"

namespace cyanide::cygui
{

    cyvideo::SDLRendererSPtr GUIRenderManager::s_renderer = nullptr;

    GUIRenderManager::GUIRenderManager(const cyvideo::SDLRendererSPtr& renderer)
    {
        GUIRenderManager::s_renderer = renderer;
    }

    cyvideo::SDLRendererSPtr& GUIRenderManager::getRenderer()
    {
        return GUIRenderManager::s_renderer;
    }

}