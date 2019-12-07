#ifndef CYANIDE_THREAD_HPP
#define CYANIDE_THREAD_HPP

#include <thread>
#include <functional>

namespace cyanide::cysystem
{

    template<typename ReturnType, typename ...Args>
    class Thread final
    {
    private:
        std::thread m_thread;

    public:
        explicit Thread(std::function<ReturnType(Args...)> f, Args... args)
            : m_thread(f, args...)
        {

        }

        ~Thread()
        {
            m_thread.join();
        }
    };

}  // namespace cyanide::cystd

#endif  // CYANIDE_THREAD_HPP
