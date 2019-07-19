#ifndef CYANIDE_TCPSOCKET_HPP
#define CYANIDE_TCPSOCKET_HPP

#include "cynet/ISocket.hpp"
#include "cynet/netPrototypes.hpp"

namespace cyanide::cynet
{

    class ITCPSocket : public ISocket
    {
    protected:
        ITCPSocket() = default;

    public:
        virtual ~ITCPSocket()                                                    = default;
        virtual SOCKET_STATE       open(const Uint16 port)                       = 0;
        virtual SOCKET_STATE       open(const char* endpoint, const Uint16 port) = 0;
        virtual SOCKET_STATE       close()                                       = 0;
        virtual void               send(const NetworkPackageSPtr& package)       = 0;
        virtual NetworkPackageSPtr receive() const                               = 0;
    };

    using ITCPSocketSPtr = SharedPtr<ITCPSocket>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_TCPSOCKET_HPP
