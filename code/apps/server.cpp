#include "cynet/tcp/SDLTCPServer.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyutil/logging/Logging.hpp"

#include <iostream>

int main()
{
    using namespace cyanide;
    using namespace cynet;
    using namespace cyutil;
    using namespace cysystem;

    SDL sdl{};
    sdl.initSDL(SDL_INIT_EVERYTHING);
    sdl.initNET();

    SDLTCPServerSPtr server(new SDLTCPServer(13370));

    while(server->accept() != SOCKET_STATE::BOUND)
    {
        SDL_Delay(1000);
    }

    print("Server has one client\n");

    bool running = true;

    while(running)
    {
        std::string line;
        std::getline(std::cin, line);
        fflush(stdout);

        if(line == "0")
        {
            running = false;
        }

        server->send(std::make_shared<NetworkPackage>(line));
        SDL_Delay(1);
    }

    return 0;
}
