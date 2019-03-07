
#include <cyvideo/SDLWindow.hpp>

#include "cyvideo/SDLWindow.hpp"

namespace Cyanide
{
namespace cyvideo
{
    SDLWindow::SDLWindow(const char* title, Sint32 x, Sint32 y, Sint32 w, Sint32 h)
    {
        createWindow(title, x, y, w, h);
    }

    SDLWindow::SDLWindow(const char* title, cymath::Rectangle geometry)
    {
        createWindow(title, geometry);
    }

    SDLWindow::SDLWindow(const char* title, cymath::Point position, cymath::Size size)
    {
        createWindow(title, position, size);
    }

    IWindow& SDLWindow::setTitle(const char* title)
    {
        SDL_SetWindowTitle(m_window, title);
        return *this;
    }

    const char* SDLWindow::getTitle() const { return SDL_GetWindowTitle(m_window); }

    cymath::Point SDLWindow::getPosition() const
    {
        cymath::Point p;
        SDL_GetWindowPosition(m_window, &p.x, &p.y);
        return p;
    }

    IWindow& SDLWindow::setPosition(cymath::Point position)
    {
        SDL_SetWindowPosition(m_window, position.x, position.y);
        return *this;
    }

    cymath::Size SDLWindow::getSize() const
    {
        cymath::Size s;
        SDL_GetWindowSize(m_window, &s.width, &s.height);
        return s;
    }

    IWindow& SDLWindow::setSize(cymath::Size size)
    {
        SDL_SetWindowSize(m_window, size.width, size.height);
        return *this;
    }

    void SDLWindow::createWindow(const char* title, Sint32 x, Sint32 y, Sint32 w, Sint32 h, Uint32 flags)
    {
        if(m_window) SDL_DestroyWindow(m_window);
        m_window = SDL_CreateWindow(title, x, y, w, h, flags);
    }

    void SDLWindow::createWindow(const char* title, cymath::Rectangle geometry, Uint32 flags)
    {
        createWindow(title, geometry.x, geometry.y, geometry.w, geometry.h, flags);
    }

    void SDLWindow::createWindow(const char* title, cymath::Point position, cymath::Size size, Uint32 flags)
    {
        createWindow(title, position.x, position.y, size.width, size.height, flags);
    }

    SDL_Window* SDLWindow::getWindow() const { return m_window; }

    cymath::Rectangle SDLWindow::getBorderSize() const
    {
        cymath::Rectangle borders;
        SDL_GetWindowBordersSize(m_window, &borders.x, &borders.y, &borders.w, &borders.h);
        return borders;
    }

    IWindow& SDLWindow::setMinimumSize(cymath::Size size)
    {
        SDL_SetWindowMinimumSize(m_window, size.width, size.height);
        return *this;
    }

    IWindow& SDLWindow::setMinimumSize(Sint32 w, Sint32 h)
    {
        SDL_SetWindowMinimumSize(m_window, w, h);
        return *this;
    }

    cymath::Size SDLWindow::getMinimumSize() const
    {
        cymath::Size s;
        SDL_GetWindowMinimumSize(m_window, &s.width, &s.height);
        return s;
    }

    IWindow& SDLWindow::setMaximumSize(cymath::Size size)
    {
        SDL_SetWindowMaximumSize(m_window, size.width, size.height);
        return *this;
    }

    IWindow& SDLWindow::setMaximumSize(Sint32 w, Sint32 h)
    {
        SDL_SetWindowMaximumSize(m_window, w, h);
        return *this;
    }

    cymath::Size SDLWindow::getMaximumSize() const
    {
        cymath::Size s;
        SDL_GetWindowMaximumSize(m_window, &s.width, &s.height);
        return s;
    }

    IWindow& SDLWindow::setFlags(Uint32 flags)
    {
        if(m_flags != flags)
        {
            if(1)  //(SYSTEM::SDL::SDL_IS_INIT)
            {
                m_flags = flags;
                if(m_window != nullptr) SDL_DestroyWindow(m_window);

                createWindow(getTitle(), getPosition(), getSize(), flags);
            }
        }
        return *this;
    }

