#ifndef CYANIDE_IP4ADDRESS_HPP
#define CYANIDE_IP4ADDRESS_HPP

#include "cynet/IIPAddress.hpp"

namespace cyanide::cynet
{

    class IP4Address final : public IIPAddress
    {
    private:
        std::string m_hostname;
        Uint32 m_host = 0;
        Uint16 m_port = 0;

    public:
        explicit IP4Address(const String& address);
        explicit IP4Address(const Uint32 host, const Uint16 port);
        void setAddress(const Uint32 host, const Uint16 port);
        Uint32 getHost() const;
        void setHost(const Uint32 host);
        Uint16 getPort() const;
        void setPort(const Uint16 port);
        String getHostname() const;
        void setHostname(const String& address);
    };

    using IP4AddressSPtr = SharedPtr<IP4Address>;

}  // namespace cyanide

#endif  // CYANIDE_IP4ADDRESS_HPP
