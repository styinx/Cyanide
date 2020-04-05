#ifndef CYANIDE_SDLRENDERER_HPP
#define CYANIDE_SDLRENDERER_HPP

#include "IRenderer.hpp"
#include "cyutil/color/RGBAColor.hpp"
#include "cyvideo/videoPrototypes.hpp"

#include <SDL2/SDL_render.h>

namespace cyanide::cyvideo
{

    namespace Default
    {
        const int    RENDER_INDEX = -1;
        const Uint32 RENDER_FLAGS = SDL_RENDERER_SOFTWARE;
    }  // namespace Default

    class SDLRenderer final : public IRenderer
    {
    private:
        SDL_Renderer*    m_renderer       = nullptr;
        SDLWindowSPtr    m_window         = nullptr;
        SDLTextureSPtr   m_target         = nullptr;
        int              m_renderer_index = Default::RENDER_INDEX;
        SDL_RendererInfo m_renderer_info{};

        SDLRenderer() = default;

        void loadRendererInfo();

    public:
        explicit SDLRenderer(const SDLWindowSPtr& window);
        virtual ~SDLRenderer() override;

        void createRenderer(const SDLWindowSPtr& window, const int index, const Uint32 flags);
        SDL_Renderer* getRenderer() const;
        cymath::Size  getSize() const;
        void          setRendererIndex(const int index);
        int           getRendererIndex() const;
        void          setRendererFlags(const Uint32 flags);
        int           getRendererFlags() const;
        int           getMaxTextureWidth();
        int           getMaxTextureHeight();

        virtual void clear() override;
        virtual void show() override;
        virtual void setRenderTarget(const SDLTextureSPtr& texture);
        virtual void resetRenderTarget();
        virtual void setDrawColor(cyutil::RGBAColor color) override;
        virtual void drawText(const String& string) override;
        virtual void drawPoint(const cymath::Point& p) override;
        virtual void drawLine(const cymath::Line& l) override;
        virtual void drawTriangle(
            const cymath::Point& p1,
            const cymath::Point& p2,
            const cymath::Point& p3) override;
        virtual void drawRectangle(const cymath::Rectangle& r) override;
        virtual void drawFilledRectangle(const cymath::Rectangle& r) override;
        virtual void drawPolygon(const Vector<cyanide::cymath::Point>& p) override;
        void         drawSDLTexture(const SDLTextureSPtr& texture, const cymath::Point& position);
        void         drawSDLTexture(
                    const SDLTextureSPtr& texture,
                    const cymath::Point&  position,
                    const cymath::Size&   size);
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLRENDERER_HPP
