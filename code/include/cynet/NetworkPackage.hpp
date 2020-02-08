#ifndef CYANIDE_NETWORKPACKAGE_HPP
#define CYANIDE_NETWORKPACKAGE_HPP

#include "cystd/Types.hpp"

#include <any>

namespace cyanide::cynet
{

    class NetworkPackage final
    {
    public:
        struct Header
        {
            Uint64 command          = 0;
            Uint32 bytes            = 0;
            Uint8  byte_per_element = 1;  // TODO only bytes atm
        };

    private:
        Vector<Uint8> m_data;
        Header        m_header{};

    public:
        NetworkPackage() = default;
        explicit NetworkPackage(const Uint8& data);
        explicit NetworkPackage(const std::string& text);
        explicit NetworkPackage(const Vector<Uint8>& data);
        ~NetworkPackage() = default;

        NetworkPackage& operator<<(const Uint8 data);
        NetworkPackage& operator<<(const Vector<Uint8>& data);
        NetworkPackage& operator>>(Uint8& data);
        NetworkPackage& operator>>(Vector<Uint8>& data);
        bool            empty() const;
        size_t          size() const;
        void            setData(const Vector<Uint8>& data);
        Vector<Uint8>   getData();
        void            setHeader(const Header& header);
        Header          getHeader() const;
    };

    using NetworkPackageSPtr = SharedPtr<NetworkPackage>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_NETWORKPACKAGE_HPP
