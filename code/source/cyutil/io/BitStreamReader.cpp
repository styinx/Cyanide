#include "cyutil/io/BitStreamReader.hpp"

#include "cystd/Enum.hpp"

namespace cyanide::cyutil
{
    BitStreamReader::BitStreamReader(const String& file)
        : m_stream(fopen(file.c_str(), "rb"))
        , m_buffer(8000)
    {

    }

    void BitStreamReader::read()
    {

    }

    void BitStreamReader::read(const Uint32 n)
    {

    }

}  // namespace cyanide
