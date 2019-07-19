#ifndef CYANIDE_ITCPCLIENT_HPP
#define CYANIDE_ITCPCLIENT_HPP

#include "cynet/IClient.hpp"

namespace cyanide::cynet
{

    class ITCPClient : public IClient
    {
    protected:
        ITCPClient() = default;

    public:
        ~ITCPClient() = default;
    };

    using TCPClientSPtr = SharedPtr<ITCPClient>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_ITCPCLIENT_HPP