    Uint32 SDLWindow::getFlags() const { return m_flags; }

    IWindow& SDLWindow::setGrab(bool grabbed)
    {
        SDL_SetWindowGrab(m_window, static_cast<SDL_bool>(grabbed));
        return *this;
    }

    bool SDLWindow::getGrab() const { return SDL_GetWindowGrab(m_window); }

    IWindow& SDLWindow::setInputFocus()
    {
        SDL_SetWindowInputFocus(m_window);
        return *this;
    }

    IWindow& SDLWindow::setHitTest(SDL_HitTest callback, void* data)
    {
        SDL_SetWindowHitTest(m_window, callback, data);
        return *this;
    }

    IWindow& SDLWindow::show()
    {
        SDL_ShowWindow(m_window);
        return *this;
    }

    IWindow& SDLWindow::hide()
    {
        SDL_HideWindow(m_window);
        return *this;
    }

    IWindow& SDLWindow::setBordered(bool bordered)
    {
        SDL_SetWindowBordered(m_window, static_cast<SDL_bool>(bordered));
        return *this;
    }

    IWindow& SDLWindow::setBrightness(float brightness)
    {
        SDL_SetWindowBrightness(m_window, brightness);
        return *this;
    }

    float SDLWindow::getBrightness() const { return SDL_GetWindowBrightness(m_window); }

    IWindow& SDLWindow::setOpacity(float opacity)
    {
        SDL_SetWindowOpacity(m_window, opacity);
        return *this;
    }

    float SDLWindow::getOpacity() const
    {
        float opacity;
        SDL_GetWindowOpacity(m_window, &opacity);
        return opacity;
    }

    IWindow& SDLWindow::setFullScreen(Uint32 flag)
    {
        SDL_SetWindowFullscreen(m_window, flag);
        return *this;
    }

    IWindow& SDLWindow::setGammaRamp(Uint16 r, Uint16 g, Uint16 b) {}

    Sint32 SDLWindow::getID() const { return 0; }

    IWindow& SDLWindow::setIcon(SDL_Surface* icon) {}

    void SDLWindow::pollEvent()  // SDL_Event* event)
    {
        //        m_exposed = false;
        //
        //        if(event->type == SDL_WINDOWEVENT_SHOWN) { m_shown = true; }
        //        else if(event->type == SDL_WINDOWEVENT_HIDDEN)
        //        {
        //            m_shown = false;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_EXPOSED)
        //        {
        //            m_exposed = true;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_MINIMIZED)
        //        {
        //            minimized = true;
        //            m_maximized = false;
        //            m_restored  = false;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_MAXIMIZED)
        //        {
        //            m_maximized = true;
        //            minimized = false;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_RESTORED)
        //        {
        //            m_restored = true;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_ENTER)
        //        {
        //            m_mouse_focus = true;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_LEAVE)
        //        {
        //            m_mouse_focus = false;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_FOCUS_GAINED)
        //        {
        //            m_focus = true;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_FOCUS_LOST)
        //        {
        //            m_focus = false;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_CLOSE)
        //        {
        //            closed = true;
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_MOVED)
        //        {
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_RESIZED)
        //        {
        //        }
        //        else if(event->type == SDL_WINDOWEVENT_SIZE_CHANGED)
        //        {
        //        }
    }

    bool SDLWindow::isShown() const { return m_shown; }

    bool SDLWindow::isExposed() const { return m_exposed; }

    bool SDLWindow::isRestored() const { return m_restored; }

    bool SDLWindow::isMinimized() const { return m_minimized; }

    bool SDLWindow::isMaximized() const { return m_maximized; }

    bool SDLWindow::hasMouseFocus() const { return m_mouse_focus; }

    bool SDLWindow::isFocus() const { return m_focus; }

    bool SDLWindow::isClosed() const { return m_closed; }

}  // namespace cyvideo
}  // namespace Cyanide