#include "cygui/GUIObjectManager.hpp"

namespace cyanide::cygui
{

    cyvideo::SDLRendererSPtr GUIObjectManager::s_renderer = nullptr;

    GUIObjectManager::GUIObjectManager(const cyvideo::SDLRendererSPtr& renderer)
    {
        GUIObjectManager::s_renderer = renderer;
    }

    cyvideo::SDLRendererSPtr& GUIObjectManager::getRenderer()
    {
        return GUIObjectManager::s_renderer;
    }

}