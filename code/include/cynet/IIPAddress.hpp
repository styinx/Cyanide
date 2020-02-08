#ifndef CYANIDE_IIPADDRESS_HPP
#define CYANIDE_IIPADDRESS_HPP

#include "cystd/Types.hpp"

namespace cyanide::cynet
{

    class IIPAddress
    {
    public:
        virtual ~IIPAddress() = default;
    };

    using IIPAddressSPtr = SharedPtr<IIPAddress>;

}  // namespace cyanide

#endif  // CYANIDE_IIPADDRESS_HPP
