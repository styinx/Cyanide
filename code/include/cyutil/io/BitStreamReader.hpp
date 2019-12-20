#ifndef CYANIDE_BITSTREAMREADER_HPP
#define CYANIDE_BITSTREAMREADER_HPP

#include "cyutil/io/IReader.hpp"
#include "cyutil/io/ioPrototypes.hpp"

#include <fstream>

namespace cyanide::cyutil
{

    class BitStreamReader : public IReader
    {
    private:
        FILE*        m_stream;
        Vector<bool> m_buffer;

    public:
        BitStreamReader() = default;
        explicit BitStreamReader(const String& file);

        virtual ~BitStreamReader() override = default;

        virtual void read() override;
        void read(const Uint32 n);
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_BITSTREAMREADER_HPP
