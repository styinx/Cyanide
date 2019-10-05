#ifndef CYANIDE_ICLIENT_HPP
#define CYANIDE_ICLIENT_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cynet
{

    class IClient
    {
    public:
        virtual ~IClient() = default;
    };

    using IClientSPtr = SharedPtr<IClient>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_ICLIENT_HPP
