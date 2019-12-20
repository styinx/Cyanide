#ifndef CYANIDE_IOPROTOTYPES_HPP
#define CYANIDE_IOPROTOTYPES_HPP

#include "cystd/stdPrototypes.hpp"

namespace cyanide::cyutil
{

    enum class BIT_STREAM : Byte
    {
        INVALID = 0,
        _1,
        _2,
        _3,
        _4
    };

    enum class BYTE_STREAM : Byte
    {
        INVALID = 0,
        UTF_8   = 8,
        UTF_16  = 16,
        UTF_32  = 32
    };

}  // namespace cyanide

#endif  // CYANIDE_IOPROTOTYPES_HPP
