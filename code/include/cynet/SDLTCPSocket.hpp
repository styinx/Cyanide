#ifndef CYANIDE_SDLTCPSOCKET_HPP
#define CYANIDE_SDLTCPSOCKET_HPP

#include "cynet/netPrototypes.hpp"

#include "cynet/ISDLSocket.hpp"
#include "cynet/ITCPSocket.hpp"

namespace cyanide::cynet
{

    class SDLTCPSocket final
        : public ITCPSocket
        , public ISDLSocket
    {
    private:
        _TCPsocket* m_socket = nullptr;

    public:
        SDLTCPSocket();
        ~SDLTCPSocket();
        _TCPsocket*                getSocket() const;
        void                       setSocket(_TCPsocket* socket);

        /**
         * @brief Opens the socket for a server connection.
         * @param port
         * @return OPEN if the socket was opened successful otherwise CLOSED.
         */
        virtual SOCKET_STATE       open(const Uint16 port) override;

        /**
         * @brief Opens the socket for a client connection.
         * @param endpoint
         * @param port
         * @return OPEN if the socket was opened successful otherwise CLOSED.
         */
        virtual SOCKET_STATE       open(const char* endpoint, const Uint16 port) override;
        virtual SOCKET_STATE       accept(const SDLTCPSocketSPtr& client_socket);
        virtual SOCKET_STATE       close() override;
        virtual void               send(const NetworkPackageSPtr& package) override;
        virtual int                send(const Uint16* data, int len);
        virtual NetworkPackageSPtr receive() const override;

        template<typename T>
        Vector<T> receive(unsigned elements) const
        {
            std::vector<T> data(elements);
            if(isBound())
            {
                SDLNet_TCP_Recv(m_socket, data.data(), sizeof(T) * elements);
            }
            return data;
        }
    };

    using SDLTCPSocketSPtr = SharedPtr<SDLTCPSocket>;

}  // namespace cyanide::cynet

#endif  // CYANIDE_SDLTCPSOCKET_HPP
