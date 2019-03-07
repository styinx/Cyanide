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
        SDLWindow(const char* title, Sint32 x, Sint32 y, Sint32 w, Sint32 h);

        SDLWindow(const char* title, cymath::Rectangle geometry);

        SDLWindow(const char* title, cymath::Point position, cymath::Size size);

        virtual ~SDLWindow() override = default;

        virtual IWindow& setTitle(const char* title) override;

        virtual const char* getTitle() const override;

        virtual cymath::Point getPosition() const override;

        virtual IWindow& setPosition(cymath::Point position) override;

        virtual cymath::Size getSize() const override;

        virtual IWindow& setSize(cymath::Size size) override;

        void createWindow(const char* title, Sint32 x, Sint32 y, Sint32 w, Sint32 h, Uint32 flags = SDL_WINDOW_SHOWN);

        void createWindow(const char* title, cymath::Rectangle geometry, Uint32 flags = SDL_WINDOW_SHOWN);

        void createWindow(const char* title, cymath::Point position, cymath::Size size, Uint32 flags = SDL_WINDOW_SHOWN);

        SDL_Window* getWindow() const;

        cymath::Rectangle getBorderSize() const;

        IWindow& setMinimumSize(cymath::Size size);

        IWindow& setMinimumSize(Sint32 w, Sint32 h);

        cymath::Size getMinimumSize() const;

        IWindow& setMaximumSize(cymath::Size size);

        IWindow& setMaximumSize(Sint32 w, Sint32 h);

        cymath::Size getMaximumSize() const;

        IWindow& setFlags(Uint32 flags);

        Uint32 getFlags() const;

        IWindow& setGrab(bool grabbed);

        bool getGrab() const;

        IWindow& setInputFocus();

        IWindow& setHitTest(SDL_HitTest callback, void* data);

        IWindow& show();

        IWindow& hide();

        IWindow& setBordered(bool bordered);

        IWindow& setBrightness(float brightness);

        float getBrightness() const;

        float getOpacity() const;

        IWindow& setOpacity(float opacity);

        IWindow& setFullScreen(Uint32 flag);

        IWindow& setGammaRamp(Uint16 r, Uint16 g, Uint16 b);

        Sint32 getID() const;

        IWindow& setIcon(SDL_Surface* icon);

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
