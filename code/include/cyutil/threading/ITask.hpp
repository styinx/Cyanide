#ifndef CYANIDE_ITASK_HPP
#define CYANIDE_ITASK_HPP

namespace cyanide::cyutil
{

    class ITask
    {
    public:
        virtual ~ITask() = default;

        virtual void operator()() = 0;
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_ITASK_HPP
