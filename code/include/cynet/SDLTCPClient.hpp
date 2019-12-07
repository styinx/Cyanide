#ifndef CYANIDE_SDLTCPCLIENT_HPP
#define CYANIDE_SDLTCPCLIENT_HPP

#include "cynet/ITCPClient.hpp"

#include "cynet/SDLTCPSocket.hpp"

namespace cyanide::cynet
{

    class SDLTCPClient final : public ITCPClient
    {
    private:
        SDLTCPSocketSPtr m_socket = nullptr;

    public:
        SDLTCPClient();
        explicit SDLTCPClient(const String& endpoint, const Uint16& port);
        ~SDLTCPClient() = default;

        const SDLTCPSocketSPtr& getSocket() const;
    };

    using SDLTCPClientSPtr = SharedPtr<SDLTCPClient>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_SDLTCPCLIENT_HPP
