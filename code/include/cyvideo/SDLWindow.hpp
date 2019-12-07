#ifndef CYANIDE_SDLWINDOW_HPP
#define CYANIDE_SDLWINDOW_HPP

#include "IWindow.hpp"

#include <SDL2/SDL_video.h>

#include "cymath/Rectangle.hpp"
#include "cymath/Size.hpp"

namespace Cyanide
{
namespace cyvideo
{

    class SDLWindow final : public IWindow
    {
    private:
        bool        m_shown       = false;
        bool        m_exposed     = false;
        bool        m_restored    = false;
        bool        m_minimized   = false;
        bool        m_maximized   = false;
        bool        m_mouse_focus = false;
        bool        m_focus       = false;
        bool        m_closed      = false;
        Uint32      m_flags       = 0x0;
        SDL_Window* m_window      = nullptr;

    public:
        SDLWindow(const char* title, const Sint32 x, const Sint32 y, const Sint32 w, const Sint32 h);

        SDLWindow(const char* title, const cymath::Rectangle geometry);

        SDLWindow(const char* title, const cymath::Point position, const cymath::Size size);

        virtual ~SDLWindow() override = default;

        virtual IWindow& setTitle(const char* title) override;

        virtual const char* getTitle() const override;

        virtual cymath::Point getPosition() const override;

        virtual IWindow& setPosition(const cymath::Point position) override;

        virtual cymath::Size getSize() const override;

        virtual IWindow& setSize(const cymath::Size size) override;

        void createWindow(
            const char* title,
            const Sint32 x,
            const Sint32 y,
            const Sint32 w,
            const Sint32 h,
            const Uint32 flags = SDL_WINDOW_SHOWN);

        void createWindow(
            const char* title,
            const cymath::Rectangle geometry,
            const Uint32 flags = SDL_WINDOW_SHOWN);

        void createWindow(
            const char* title,
            const cymath::Point position,
            const cymath::Size size,
            const Uint32 flags = SDL_WINDOW_SHOWN);

        SDL_Window* getWindow() const;

        cymath::Rectangle getBorderSize() const;

        IWindow& setMinimumSize(const cymath::Size size);

        IWindow& setMinimumSize(const Sint32 w, const Sint32 h);

        cymath::Size getMinimumSize() const;

        IWindow& setMaximumSize(const cymath::Size size);

        IWindow& setMaximumSize(const Sint32 w, const Sint32 h);

        cymath::Size getMaximumSize() const;

        IWindow& setFlags(const Uint32 flags);

        Uint32 getFlags() const;

        IWindow& setGrab(bool grabbed);

        bool getGrab() const;

        IWindow& setInputFocus();

        IWindow& setHitTest(const SDL_HitTest callback, void* const data);

        IWindow& show();

        IWindow& hide();

        IWindow& setBordered(const bool bordered);

        IWindow& setBrightness(const float brightness);

        float getBrightness() const;

        float getOpacity() const;

        IWindow& setOpacity(const float opacity);

        IWindow& setFullScreen(const Uint32 flag);

        IWindow& setGammaRamp(const Uint16 r, const Uint16 g, const Uint16 b);

        Sint32 getID() const;

        IWindow& setIcon(SDL_Surface* const icon);

        void pollEvent();  // SDL_Event* event);

        bool isShown() const;

        bool isExposed() const;

        bool isRestored() const;

        bool isMinimized() const;

        bool isMaximized() const;

        bool hasMouseFocus() const;

        bool isFocus() const;

        bool isClosed() const;
    };

}  // namespace cyvideo
}  // namespace Cyanide

#endif  // CYANIDE_SDLWINDOW_HPP