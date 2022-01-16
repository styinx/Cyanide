#include "cyutil/threading/Scheduler.hpp"

namespace cyanide::cyutil
{

    Scheduler::Scheduler()
    {
    }

    Scheduler::~Scheduler()
    {
        stop();
    }

    void Scheduler::run()
    {
        m_state = cyanide::cyutil::ThreadState::RUNNING;
        while(m_running)
        {
            if(m_queue.size())
            {
                const auto task = m_queue.front();
                m_queue.pop();
                (*task)();
            }
        }
    }

    void Scheduler::add(const SharedPtr<ITask>& task)
    {
        m_queue.emplace(task);
    }

}
