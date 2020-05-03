#include "cyaudio/player/AudioPlayer.hpp"
#include "cyinput/SDLEventLoop.hpp"
#include "cymath/Rectangle.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/window/SDLWindow.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int main()
{
    using namespace cyanide;
    using namespace cyaudio;
    using namespace cyvideo;

    cysystem::SDL sdl{};
    sdl.initSDL(SDL_INIT_EVERYTHING);
    sdl.initMIX(MIX_INIT_MP3 | MIX_INIT_MID | MIX_INIT_OGG | MIX_INIT_MOD);

    if(Mix_OpenAudio(44100, AUDIO_F32, 2, 4096) < 0)
    {
        // Some error shows here
    }

    auto win =
        std::make_shared<cyvideo::SDLWindow>("asd", cymath::Point{50, 50}, cymath::Size{250, 250});
    auto ren = std::make_shared<cyvideo::SDLRenderer>(win);

    auto playlist = std::make_shared<Playlist>("/home/chris/Projekte/Cyanide/resources/audio/"
                                               "classic.mp3");
    auto player   = std::make_shared<AudioPlayer>(playlist);
    player->setFadein(3000);
    player->setVolume(255);

    player->play();

    cyinput::SDLEventLoop eventLoop{};
    eventLoop.run();

    return 0;
}
