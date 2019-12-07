#include "cyutil/time/SDLTimer.hpp"

#include "cyutil/time/Clock.hpp"

namespace cyanide
{
namespace cyutil
{

    Uint16 Timer::timers = 0;

    Timer::Timer()
    {
        Timer::timers++;
        timer_id = Timer::timers;

        // reset();
        start();
    }

    Timer::~Timer() { stop(); }

    Uint32 Timer::start()
    {
        timer_started = getTicks();
        if(state != TIMER_STATE::STARTED) { state = TIMER_STATE::STARTED; }
        else
        {
            state = TIMER_STATE::STOPPED;
            return start();
        }
        return timer_started;
    }

    Uint32 Timer::pause()
    {
        timer_paused = getTicks();
        if(state == TIMER_STATE::STARTED)
        {
            Uint32 start_resume = (timer_resumed > timer_started) ? timer_resumed : timer_started;
            Uint32 time_diff    = timer_paused - start_resume;
            active_time += time_diff;
            elapsed_time += time_diff;
            state = TIMER_STATE::PAUSED;
        }
        return timer_paused;
    }

    Uint32 Timer::resume()
    {
        timer_resumed = getTicks();
        if(state == TIMER_STATE::PAUSED)
        {
            Uint32 time_diff = timer_resumed - timer_paused;
            paused_time += time_diff;
            elapsed_time += time_diff;
            state = TIMER_STATE::STARTED;
        }
        return timer_resumed;
    }

    Uint32 Timer::stop()
    {
        timer_stopped = getTicks();
        if(state != TIMER_STATE::STOPPED)
        {
            Uint32 diff_time = (timer_resumed > timer_started) ? timer_resumed : timer_started;
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

    Uint32 Timer::addTime(Uint32 amount)
    {
        elapsed_time += amount;

        return elapsed_time;
    }

    Uint32 Timer::addActiveTime(Uint32 amount)
    {
        active_time += amount;
        elapsed_time += amount;

        return active_time;
    }

    Uint32 Timer::subTime(Uint32 amount)
    {
        elapsed_time -= amount;

        return elapsed_time;
    }

    Uint32 Timer::subActiveTime(Uint32 amount)
    {
        active_time -= amount;
        elapsed_time -= amount;

        return active_time;
    }

    TIMER_STATE Timer::reset()
    {
        stop();
        elapsed_time = 0;
        active_time  = 0;
        paused_time  = 0;
        return state;
    }

    TIMER_STATE Timer::getState() { return state; }

    Uint32 Timer::getTicks() { return Clock::getTicks(); }

    Uint32 Timer::getTime()
    {
        pause();
        resume();
        return elapsed_time;
    }

    Uint32 Timer::getActiveTime()
    {
        pause();
        resume();
        return active_time;
    }

    Uint32 Timer::getPausedTime()
    {
        pause();
        resume();
        return paused_time;
    }

}  // namespace cyutil
}  // namespace cyanide