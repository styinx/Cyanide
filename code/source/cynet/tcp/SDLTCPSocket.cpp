#include "cynet/tcp/SDLTCPSocket.hpp"

namespace cyanide::cynet
{
    SDLTCPSocket::SDLTCPSocket()
        : ITCPSocket()
        , ISDLSocket()
    {
    }

    SDLTCPSocket::~SDLTCPSocket()
    {
        close();
    }

    _TCPsocket* SDLTCPSocket::getSocket() const
    {
        return m_socket;
    }

    void SDLTCPSocket::setSocket(_TCPsocket* socket)
    {
        m_socket = socket;
    }

    SOCKET_STATE SDLTCPSocket::open(const Uint16& port)
    {
        if(resolve(port) == 0)
        {
            if((m_socket = SDLNet_TCP_Open(&m_ip_address)) != nullptr)
            {
                m_socket_state = SOCKET_STATE::OPEN;
            }
        }
        return m_socket_state;
    }

    SOCKET_STATE SDLTCPSocket::open(const String& endpoint, const Uint16& port)
    {
        if(resolve(endpoint, port) == 0)
        {
            if((m_socket = SDLNet_TCP_Open(&m_ip_address)) != nullptr)
            {
                m_socket_state = SOCKET_STATE::BOUND;
            }
        }
        return m_socket_state;
    }

    SOCKET_STATE SDLTCPSocket::accept(const SDLTCPSocketSPtr& client_socket)
    {
        _TCPsocket* accepted_socket = SDLNet_TCP_Accept(m_socket);
        if(accepted_socket != nullptr)
        {
            client_socket->m_socket       = accepted_socket;
            client_socket->m_socket_state = SOCKET_STATE::BOUND;
            m_socket_state                = SOCKET_STATE::BOUND;
        }
        return m_socket_state;
    }

    SOCKET_STATE SDLTCPSocket::close()
    {
        SDLNet_TCP_Close(m_socket);
        if(m_socket == nullptr)
        {
            m_socket_state = SOCKET_STATE::CLOSED;
        }
        return m_socket_state;
    }

    void SDLTCPSocket::send(const NetworkPackageSPtr& package)
    {
        if(isBound())
        {
            NetworkPackage::Header header = package->getHeader();
            SDLNet_TCP_Send(m_socket, &header, sizeof(NetworkPackage::Header));
            SDLNet_TCP_Send(m_socket, package->getData().data(), package->size() * sizeof(Uint8));
        }
    }

    int SDLTCPSocket::send(const Uint16* data, int len)
    {
        if(isBound())
        {
            return SDLNet_TCP_Send(m_socket, data, len);
        }
        return -1;
    }

    // TODO 2 packages are sent, pack getHeader and getData into one package.
    NetworkPackageSPtr SDLTCPSocket::receive() const
    {
        NetworkPackageSPtr package(new NetworkPackage());
        if(isBound())
        {
            std::vector<NetworkPackage::Header> result = receive<NetworkPackage::Header>(1);

            if(!result.empty())
            {
                NetworkPackage::Header header = result.at(0);
                *package << receive<Uint8>(header.bytes / header.byte_per_element);
            }
        }
        return package;
    }

}  // namespace cyanide::cynet
