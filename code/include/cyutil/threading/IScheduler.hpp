#ifndef CYANIDE_SCHEDULER_HPP
#define CYANIDE_SCHEDULER_HPP

#include "cyutil/threading/ITask.hpp"
#include "cyutil/threading/Thread.hpp"

namespace cyanide::cyutil
{

    template<typename QueueType>
    class IScheduler : public Thread
    {
    protected:
        QueueType m_queue;

        virtual void run() override = 0;

    public:
        explicit IScheduler(){};
        virtual ~IScheduler(){};

        virtual void add(const SharedPtr<ITask>& task) = 0;
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_SCHEDULER_HPP
