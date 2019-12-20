#ifndef CYANIDE_CLOCK_HPP
#define CYANIDE_CLOCK_HPP

#include "cyutil/time/time.hpp"

namespace cyanide::cyutil
{

    class Clock
    {
    public:
        /**
         * @brief Returns the number ticks since the application is running. (eqvivalent to
         * SDL_GetTicks())
         * @return ticks as int
         */
        static Uint32 getTicks();

        /**
         * @brief Returns the current timestamp in nanoseconds. Uses std::chrono as reference.
         * @return timestamp as long
         */
        static Uint64 getTimestamp();

        /**
         * @brief Lets the current thread sleep for @param ns nanoseconds.
         * @param ns time to sleep in nanoseconds
         */
        static void sleep(Uint64 ns);

        /**
         * @brief Converts the number of ticks into human readable time.
         * @param ticks number of ticks to convert
         * @param format the format the resulting string shall have
         * @return a formatted string
         */
        static std::string getTicksToString(const Uint32 ticks, const String format = "%H:%M:%S.%f");

        /**
         * @brief Converts the number of performance ticks into human readable time.
         * In cotrary to @see getTicksToString this function uses 64 bit integers for higher accuracy.
         * @param ticks number of ticks to convert
         * @param format the format the resulting string shall have
         * @return a formatted string
         */
        static std::string getPTicksToString(const Uint64 ticks, const String format = "%H:%M:%S.%f %u %n");

        /**
         * @brief Converts the current timestamp into a human readable date.
         * @param timestamp the timestamp to convert
         * @param format the format the resulting string shall have
         * @return a formatted string
         */
        static std::string getTimestampToString(const Uint64 timestamp, const String format = "%H:%M:%S %d.%m.%Y");
    };

}  // namespace cyanide

#endif  // CYANIDE_CLOCK_HPP
