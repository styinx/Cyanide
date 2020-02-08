#ifndef CYANIDE_ISCHEDULER_HPP
#define CYANIDE_ISCHEDULER_HPP

#include "cystd/Types.hpp"
#include "cysystem/ITask.hpp"

namespace cyanide::cysystem
{

    class IScheduler
    {
    public:
        virtual ~IScheduler() = default;
        virtual void add(ITask* task) = 0;
        virtual void run() = 0;
    };

}  // namespace cyanide

#endif  // CYANIDE_ISCHEDULER_HPP
