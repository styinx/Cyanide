#include "cynet/ISDLSocket.hpp"

namespace cyanide::cynet
{

    bool ISDLSocket::resolve(const String& endpoint, const Uint16& port)
    {
        return SDLNet_ResolveHost(&m_ip_address, endpoint.c_str(), port);
    }

    bool ISDLSocket::resolve(const Uint16& port)
    {
        return SDLNet_ResolveHost(&m_ip_address, nullptr, port);
    }

}  // namespace cyanide