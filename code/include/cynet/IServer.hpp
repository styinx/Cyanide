#ifndef CYANIDE_ISERVER_HPP
#define CYANIDE_ISERVER_HPP

#include "cystd/Types.hpp"

namespace cyanide::cynet
{

    class IServer
    {
    public:
        virtual ~IServer() = default;
    };

    using IServerSPtr = SharedPtr<IServer>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_ISERVER_HPP
