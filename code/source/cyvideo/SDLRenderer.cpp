#include "cyvideo/SDLRenderer.hpp"

#include <SDL2/SDL2_gfxPrimitives.h>

namespace cyanide::cyvideo
{

    SDL_Renderer* SDLRenderer::getRenderer() const
    {
        return m_renderer;
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

    void cyvideo::SDLRenderer::drawPolygon(const Vector<cymath::Point>& p)
    {
    }

}  // namespace cyanide::cyvideo