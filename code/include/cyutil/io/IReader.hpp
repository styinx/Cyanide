#ifndef CYANIDE_IREADER_HPP
#define CYANIDE_IREADER_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cyutil
{

    class IReader
    {
    private:
    public:
        virtual ~IReader() = default;

        virtual void read() = 0;
    };

}  // namespace cyanide

#endif  // CYANIDE_IREADER_HPP
