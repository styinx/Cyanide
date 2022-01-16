#ifndef CYANIDE_ISCHEDULER_HPP
#define CYANIDE_ISCHEDULER_HPP

#include "cyutil/threading/IScheduler.hpp"

namespace cyanide::cyutil
{

    class Scheduler : public IScheduler<Queue<SharedPtr<ITask>>>
    {
    protected:
        virtual void run() override;

    public:
        explicit Scheduler();
        virtual ~Scheduler();

        virtual void add(const SharedPtr<ITask>& task) override;
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_ISCHEDULER_HPP
