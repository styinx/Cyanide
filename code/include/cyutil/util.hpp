#ifndef CYANIDE_UTIL_HPP
#define CYANIDE_UTIL_HPP

#include "cyutil/animation/Animation.hpp"
#include "cyutil/color/IColor.hpp"
#include "cyutil/color/RGBAColor.hpp"
#include "cyutil/color/animation/ColorAnimation.hpp"
#include "cyutil/io/ByteStreamReader.hpp"
#include "cyutil/io/Print.hpp"
#include "cyutil/serialize/ISerialize.hpp"
#include "cyutil/time/Clock.hpp"
#include "cyutil/time/ITimer.hpp"
#include "cyutil/time/SDLPerformanceTimer.hpp"
#include "cyutil/time/SDLTimer.hpp"
#include "cyutil/time/time.hpp"
#include "cyutil/type/TypeEnum.hpp"
#include "cyutil/type/TypeName.hpp"

#include <cmath>
#include <sstream>
#include <string>

namespace cyanide::cyutil
{

    unsigned digits(long number)
    {
        return number > 0 ? static_cast<unsigned>(log10(number) + 1) : 1;
    }

    unsigned bits(long number)
    {
        unsigned bits = 0;
        while(number > 0)
        {
            number >>= 1;
            bits++;
        }
        return bits;
    }

    unsigned bitsTrue(long number)
    {
        unsigned bits = 0;
        while(number > 0)
        {
            if(number & 0x1)
            {
                bits++;
            }
            number >>= 1;
        }
        return bits;
    }

    unsigned bitsFalse(long number)
    {
        unsigned bits = 0;
        while(number > 0)
        {
            if(!(number & 0x1))
            {
                bits++;
            }
            number >>= 1;
        }
        return bits;
    }

    unsigned toNumber(const std::string number)
    {
        unsigned          num = 0;
        std::stringstream ss(number);
        ss >> num;
        return num;
    }

}  // namespace cyanide::cyutil

#endif  // CYANIDE_UTIL_HPP
