#include "cynet/ISocket.hpp"

namespace cyanide::cynet
{

    SOCKET_STATE ISocket::getState() const
    {
        return m_socket_state;
    }

    bool ISocket::isClosed() const
    {
        return m_socket_state == SOCKET_STATE::CLOSED;
    }

    bool ISocket::isOpen() const
    {
        return m_socket_state == SOCKET_STATE::OPEN;
    }

    bool ISocket::isBound() const
    {
        return m_socket_state == SOCKET_STATE::BOUND;
    }

}  // namespace cyanide