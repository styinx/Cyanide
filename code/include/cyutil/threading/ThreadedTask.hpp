#ifndef CYANIDE_THREADEDTASK_HPP
#define CYANIDE_THREADEDTASK_HPP

#include "cyutil/threading/Thread.hpp"

#include <functional>

namespace cyanide::cyutil
{

    template<typename ReturnType, typename... Args>
    class ThreadedTask final : public Thread
    {
        using Task = std::function<ReturnType(Args...)>;

    private:
        Task                m_func;
        std::tuple<Args...> m_args;

        virtual void run() override
        {
            m_func(std::get<Args>(m_args)...);
        }

    public:
        explicit ThreadedTask(Task func, Args... args)
            : m_func(func)
            , m_args(std::forward<Args>(args)...)
        {
        }

        virtual ~ThreadedTask()
        {
            stop();
        }
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_THREADEDTASK_HPP
