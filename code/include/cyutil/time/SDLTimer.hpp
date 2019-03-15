#ifndef CYANIDE_SDLTIMER_HPP
#define CYANIDE_SDLTIMER_HPP

#include "cyutil/time/ITimer.hpp"

namespace cyanide
{
namespace cyutil
{

    /**
     * @brief A millisecond accurate timer
     * @note the actual time may differ by some offset caused by function calls
     */
    class Timer : public ITimer
    {
    private:
        static Uint16 timers;
        Uint16        timer_id      = 0;
        TIMER_STATE   state         = TIMER_STATE::STOPPED;
        Uint32        elapsed_time  = 0;
        Uint32        active_time   = 0;
        Uint32        paused_time   = 0;
        Uint32        timer_started = 0;
        Uint32        timer_paused  = 0;
        Uint32        timer_resumed = 0;
        Uint32        timer_stopped = 0;

    public:
        explicit Timer();

        ~Timer();

        Uint32 start();

        Uint32 pause();

        Uint32 resume();

        Uint32 stop();

        Uint32 addTime(Uint32 amount);

        Uint32 addActiveTime(Uint32 amount);

        Uint32 subTime(Uint32 amount);

        Uint32 subActiveTime(Uint32 amount);

        TIMER_STATE reset();

        TIMER_STATE getState();

        Uint32 getTicks();

        Uint32 getTime();

        Uint32 getActiveTime();

        Uint32 getPausedTime();
    };

}  // namespace cyutil
}  // namespace cyanide

#endif  // CYANIDE_SDLTIMER_HPP
