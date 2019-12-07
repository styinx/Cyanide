#ifndef CYANIDE_ITCPSERVER_HPP
#define CYANIDE_ITCPSERVER_HPP

#include "cynet/IServer.hpp"

namespace cyanide::cynet
{

    class ITCPServer : public IServer
    {
    protected:
        ITCPServer() = default;

    public:
        virtual ~ITCPServer() = default;
    };

    using TCPServerSPtr = SharedPtr<ITCPServer>;

}  // namespace cyanide::cynet

#endif  //CYANIDE_ITCPSERVER_HPP
