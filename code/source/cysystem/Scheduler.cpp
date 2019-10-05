#include "cysystem/Scheduler.hpp"

namespace cyanide::cysystem
{

    void Scheduler::add(ITask* task)
    {
        queue.push(task);
    }

    void Scheduler::run()
    {
        // (*queue.front())(); // arguments missing
    }

}  // namespace cyanide::cysystem