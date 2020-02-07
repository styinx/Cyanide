#ifndef CYANIDE_SCHEDULERTASK_HPP
#define CYANIDE_SCHEDULERTASK_HPP

#include "cystd/Types.hpp"
#include "cysystem/ITask.hpp"

namespace cyanide::cysystem
{

    template<typename ReturnType, typename ...Args>
    class SchedulerTask final : public ITask
    {
    private:
        Function<ReturnType(Args...)> f;

    public:
        SchedulerTask& bind(Function<ReturnType(Args...)> function)
        {
            if(function)
                f = function;
            return *this;
        }

        SchedulerTask& operator()(Args... args)
        {
            if(f)
                f(args...);
            return *this;
        }
    };

}  // namespace cyanide

#endif  // CYANIDE_SCHEDULERTASK_HPP
