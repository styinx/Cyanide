#include "cynet/tcp/SDLTCPClient.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyutil/logging/Logging.hpp"

void printVec(const cyanide::Vector<cyanide::Byte>& vec)
{
    using namespace cyanide::cyutil;
    for(const auto& e : vec)
    {
        print("{}", (char)e);
    }
    print("\n");
    fflush(stdout);
}

int main()
{
    using namespace cyanide;
    using namespace cynet;
    using namespace cyutil;
    using namespace cysystem;

    SDL sdl{};
    sdl.initSDL(SDL_INIT_EVERYTHING);
    sdl.initNET();

    SDLTCPClientSPtr client(new SDLTCPClient("localhost", 13370));

    bool running = true;

    while(running)
    {
        NetworkPackageSPtr package = client->getSocket()->receive();
        NetworkPackage     pack    = *(package);

        if(!pack.empty())
        {
            printVec(pack.getData());

            if(*pack.getData().begin() == '0')
            {
                running = false;
            }
        }
        SDL_Delay(1);
    }

    return 0;
}
