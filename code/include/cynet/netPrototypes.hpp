#ifndef CYANIDE_NETPROTOTYPES_HPP
#define CYANIDE_NETPROTOTYPES_HPP

#include "cystd/Types.hpp"

namespace cyanide::cynet
{

    class IIPAddress;
    using IIPAddressSPtr = SharedPtr<IIPAddress>;

    class ISocket;
    using ISocketSPtr = SharedPtr<ISocket>;

    class TCPSocket;
    using TCPSocketSPtr = SharedPtr<TCPSocket>;

    class SDLTCPSocket;
    using SDLTCPSocketSPtr = SharedPtr<SDLTCPSocket>;

    class IServer;
    using IServerSPtr = SharedPtr<IServer>;

    class IClient;
    using IClientSPtr = SharedPtr<IClient>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_NETPROTOTYPES_HPP
