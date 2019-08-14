#include "cyvideo/renderer/SDLRenderer.hpp"

#include "cyvideo/SDLTexture.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <SDL2/SDL2_gfxPrimitives.h>

namespace cyanide::cyvideo
{
    SDLRenderer::SDLRenderer(const SDLWindowSPtr& window)
    {
        createRenderer(window, Default::RENDER_INDEX, Default::RENDER_FLAGS);
    }

    SDLRenderer::~SDLRenderer()
    {
        if(m_renderer != nullptr)
        {
            SDL_DestroyRenderer(m_renderer);
            m_renderer = nullptr;
        }
    }

    void SDLRenderer::createRenderer(const SDLWindowSPtr& window, const int& index, const Uint32& flags)
    {
        if(window != nullptr)
        {
            if(m_renderer != nullptr)
            {
                SDL_DestroyRenderer(m_renderer);
                m_renderer = nullptr;
            }

            m_window   = window;
            m_renderer = SDL_CreateRenderer(m_window->getWindow(), index, flags);

            if(m_renderer != nullptr)
            {
                m_renderer_index = index;
                loadRendererInfo();
            }
        }
        else
        {
            // err
        }
    }

    // Private

    void SDLRenderer::loadRendererInfo()
    {
        if(m_renderer != nullptr)
        {
            SDL_GetRendererInfo(m_renderer, &m_renderer_info);
        }
    }

    // Public

    SDL_Renderer* SDLRenderer::getRenderer() const
    {
        return m_renderer;
    }

    cymath::Size SDLRenderer::getSize() const
    {
        return {m_renderer_info.max_texture_width, m_renderer_info.max_texture_height};
    }

    void SDLRenderer::setRendererIndex(const int& index)
    {
        if(m_renderer_index != index)
        {
            createRenderer(m_window, index, m_renderer_info.flags);
        }
    }

    void SDLRenderer::setRendererFlags(const Uint32& flags)
    {
        if(m_renderer_info.flags != flags)
        {
            createRenderer(m_window, m_renderer_index, flags);
        }
    }

    void SDLRenderer::clear()
    {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    }

    void SDLRenderer::show()
    {
        SDL_RenderPresent(m_renderer);
    }

    void SDLRenderer::setRenderTarget(const SDLTextureSPtr& texture)
    {
        m_target = texture;
        SDL_SetRenderTarget(m_renderer, m_target->getTexture());
    }

    void SDLRenderer::resetRenderTarget()
    {
        SDL_SetRenderTarget(m_renderer, nullptr);
    }

    void SDLRenderer::setDrawColor(RGBAColor color)
    {
        SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    }

    void SDLRenderer::drawText(const String& string)
    {
    }

    void cyvideo::SDLRenderer::drawPoint(const cymath::Point& p)
    {
        SDL_RenderDrawPoint(m_renderer, p.x, p.y);
    }

    void cyvideo::SDLRenderer::drawLine(const cymath::Line& l)
    {
        SDL_RenderDrawLine(m_renderer, l.x1, l.y1, l.x2, l.y2);
    }

    void cyvideo::SDLRenderer::drawTriangle(
        const cymath::Point& p1,
        const cymath::Point& p2,
        const cymath::Point& p3)
    {
    }

    void cyvideo::SDLRenderer::drawRectangle(const cymath::Rectangle& r)
    {
        SDL_Rect rect{r.x, r.y, r.w, r.h};
        SDL_RenderDrawRect(m_renderer, &rect);
    }

    void SDLRenderer::drawFilledRectangle(const cymath::Rectangle& r)
    {
        SDL_Rect rect{r.x, r.y, r.w, r.h};
        SDL_RenderFillRect(m_renderer, &rect);
    }

    void cyvideo::SDLRenderer::drawPolygon(const Vector<cymath::Point>& p)
    {
    }

    void SDLRenderer::drawSDLTexture(const SDLTextureSPtr& texture, const cymath::Point& position)
    {
        cymath::Size s = texture->getSize();
        SDL_Rect src{0, 0, s.width, s.height};
        SDL_Rect dst{position.x, position.y, s.width, s.height};
        SDL_RenderCopy(m_renderer, texture->getTexture(), &src, &dst);
    }

}  // namespace cyanide::cyvideo