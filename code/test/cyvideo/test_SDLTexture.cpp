#include "cysystem/sdl/SDL.hpp"
#include "cyvideo/SDLSurface.hpp"
#include "cyvideo/SDLTexture.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <gtest/gtest.h>

using namespace cyanide::cymath;
using namespace cyanide::cysystem;
using namespace cyanide::cyvideo;

class SDLTextrueTest : public ::testing::Test
{
protected:
    SDLTextrueTest()
    {
        SDL sdl{};
        sdl.initSDL(SDL_INIT_EVERYTHING);

        const std::string FILENAME = __FILE__;
        const std::string BASE_DIR = FILENAME.substr(0, FILENAME.find_last_of('/')) + "/../../../";

        win  = std::make_shared<SDLWindow>("Test", Point{20, 20}, Size{200, 200});
        ren  = std::make_shared<SDLRenderer>(win);
        surf = std::make_shared<SDLSurface>(std::string(BASE_DIR + "resources/cyanide.png"));
    }

    ~SDLTextrueTest() override
    {
    }

    SDLWindowSPtr   win;
    SDLRendererSPtr ren;
    SDLSurfaceSPtr  surf;
};

TEST_F(SDLTextrueTest, Ctor)
{
    const SDLTexture tex = SDLTexture(ren, surf);

    ASSERT_TRUE(tex.getSize());
    ASSERT_TRUE(tex.getTexture() != nullptr);
}

TEST_F(SDLTextrueTest, Ctor2)
{
    const Size       size = Size(50, 30);
    const SDLTexture tex  = SDLTexture(ren, size);

    ASSERT_EQ(tex.getSize(), size);
    ASSERT_TRUE(tex.getTexture() != nullptr);
}
