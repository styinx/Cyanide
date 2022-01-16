#ifndef CYANIDE_INTERVALSCHEDULER_HPP
#define CYANIDE_INTERVALSCHEDULER_HPP

#include "cyutil/threading/IScheduler.hpp"

namespace cyanide::cyutil
{

    class IntervalScheduler : public IScheduler<Vector<SharedPtr<ITask>>>
    {
    private:
        const std::chrono::milliseconds m_interval;

        virtual void run() override;

    public:
        explicit IntervalScheduler(const std::chrono::milliseconds interval);
        virtual ~IntervalScheduler();

        virtual void add(const SharedPtr<ITask>& task) override;
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_INTERVALSCHEDULER_HPP
