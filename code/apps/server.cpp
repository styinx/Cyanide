#include <SDL2/SDL.h>
#include "cynet/tcp/SDLTCPServer.hpp"
#include <iostream>

void print(std::string what)
{
    std::cout << what << "\n";
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
    NetworkPackage data{};
    data << Vector<Uint8>{2, 5, 6, 9, 55, 23, 54};
    server->send(std::make_shared<NetworkPackage>(data));

    return 0;
}
