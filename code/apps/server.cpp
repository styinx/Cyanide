#include "cynet/tcp/SDLTCPServer.hpp"

#include <SDL2/SDL.h>
#include <iostream>

void print(const std::string& what)
{
    std::cout << what << "\n";
}

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

    int i = 0;

    SDLTCPServerSPtr server(new SDLTCPServer(13370));

    while(server->accept() != SOCKET_STATE::BOUND)
    {
        SDL_Delay(1000);
        i += 1;
    }

    print("Server has one client");

    bool running = true;

    while(running)
    {
        std::string line;
        std::getline(std::cin, line);

        if(line == "0")
        {
            running = false;
        }

        server->send(std::make_shared<NetworkPackage>(line));
        SDL_Delay(1);
    }

    return 0;
}
