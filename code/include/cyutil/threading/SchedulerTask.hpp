#ifndef CYANIDE_SCHEDULERTASK_HPP
#define CYANIDE_SCHEDULERTASK_HPP

#include "cystd/Types.hpp"
#include "cyutil/threading/ITask.hpp"

namespace cyanide::cyutil
{

    template<typename ReturnType, typename... Args>
    class SchedulerTask final : public ITask
    {
        using Task = Function<ReturnType(Args...)>;

    private:
         Task m_func;
         std::tuple<Args...> m_args;

    public:
        explicit SchedulerTask(Task func, Args... args)
            : m_func(func)
            , m_args(std::forward<Args>(args)...)
        {
        }

        virtual void operator()() override
        {
            if(m_func)
            {
                m_func(std::get<Args>(m_args)...);
            }
        }
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_SCHEDULERTASK_HPP
