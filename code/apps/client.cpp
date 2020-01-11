#include "cynet/tcp/SDLTCPClient.hpp"

#include <SDL2/SDL.h>
#include <iostream>

int main()
{
    using namespace cyanide;
    using namespace cynet;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDLNet_Init();

    SDLTCPClientSPtr client(new SDLTCPClient("localhost", 13370));

    NetworkPackageSPtr package = client->getSocket()->receive();
    NetworkPackage     pack    = *(package);

    return 0;
}
