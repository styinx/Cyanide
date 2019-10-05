#include "cynet/SDLTCPClient.hpp"

#include <SDL2/SDL_net.h>

namespace cyanide::cynet
{

    SDLTCPClient::SDLTCPClient()
        : m_socket(new SDLTCPSocket())
    {
    }

    SDLTCPClient::SDLTCPClient(const String& endpoint, const Uint16& port)
        : m_socket(new SDLTCPSocket())
    {
        m_socket->open(endpoint, port);
    }

    const SDLTCPSocketSPtr& SDLTCPClient::getSocket() const
    {
        return m_socket;
    }

}  // namespace cyanide::cynet