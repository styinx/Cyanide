#include "cynet/tcp/SDLTCPClient.hpp"

#include <SDL2/SDL.h>
#include <iostream>

void print(const std::vector<Uint8>& what)
{
    for(const auto& b : what)
    {
        std::cout << b;
    }
    std::cout << "\n";
}

int main()
{
    using namespace cyanide;
    using namespace cynet;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDLNet_Init();

    SDLTCPClientSPtr client(new SDLTCPClient("localhost", 13370));

    bool running = true;

    while(running)
    {
        NetworkPackageSPtr package = client->getSocket()->receive();
        NetworkPackage     pack    = *(package);

        if(!pack.empty())
        {
            print(pack.getData());

            if(*pack.getData().begin() == '0')
            {
                running = false;
            }
        }
        SDL_Delay(1);
    }

    return 0;
}
