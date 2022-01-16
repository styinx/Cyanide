#ifndef CYANIDE_THREAD_HPP
#define CYANIDE_THREAD_HPP

#include "cystd/Types.hpp"

#include <thread>

namespace cyanide::cyutil
{

    enum class ThreadState : Uint8
    {
        STOPPED = 0,
        STARTING,
        RUNNING,
        IDLE,
        JOINING,
    };

    class Thread
    {
    private:
        std::thread m_thread;

    protected:
        bool        m_running = false;
        ThreadState m_state;

    public:
        explicit Thread();
        virtual ~Thread();

        void         start();
        void         join();
        virtual void run() = 0;
        void         stop();
        ThreadState getState();
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_THREAD_HPP
