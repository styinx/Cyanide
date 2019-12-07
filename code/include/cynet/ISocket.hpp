#ifndef CYANIDE_ISOCKET_HPP
#define CYANIDE_ISOCKET_HPP

#include "cynet/NetworkPackage.hpp"
#include "cystd/stdPrototypes.hpp"

namespace cyanide::cynet
{

    enum class SOCKET_STATE : Byte
    {
        CLOSED = 0,
        OPEN   = 1,
        BOUND  = 2
    };

    class ISocket
    {
    protected:
        SOCKET_STATE m_socket_state = SOCKET_STATE::CLOSED;

        ISocket() = default;

    public:
        virtual ~ISocket()                                                          = default;
        virtual SOCKET_STATE       open(const Uint16& port)                         = 0;
        virtual SOCKET_STATE       open(const String& endpoint, const Uint16& port) = 0;
        virtual SOCKET_STATE       close()                                          = 0;
        virtual void               send(const NetworkPackageSPtr& package)          = 0;
        virtual NetworkPackageSPtr receive() const                                  = 0;

        virtual SOCKET_STATE getState() const;
        virtual bool         isClosed() const;
        virtual bool         isOpen() const;
        virtual bool         isBound() const;
    };

    using ISocketSPtr = SharedPtr<ISocket>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_ISOCKET_HPP
