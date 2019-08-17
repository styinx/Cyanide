
#include <cyvideo/window/SDLWindow.hpp>

namespace cyanide::cyvideo
{
    SDLWindow::SDLWindow(
        const String&        title,
        const cymath::Point& pos,
        const cymath::Size&  size)
    {
        createWindow(title, pos, size);
    }
    
    void SDLWindow::createWindow(
        const String&        title,
        const cymath::Point& pos,
        const cymath::Size&  size,
        const Uint32        flags)
    {
        if(m_window)
        {
            SDL_DestroyWindow(m_window);
        }
        m_window = SDL_CreateWindow(title.c_str(), pos.x, pos.y, size.width, size.height, flags);
    }

    void SDLWindow::setTitle(const String& title)
    {
        SDL_SetWindowTitle(m_window, title.c_str());
    }

    const String SDLWindow::getTitle() const
    {
        return SDL_GetWindowTitle(m_window);
    }

    cymath::Point SDLWindow::getPosition() const
    {
        cymath::Point p;
        SDL_GetWindowPosition(m_window, &p.x, &p.y);
        return p;
    }

    void SDLWindow::setPosition(const cymath::Point& pos)
    {
        SDL_SetWindowPosition(m_window, pos.x, pos.y);
    }

    cymath::Size SDLWindow::getSize() const
    {
        cymath::Size s;
        SDL_GetWindowSize(m_window, &s.width, &s.height);
        return s;
    }

    void SDLWindow::setSize(const cymath::Size& size)
    {
        SDL_SetWindowSize(m_window, size.width, size.height);
    }

    SDL_Window* SDLWindow::getWindow() const
    {
        return m_window;
    }

    cymath::Rectangle SDLWindow::getBorderSize() const
    {
        cymath::Rectangle borders;
        SDL_GetWindowBordersSize(m_window, &borders.x, &borders.y, &borders.w, &borders.h);
        return borders;
    }

    void SDLWindow::setMinimumSize(const cymath::Size& size)
    {
        SDL_SetWindowMinimumSize(m_window, size.width, size.height);
    }

    void SDLWindow::setMinimumSize(const Sint32 w, const Sint32 h)
    {
        SDL_SetWindowMinimumSize(m_window, w, h);
    }

    cymath::Size SDLWindow::getMinimumSize() const
    {
        cymath::Size s;
        SDL_GetWindowMinimumSize(m_window, &s.width, &s.height);
        return s;
    }

    void SDLWindow::setMaximumSize(const cymath::Size& size)
    {
        SDL_SetWindowMaximumSize(m_window, size.width, size.height);
    }

    void SDLWindow::setMaximumSize(const Sint32 w, const Sint32 h)
    {
        SDL_SetWindowMaximumSize(m_window, w, h);
    }

    cymath::Size SDLWindow::getMaximumSize() const
    {
        cymath::Size s;
        SDL_GetWindowMaximumSize(m_window, &s.width, &s.height);
        return s;
    }

    void SDLWindow::setFlags(const Uint32 flags)
    {
        if(m_flags != flags)
        {
            if(1)  // TODO(SYSTEM::SDL::SDL_IS_INIT)
            {
                m_flags = flags;
                if(m_window != nullptr)
                    SDL_DestroyWindow(m_window);

                createWindow(getTitle(), getPosition(), getSize(), flags);
            }
        }
    }

    Uint32 SDLWindow::getFlags() const
    {
        return m_flags;
    }

    void SDLWindow::setResizeable(const bool resizeable)
    {
        SDL_SetWindowResizable(m_window, static_cast<SDL_bool>(resizeable));
    }

    void SDLWindow::setModalTo(const SDLWindow* parent)
    {
        SDL_SetWindowModalFor(m_window, parent->getWindow());
    }

    void SDLWindow::setFullScreen(const Uint32 flag)
    {
        SDL_SetWindowFullscreen(m_window, flag);
    }

    void SDLWindow::setGrab(const bool& grabbed)
    {
        SDL_SetWindowGrab(m_window, static_cast<SDL_bool>(grabbed));
    }

    bool SDLWindow::getGrab() const
    {
        return SDL_GetWindowGrab(m_window);
    }

    void SDLWindow::setInputFocus()
    {
        SDL_SetWindowInputFocus(m_window);
    }

    void SDLWindow::setHitTest(const SDL_HitTest& callback, void* const data)
    {
        SDL_SetWindowHitTest(m_window, callback, data);
    }

    void SDLWindow::show()
    {
        SDL_ShowWindow(m_window);
    }

    void SDLWindow::hide()
    {
        SDL_HideWindow(m_window);
    }

    void SDLWindow::setBordered(const bool bordered)
    {
        SDL_SetWindowBordered(m_window, static_cast<SDL_bool>(bordered));
    }

    void SDLWindow::setBrightness(const float brightness)
    {
        SDL_SetWindowBrightness(m_window, brightness);
    }

    float SDLWindow::getBrightness() const
    {
        return SDL_GetWindowBrightness(m_window);
    }

    void SDLWindow::setOpacity(const float opacity)
    {
        SDL_SetWindowOpacity(m_window, opacity);
    }

    float SDLWindow::getOpacity() const
    {
        float opacity;
        SDL_GetWindowOpacity(m_window, &opacity);
        return opacity;
    }

    void SDLWindow::setGammaRamp(const Uint16 r, const Uint16 g, const Uint16 b)
    {
        SDL_SetWindowGammaRamp(m_window, &r, &g, &b);
    }

    void SDLWindow::setGammaRamp(const cyutil::RGBAColor& color)
    {
        setGammaRamp(color.r, color.g, color.b);
    }

    Uint32 SDLWindow::getID() const
    {
        return SDL_GetWindowID(m_window);
    }

    Uint32 SDLWindow::getDisplayIndex() const
    {
        int display_int = SDL_GetWindowDisplayIndex(m_window);

        if(display_int > 0)
            return static_cast<Uint32>(display_int);
        else
            return 0;
    }

    void SDLWindow::setIcon(SDL_Surface* icon)
    {
        SDL_SetWindowIcon(m_window, icon);
    }

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

    bool SDLWindow::isShown() const
    {
        return m_shown;
    }

    bool SDLWindow::isExposed() const
    {
        return m_exposed;
    }

    bool SDLWindow::isRestored() const
    {
        return m_restored;
    }

    bool SDLWindow::isMinimized() const
    {
        return m_minimized;
    }

    bool SDLWindow::isMaximized() const
    {
        return m_maximized;
    }

    bool SDLWindow::hasMouseFocus() const
    {
        return m_mouse_focus;
    }

    bool SDLWindow::isFocus() const
    {
        return m_focus;
    }

    bool SDLWindow::isClosed() const
    {
        return m_closed;
    }

}  // namespace cyanide::cyvideo
