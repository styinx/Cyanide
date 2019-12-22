#include "cynet/tcp/SDLTCPServer.hpp"

#include "cynet/tcp/SDLTCPSocket.hpp"

namespace cyanide::cynet
{

    SDLTCPServer::SDLTCPServer(Uint16 port)
        : m_socket(new SDLTCPSocket())
        , m_client(new SDLTCPClient())
    {
        m_socket->open(port);
    }

    SOCKET_STATE SDLTCPServer::accept()
    {
        return m_socket->accept(m_client->getSocket());
    }

    void SDLTCPServer::send(const NetworkPackageSPtr& package)
    {
        return m_client->getSocket()->send(package);
    }

    int SDLTCPServer::send(const Uint16* data, int len)
    {
        return m_client->getSocket()->send(data, len);
    }

}  // namespace cyanide::cynet
