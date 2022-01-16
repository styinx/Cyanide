#include "cyutil/time/Timer.hpp"

namespace cyanide::cyutil
{

    template<typename Type, typename TResolution>
    Uint16 Timer<Type, TResolution>::c_timers = 0;

    template<>
    Uint16 Timer<Uint32, milliseconds>::c_timers = 0;

    template<>
    Uint16 Timer<Uint64, nanoseconds>::c_timers = 0;

}  // namespace cyanide::cyutil
