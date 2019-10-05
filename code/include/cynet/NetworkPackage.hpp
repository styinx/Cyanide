#ifndef CYANIDE_NETWORKPACKAGE_HPP
#define CYANIDE_NETWORKPACKAGE_HPP

#include <any>
#include <cystd/stdPrototypes.hpp>

namespace cyanide::cynet
{

    class NetworkPackage final
    {
    public:
        struct Header
        {
            Uint32 bytes            = 0;
            Uint8  byte_per_element = 1;  // TODO only bytes atm
        };

    private:
        Vector<Uint8> m_data;
        Header        m_header{};

    public:
        NetworkPackage()  = default;
        ~NetworkPackage() = default;

        NetworkPackage& operator<<(const Uint8 data);
        NetworkPackage& operator<<(const Vector<Uint8>& data);
        NetworkPackage& operator>>(Uint8 data);
        NetworkPackage& operator>>(Vector<Uint8>& data);
        size_t          size();
        Vector<Uint8>   data();
        Header&         header();
    };

    using NetworkPackageSPtr = SharedPtr<NetworkPackage>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_NETWORKPACKAGE_HPP
