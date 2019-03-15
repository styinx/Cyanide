#include "cyutil/time/Clock.hpp"

#include <iomanip>

#include <SDL2/SDL_timer.h>

namespace cyanide
{
namespace cyutil
{
    Uint32 Clock::getTicks() { return SDL_GetTicks(); }

    Uint64 Clock::getTimestamp()
    {
        auto ns =
        std::chrono::duration_cast<nanoseconds>(std::chrono::system_clock::now().time_since_epoch());
        return static_cast<Uint64>(ns.count());
    }

    void Clock::sleep(Uint64 ns) { std::this_thread::sleep_for(std::chrono::nanoseconds(ns)); }

    String Clock::getTicksToString(Uint32 ticks, String format)
    {
        std::stringstream ss;
        Sint32            digits      = 0;
        Uint64            offset      = 0;
        Uint64            next_offset = 0;
        Uint64            diff        = 0;
        Uint64            hours = 0, minutes = 0, seconds = 0, milliseconds = 0;

        if((offset = format.find("%H", offset)) != String::npos)
        {
            hours  = ticks / (1000 * 60 * 60);
            diff   = hours * 1000 * 60 * 60;
            digits = cyutil::digits(hours);

            ss << std::setw(std::max(2, digits)) << std::setfill('0') << hours
               << format.substr(offset + 2, format.find('%', offset + 2) - offset - 2);
            next_offset = offset + 2;
        }
        if((offset = format.find("%M", next_offset)) != String::npos)
        {
            minutes = (hours > 0) ? ticks / (1000 * 60) % 60 : ticks / (1000 * 60);
            digits  = cyutil::digits(minutes);

            ss << std::setw(std::max(2, digits)) << std::setfill('0') << minutes
               << format.substr(offset + 2, format.find('%', offset + 2) - offset - 2);
            next_offset = offset + 2;
        }
        if((offset = format.find("%S", next_offset)) != String::npos)
        {
            seconds = (minutes > 0) ? (ticks / 1000 % 60) : (ticks - diff) / 1000;
            digits  = cyutil::digits(seconds);

            ss << std::setw(std::max(2, digits)) << std::setfill('0') << seconds
               << format.substr(offset + 2, format.find('%', offset + 2) - offset - 2);
            next_offset = offset + 2;
        }

        diff += minutes * 1000 * 60;

        if((offset = format.find("%f", next_offset)) != String::npos)
        {
            milliseconds = (seconds > 0) ? (ticks % 1000) : ticks - diff;
            digits       = cyutil::digits(milliseconds);

            ss << std::setw(std::max(3, digits)) << std::setfill('0') << milliseconds
               << format.substr(offset + 2);
        }
        return ss.str();
    }

    String Clock::getPTicksToString(Uint64 ticks, String format)
    {
        std::stringstream ss;
        Sint32            digits      = 0;
        Uint64            offset      = 0;
        Uint64            next_offset = 0;
        Uint64            diff        = 0;
        Uint64 hours = 0, minutes = 0, seconds = 0, milliseconds = 0, microseconds = 0, nanoseconds = 0;
        Uint64 ns_to_s = 1000 * 1000 * 1000;

        if((offset = format.find("%H", offset)) != String::npos)
        {
            hours  = (ticks / (ns_to_s * 60 * 60));
            diff   = hours * ns_to_s * 60 * 60;
            digits = cyutil::digits(hours);

            ss << std::setw(std::max(2, digits)) << std::setfill('0') << hours
               << format.substr(offset + 2, format.find('%', offset + 2) - offset - 2);
            next_offset = offset + 2;
        }
        if((offset = format.find("%M", next_offset)) != String::npos)
        {
            minutes = (hours > 0) ? (ticks / (ns_to_s * 60)) % 60 : ticks / (ns_to_s * 60);
            digits  = cyutil::digits(minutes);

            ss << std::setw(std::max(2, digits)) << std::setfill('0') << minutes
               << format.substr(offset + 2, format.find('%', offset + 2) - offset - 2);
            next_offset = offset + 2;
        }
        if((offset = format.find("%S", next_offset)) != String::npos)
        {
            seconds = (minutes > 0) ? (ticks / ns_to_s) % 60 : (ticks - diff) / ns_to_s;
            digits  = cyutil::digits(seconds);

            ss << std::setw(std::max(2, digits)) << std::setfill('0') << seconds
               << format.substr(offset + 2, format.find('%', offset + 2) - offset - 2);
            next_offset = offset + 2;
        }

        diff += minutes * ns_to_s * 60;

        if((offset = format.find("%f", next_offset)) != String::npos)
        {
            milliseconds = (seconds > 0) ? (ticks / (1000 * 1000)) % 1000 : (ticks - diff) / (1000 * 1000);
            digits = cyutil::digits(milliseconds);

            ss << std::setw(std::max(3, digits)) << std::setfill('0') << milliseconds
               << format.substr(offset + 2, format.find('%', offset + 2) - offset - 2);
            next_offset = offset + 2;
        }

        diff += seconds * ns_to_s;

        if((offset = format.find("%u", next_offset)) != String::npos)
        {
            microseconds = (milliseconds > 0) ? (ticks / 1000) % 1000 : (ticks - diff) / 1000;
            digits       = cyutil::digits(microseconds);

            ss << std::setw(std::max(3, digits)) << std::setfill('0') << microseconds
               << format.substr(offset + 2, format.find('%', offset + 2) - offset - 2);
            next_offset = offset + 2;
        }

        diff += milliseconds * 1000 * 1000;

        if((offset = format.find("%n", next_offset)) != String::npos)
        {
            nanoseconds = (microseconds > 0) ? ticks % 1000 : ticks - diff;
            digits      = cyutil::digits(nanoseconds);

            ss << std::setw(std::max(3, digits)) << std::setfill('0') << nanoseconds
               << format.substr(offset + 2);
        }
        return ss.str();
    }

    String Clock::getTimestampToString(Uint64 timestamp, String format)
    {
        const auto                                  ns = nanoseconds(timestamp);
        const std::chrono::time_point<system_clock> tp(ns);
        time_t                                      time = system_clock::to_time_t(tp);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), format.c_str());
        return ss.str();
    }

}  // namespace cyutil
}  // namespace cyanide