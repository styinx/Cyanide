#ifndef CYANIDE_ISDLSOCKET_HPP
#define CYANIDE_ISDLSOCKET_HPP

#include "cynet/ISocket.hpp"

#include <SDL2/SDL_net.h>

namespace cyanide::cynet
{

    class ISDLSocket
    {
    protected:
        IPaddress m_ip_address{};

        explicit ISDLSocket() = default;

    public:
        virtual ~ISDLSocket() = default;

        bool resolve(const char* endpoint, const Uint16 port);
        bool resolve(const Uint16 port);
    };

    using SDLSocketSPtr = SharedPtr<ISDLSocket>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_ISDLSOCKET_HPP
