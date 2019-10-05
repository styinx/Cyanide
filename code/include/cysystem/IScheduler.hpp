#ifndef CYANIDE_ISCHEDULER_HPP
#define CYANIDE_ISCHEDULER_HPP

#include "cystd/stdPrototypes.hpp"
#include "cysystem/ITask.hpp"

namespace cyanide
{
namespace cysystem
{

    class IScheduler
    {
    public:
        virtual ~IScheduler() = default;
        virtual void add(ITask* task) = 0;
        virtual void run() = 0;
    };

}  // namespace cysystem
}  // namespace cyanide

#endif  // CYANIDE_ISCHEDULER_HPP
