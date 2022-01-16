#include "cyutil/threading/IntervalScheduler.hpp"

namespace cyanide::cyutil
{

    IntervalScheduler::IntervalScheduler(const std::chrono::milliseconds interval)
        : m_interval(interval)
    {
    }

    IntervalScheduler::~IntervalScheduler()
    {
        stop();
    }

    void IntervalScheduler::run()
    {
        while(m_running)
        {
            m_state = cyanide::cyutil::ThreadState::IDLE;
            std::this_thread::sleep_for(m_interval);
            m_state = cyanide::cyutil::ThreadState::RUNNING;

            for(const auto& task : m_queue)
            {
                (*task)();
            }
        }
    }

    void IntervalScheduler::add(const SharedPtr<ITask>& task)
    {
        m_queue.emplace_back(task);
    }

}
