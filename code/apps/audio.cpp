#include "cyaudio/player/AudioPlayer.hpp"
#include "cyinput/SDLEventLoop.hpp"
#include "cymath/Rectangle.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <cyaudio/SDLMixerAudio.hpp>

int main()
{
    using namespace cyanide;
    using namespace cyaudio;
    using namespace cyinput;
    using namespace cyvideo;

    const String FILENAME = __FILE__;
    const String BASE_DIR = FILENAME.substr(0, FILENAME.find_last_of('/')) + "/../../";

    cysystem::SDL sdl{};
    sdl.initSDL(SDL_INIT_EVERYTHING);
    sdl.initMIX(MIX_INIT_MP3 | MIX_INIT_MID | MIX_INIT_OGG | MIX_INIT_MOD);

    auto win =
        std::make_shared<cyvideo::SDLWindow>("asd", cymath::Point{50, 50}, cymath::Size{250, 250});
    auto ren = std::make_shared<cyvideo::SDLRenderer>(win);

    auto playlist = std::make_shared<Playlist>(BASE_DIR + "resources/audio/test.mp3");
    auto player   = std::make_shared<AudioPlayer>(playlist);
    player->setFadein(10000);
    player->setVolume(64);

    player->play();

    cyinput::SDLEventLoop eventLoop{};

    eventLoop.keyboard()->onAnyKeyEvent([&player](const SDL_Event& event) {
        switch(event.key.keysym.sym)
        {
        case SDLK_PLUS:
        case SDLK_VOLUMEUP:
        case SDLK_KP_PLUS:
        {
            player->setVolume(SDLMixerAudio::getMusicVolume() + 10);
            break;
        }
        case SDLK_MINUS:
        case SDLK_VOLUMEDOWN:
        case SDLK_KP_MINUS:
        {
            player->setVolume(std::max(SDLMixerAudio::getMusicVolume() - 10, 0));
            break;
        }
        }
    });
    eventLoop.run();

    return 0;
}
