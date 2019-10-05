#ifndef CYANIDE_SCHEDULER_HPP
#define CYANIDE_SCHEDULER_HPP

#include "cysystem/IScheduler.hpp"

namespace cyanide::cysystem
{

    class Scheduler : public IScheduler
    {
    private:
        Queue<ITask*> queue;

    public:
        virtual ~Scheduler() = default;
        virtual void add(ITask* task) override;
        virtual void run() override;
    };

}  // namespace cyanide::cysystem

#endif  // CYANIDE_SCHEDULER_HPP
