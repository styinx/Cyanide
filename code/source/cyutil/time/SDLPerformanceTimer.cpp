#include "cyutil/time/SDLPerformanceTimer.hpp"

namespace cyanide
{
namespace cyutil
{

    Uint16 SDLPerformanceTimer::timers = 0;

    SDLPerformanceTimer::SDLPerformanceTimer()
    {
        SDLPerformanceTimer::timers++;
        timer_id = SDLPerformanceTimer::timers;

        start();
    }

    SDLPerformanceTimer::~SDLPerformanceTimer() { stop(); }

    Uint64 SDLPerformanceTimer::start()
    {
        timer_started = getTicks();
        if(state != TIMER_STATE::STARTED)
        {
            elapsed_time = 0;
            state        = TIMER_STATE::STARTED;
        }
        else
        {
            state = TIMER_STATE::STOPPED;
            return start();
        }
        return timer_started;
    }

    Uint64 SDLPerformanceTimer::pause()
    {
        timer_paused = getTicks();
        if(state == TIMER_STATE::STARTED)
        {
            Uint64 start_resume = (timer_resumed > timer_started) ? timer_resumed : timer_started;
            Uint64 time_diff    = timer_paused - start_resume;
            active_time += time_diff;
            elapsed_time += time_diff;
            state = TIMER_STATE::PAUSED;
        }
        return timer_paused;
    }

    Uint64 SDLPerformanceTimer::resume()
    {
        timer_resumed = getTicks();
        if(state == TIMER_STATE::PAUSED)
        {
            Uint64 time_diff = timer_resumed - timer_paused;
            paused_time += time_diff;
            elapsed_time += time_diff;
            state = TIMER_STATE::STARTED;
        }
        return timer_resumed;
    }

    Uint64 SDLPerformanceTimer::stop()
    {
        timer_stopped = getTicks();
        if(state != TIMER_STATE::STOPPED)
        {
            Uint64 diff_time = (timer_resumed > timer_started) ? timer_resumed : timer_started;
            if(state == TIMER_STATE::STARTED) { active_time += timer_stopped - diff_time; }
            else if(state == TIMER_STATE::PAUSED)
            {
                paused_time += timer_stopped - diff_time;
            }
            elapsed_time += timer_stopped - diff_time;
            state = TIMER_STATE::STOPPED;
        }
        return timer_stopped;
    }

    Uint64 SDLPerformanceTimer::addTime(Uint64 amount)
    {
        elapsed_time += amount;

        return elapsed_time;
    }

    Uint64 SDLPerformanceTimer::addActiveTime(Uint64 amount)
    {
        active_time += amount;
        elapsed_time += amount;

        return active_time;
    }

    Uint64 SDLPerformanceTimer::subTime(Uint64 amount)
    {
        elapsed_time -= amount;

        return elapsed_time;
    }

    Uint64 SDLPerformanceTimer::subActiveTime(Uint64 amount)
    {
        active_time -= amount;
        elapsed_time -= amount;

        return active_time;
    }

    TIMER_STATE SDLPerformanceTimer::reset()
    {
        stop();
        elapsed_time = 0;
        active_time  = 0;
        paused_time  = 0;
        return state;
    }

    TIMER_STATE SDLPerformanceTimer::getState() { return state; }

    Uint64 SDLPerformanceTimer::getTicks()
    {
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::system_clock::now().time_since_epoch());
        return static_cast<Uint64>(ns.count());
    }

    Uint64 SDLPerformanceTimer::getTime()
    {
        pause();
        resume();
        return elapsed_time;
    }

    Uint64 SDLPerformanceTimer::getActiveTime()
    {
        pause();
        resume();
        return active_time;
    }

    Uint64 SDLPerformanceTimer::getPausedTime()
    {
        pause();
        resume();
        return paused_time;
    }
    
}  // namespace cyutil
}  // namespace cyanide