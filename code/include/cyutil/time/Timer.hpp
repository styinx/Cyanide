#ifndef CYANIDE_TIMER_HPP
#define CYANIDE_TIMER_HPP

#include "cyutil/time/time.hpp"

namespace cyanide::cyutil
{

    template<typename Type, typename TResolution>
    class Timer
    {
    protected:
        static Uint16 c_timers;
        Uint16        m_timer_id      = 0;
        TIMER_STATE   m_state         = TIMER_STATE::STOPPED;
        Type          m_elapsed_time  = 0;
        Type          m_active_time   = 0;
        Type          m_paused_time   = 0;
        Type          m_timer_started = 0;
        Type          m_timer_paused  = 0;
        Type          m_timer_resumed = 0;
        Type          m_timer_stopped = 0;

    public:
        explicit Timer()
        {
            Timer<Type, TResolution>::c_timers++;
            m_timer_id = Timer<Type, TResolution>::c_timers;

            start();
        }

        virtual ~Timer()
        {
            stop();
        };

        Type getTicks()
        {
            using std::chrono::system_clock;
            using std::chrono::duration_cast;

            auto ticks = duration_cast<TResolution>(system_clock::now().time_since_epoch());
            return static_cast<Type>(ticks.count());
        }

        Type start()
        {
            m_timer_started = getTicks();
            if(m_state != TIMER_STATE::STARTED)
            {
                m_elapsed_time = 0;
                m_state        = TIMER_STATE::STARTED;
            }
            else
            {
                m_state = TIMER_STATE::STOPPED;
                return start();
            }
            return m_timer_started;
        }

        Type pause()
        {
            m_timer_paused = getTicks();
            if(m_state == TIMER_STATE::STARTED)
            {
                Type start_resume =
                    (m_timer_resumed > m_timer_started) ? m_timer_resumed : m_timer_started;
                Type time_diff = m_timer_paused - start_resume;
                m_active_time += time_diff;
                m_elapsed_time += time_diff;
                m_state = TIMER_STATE::PAUSED;
            }
            return m_timer_paused;
        }

        Type resume()
        {
            m_timer_resumed = getTicks();
            if(m_state == TIMER_STATE::PAUSED)
            {
                Type time_diff = m_timer_resumed - m_timer_paused;
                m_paused_time += time_diff;
                m_elapsed_time += time_diff;
                m_state = TIMER_STATE::STARTED;
            }
            return m_timer_resumed;
        }

        Type stop()
        {
            m_timer_stopped = getTicks();
            if(m_state != TIMER_STATE::STOPPED)
            {
                Type diff_time =
                    (m_timer_resumed > m_timer_started) ? m_timer_resumed : m_timer_started;
                if(m_state == TIMER_STATE::STARTED)
                {
                    m_active_time += m_timer_stopped - diff_time;
                }
                else if(m_state == TIMER_STATE::PAUSED)
                {
                    m_paused_time += m_timer_stopped - diff_time;
                }
                m_elapsed_time += m_timer_stopped - diff_time;
                m_state = TIMER_STATE::STOPPED;
            }
            return m_timer_stopped;
        }

        Type addTime(Type amount)
        {
            m_elapsed_time += amount;

            return m_elapsed_time;
        }

        Type addActiveTime(Type amount)
        {
            m_active_time += amount;
            m_elapsed_time += amount;

            return m_active_time;
        }

        Type subTime(Type amount)
        {
            m_elapsed_time -= amount;

            return m_elapsed_time;
        }

        Type subActiveTime(Type amount)
        {
            m_active_time -= amount;
            m_elapsed_time -= amount;

            return m_active_time;
        }

        TIMER_STATE reset()
        {
            stop();
            m_elapsed_time = 0;
            m_active_time  = 0;
            m_paused_time  = 0;
            return m_state;
        }

        TIMER_STATE getState()
        {
            return m_state;
        }

        Uint16 getId()
        {
            return m_timer_id;
        }

        Type getTime()
        {
            pause();
            resume();
            return m_elapsed_time;
        }

        Type getActiveTime()
        {
            pause();
            resume();
            return m_active_time;
        }

        Type getPausedTime()
        {
            pause();
            resume();
            return m_paused_time;
        }
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_TIMER_HPP
