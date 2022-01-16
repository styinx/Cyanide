#include "cyutil/threading/Thread.hpp"

namespace cyanide::cyutil
{

    Thread::Thread()
        : m_running(false)
    {
    }

    Thread::~Thread()
    {
        stop();
    }

    void Thread::start()
    {
        m_running = true;
        m_state = ThreadState::STARTING;
        m_thread = std::thread(&Thread::run, this);
    }

    void Thread::join()
    {
        if(m_thread.joinable())
        {
            m_state = ThreadState::JOINING;
            m_thread.join();
        }
    }

    void Thread::stop()
    {
        m_running = false;
        join();
        m_state = ThreadState::STOPPED;
    }

    ThreadState Thread::getState()
    {
        return m_state;
    }

}
