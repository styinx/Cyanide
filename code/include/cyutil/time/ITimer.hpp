#ifndef CYANIDE_ITIMER_HPP
#define CYANIDE_ITIMER_HPP

#include "cyutil/time/time.hpp"

namespace cyanide::cyutil
{

    class ITimer
    {
    public:
        virtual ~ ITimer() = default;
    };

}  // namespace cyanide

#endif  // CYANIDE_ITIMER_HPP
