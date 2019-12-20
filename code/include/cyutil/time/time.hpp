#ifndef CYANIDE_TIME_HPP
#define CYANIDE_TIME_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cyutil
{
    using system_clock = std::chrono::system_clock;
    using nanoseconds  = std::chrono::nanoseconds;
    using microseconds = std::chrono::microseconds;
    using milliseconds = std::chrono::milliseconds;
    using seconds      = std::chrono::seconds;

    enum class TIMER_STATE : Byte
    {
        STOPPED = 0x01,
        STARTED = 0x02,
        PAUSED  = 0x03
    };

}  // namespace cyanide

#endif  // CYANIDE_TIME_HPP
