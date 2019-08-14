#ifndef CYANIDE_SDLWINDOW_HPP
#define CYANIDE_SDLWINDOW_HPP

#include "IWindow.hpp"
#include "cymath/Rectangle.hpp"
#include "cymath/Size.hpp"
#include "cyutil/color/Color.hpp"

#include <SDL2/SDL_video.h>

namespace cyanide::cyvideo
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
        explicit SDLWindow(
            const String& title,
            const Sint32& x,
            const Sint32& y,
            const Sint32& w,
            const Sint32& h);

        explicit SDLWindow(const String& title, const cymath::Rectangle& geometry);

        explicit SDLWindow(
            const String&        title,
            const cymath::Point& position,
            const cymath::Size&  size);

        virtual ~SDLWindow() override = default;

        void createWindow(
            const String& title,
            const Sint32& x,
            const Sint32& y,
            const Sint32& w,
            const Sint32& h,
            const Uint32& flags = SDL_WINDOW_SHOWN);

        void createWindow(
            const String&            title,
            const cymath::Rectangle& geometry,
            const Uint32&            flags = SDL_WINDOW_SHOWN);

        void createWindow(
            const String&        title,
            const cymath::Point& position,
            const cymath::Size&  size,
            const Uint32&        flags = SDL_WINDOW_SHOWN);

        virtual void         setTitle(const String& title) override;
        virtual const String getTitle() const override;

        // Size and position

        virtual cymath::Point getPosition() const override;
        virtual void          setPosition(const cymath::Point& position) override;
        virtual cymath::Size  getSize() const override;
        virtual void          setSize(const cymath::Size& size) override;

        SDL_Window*       getWindow() const;
        cymath::Rectangle getBorderSize() const;
        void              setMinimumSize(const cymath::Size& size);
        void              setMinimumSize(const Sint32& w, const Sint32& h);
        cymath::Size      getMinimumSize() const;
        void              setMaximumSize(const cymath::Size& size);
        void              setMaximumSize(const Sint32& w, const Sint32& h);
        cymath::Size      getMaximumSize() const;

        // Behaviour

        void   setFlags(const Uint32& flags);
        Uint32 getFlags() const;
        void   setResizeable(const bool& resizeable);
        void   setModalTo(const SDLWindow* parent);
        void   setFullScreen(const Uint32& flag);
        void   setGrab(const bool& grabbed);
        bool   getGrab() const;
        void   setInputFocus();
        void   setHitTest(const SDL_HitTest& callback, void* const data);

        // Visibility

        void  show();
        void  hide();
        void  setBordered(const bool& bordered);
        void  setBrightness(const float& brightness);
        float getBrightness() const;
        void  setOpacity(const float& opacity);
        float getOpacity() const;
        void  setGammaRamp(const Uint16& r, const Uint16& g, const Uint16& b);
        void  setGammaRamp(const cyutil::Color& color);

        // Decoration

        void setIcon(SDL_Surface* icon);

        // Properties

        Uint32 getID() const;
        Uint32 getDisplayIndex() const;
        void   pollEvent();  // SDL_Event* event);
        bool   isShown() const;
        bool   isExposed() const;
        bool   isRestored() const;
        bool   isMinimized() const;
        bool   isMaximized() const;
        bool   hasMouseFocus() const;
        bool   isFocus() const;
        bool   isClosed() const;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLWINDOW_HPP
