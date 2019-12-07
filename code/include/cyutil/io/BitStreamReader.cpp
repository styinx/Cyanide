#include "cyutil/io/BitStreamReader.hpp"

#include "cystd/Enum.hpp"

namespace cyanide
{
namespace cyutil
{
    BitStreamReader::BitStreamReader(BIT_STREAM bits)
        : bits(bits)
    {

    }

    void BitStreamReader::read()
    {
        void * buffer = {}; //TODO

        while(buffer)
        {
            for(Uint8 i = 0; i < cystd::fromEnum(bits); ++i)
            {

            }
        }
    }

}  // namespace cyutil
}  // namespace cyanide