#include "cynet/IP4Address.hpp"

#include <SDL2/SDL_net.h>

namespace cyanide::cynet
{

    IP4Address::IP4Address(const String& address)
    {
        setHostname(address);
    }

    IP4Address::IP4Address(const Uint32 host, const Uint16 port)
        : m_host(host)
        , m_port(port)
    {

    }

    void IP4Address::setAddress(const Uint32 host, const Uint16 port)
    {
        m_host = host;
        m_port = port;
    }

    Uint32 IP4Address::getHost() const
    {
        return m_host;
    }

    void IP4Address::setHost(const Uint32 host)
    {
        m_host = host;
    }

    Uint16 IP4Address::getPort() const
    {
        return m_port;
    }

    void IP4Address::setPort(const Uint16 port)
    {
        m_port = port;
    }

    String IP4Address::getHostname() const
    {
        return m_hostname;
    }

    void IP4Address::setHostname(const String& address)
    {

    }

}  // namespace cyanide