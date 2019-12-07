#ifndef CYANIDE_BITSTREAMREADER_HPP
#define CYANIDE_BITSTREAMREADER_HPP

#include "cyutil/io/IReader.hpp"

#include "cyutil/io/ioPrototypes.hpp"

namespace cyanide
{
namespace cyutil
{

    class BitStreamReader : IReader
    {
    private:
        BIT_STREAM           bits = BIT_STREAM ::INVALID;
        Vector<Vector<bool>> buffer;

    public:
        BitStreamReader() = default;
        explicit BitStreamReader(BIT_STREAM bits);

        virtual ~BitStreamReader() override = default;

        virtual void read() override;
    };

}  // namespace cyutil
}  // namespace cyanide

#endif  // CYANIDE_BITSTREAMREADER_HPP
