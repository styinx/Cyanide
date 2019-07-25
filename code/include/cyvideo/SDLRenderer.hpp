#ifndef CYANIDE_SDLRENDERER_HPP
#define CYANIDE_SDLRENDERER_HPP

#include "cyvideo/IRenderer.hpp"

#include <SDL2/SDL_render.h>

namespace cyanide::cyvideo
{

    class SDLRenderer final
        : public IRenderer
    {
    private:
        SDL_Renderer* m_renderer = nullptr;

    public:
        SDLRenderer()           = default;
        ~SDLRenderer() override = default;

        SDL_Renderer* getRenderer() const;

        virtual void drawText(const String& string) override;
        virtual void drawPoint(const cymath::Point& p) override;
        virtual void drawLine(const cymath::Line& l) override;
        virtual void drawTriangle(
            const cymath::Point& p1,
            const cymath::Point& p2,
            const cymath::Point& p3) override;
        virtual void drawRectangle(const cymath::Rectangle& r) override;
        virtual void drawPolygon(const Vector<cyanide::cymath::Point>& p) override;
    };

}  // namespace cyanide::cyvideo

#endif  // CYANIDE_SDLRENDERER_HPP
