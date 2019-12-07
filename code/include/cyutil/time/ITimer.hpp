#ifndef CYANIDE_ITIMER_HPP
#define CYANIDE_ITIMER_HPP

#include "cyutil/time/time.hpp"

namespace cyanide
{
namespace cyutil
{

    class ITimer
    {
    public:
        virtual ~ ITimer() = default;
    };

}  // namespace cyutil
}  // namespace cyanide

#endif  // CYANIDE_ITIMER_HPP
