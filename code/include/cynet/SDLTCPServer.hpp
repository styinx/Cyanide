#ifndef CYANIDE_SDLTCPSERVER_HPP
#define CYANIDE_SDLTCPSERVER_HPP

#include "cynet/ITCPServer.hpp"

#include "cynet/SDLTCPClient.hpp"
#include "cynet/SDLTCPSocket.hpp"

namespace cyanide::cynet
{

    class SDLTCPServer final : public ITCPServer
    {
    private:
        SDLTCPSocketSPtr m_socket = nullptr;
        SDLTCPClientSPtr m_client = nullptr;

    public:
        explicit SDLTCPServer(Uint16 port);
        ~SDLTCPServer() = default;

        virtual SOCKET_STATE accept();
        virtual void         send(const NetworkPackageSPtr& package);
        virtual int          send(const Uint16* data, int len);
    };

    using SDLTCPServerSPtr = SharedPtr<SDLTCPServer>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_SDLTCPSERVER_HPP
