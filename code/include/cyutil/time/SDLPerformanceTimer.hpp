#ifndef CYANIDE_SDLPERFORMANCETIMER_HPP
#define CYANIDE_SDLPERFORMANCETIMER_HPP

#include "cyutil/time/ITimer.hpp"

namespace cyanide::cyutil
{

    /**
     * @brief A nanosecond accurate pointer
     */
    class SDLPerformanceTimer
    {
    private:
        static Uint16 timers;
        Uint16        timer_id      = 0;
        TIMER_STATE   state         = TIMER_STATE::STOPPED;
        Uint64        elapsed_time  = 0;
        Uint64        active_time   = 0;
        Uint64        paused_time   = 0;
        Uint64        timer_started = 0;
        Uint64        timer_paused  = 0;
        Uint64        timer_resumed = 0;
        Uint64        timer_stopped = 0;

    public:
        explicit SDLPerformanceTimer();

        ~SDLPerformanceTimer();

        Uint64 start();

        Uint64 pause();

        Uint64 resume();

        Uint64 stop();

        Uint64 addTime(Uint64 amount);

        Uint64 addActiveTime(Uint64 amount);

        Uint64 subTime(Uint64 amount);

        Uint64 subActiveTime(Uint64 amount);

        TIMER_STATE reset();

        TIMER_STATE getState();

        Uint64 getTicks();

        Uint64 getTime();

        Uint64 getActiveTime();

        Uint64 getPausedTime();
    };

}  // namespace cyanide

#endif  // CYANIDE_SDLPERFORMANCETIMER_HPP
