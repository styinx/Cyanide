#ifndef CYANIDE_SDLRENDERER_HPP
#define CYANIDE_SDLRENDERER_HPP

#include "cyvideo/IRenderer.hpp"

namespace cyanide
{
namespace cyvideo
{

    class SDLRenderer : public IRenderer
    {
    private:
    public:
        SDLRenderer() = default;

        ~SDLRenderer() = default;
    };

}  // namespace cyvideo
}  // namespace cyanide

#endif  // CYANIDE_SDLRENDERER_HPP
