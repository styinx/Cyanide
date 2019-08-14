#ifndef CYANIDE_GUIOBJECTMANAGER_HPP
#define CYANIDE_GUIOBJECTMANAGER_HPP

#include "cyvideo/videoPrototypes.hpp"

namespace cyanide::cygui
{

    class GUIObjectManager final
    {
    private:
        static cyvideo::SDLRendererSPtr s_renderer;

        GUIObjectManager() = default;

    public:
        explicit GUIObjectManager(const cyvideo::SDLRendererSPtr& renderer);
        GUIObjectManager(const GUIObjectManager& GUIObjectManager)     = default;
        GUIObjectManager(GUIObjectManager&& GUIObjectManager) noexcept = default;
        GUIObjectManager& operator=(const GUIObjectManager& GUIObjectManager) = default;
        GUIObjectManager& operator=(GUIObjectManager&& GUIObjectManager) noexcept = default;
        virtual ~GUIObjectManager()                                               = default;

        static cyvideo::SDLRendererSPtr& getRenderer();
    };

}  // namespace cyanide::cygui

#endif  // CYANIDE_GUIOBJECTMANAGER_HPP
