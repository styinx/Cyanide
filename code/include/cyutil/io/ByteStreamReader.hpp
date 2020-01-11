#ifndef CYANIDE_BYTESTREAMREADER_HPP
#define CYANIDE_BYTESTREAMREADER_HPP

namespace cyanide::cyutil
{

    class ByteStreamReader final
    {
    private:


    public:
        ByteStreamReader()                                  = default;
        ByteStreamReader(const ByteStreamReader& other)     = default;
        ByteStreamReader(ByteStreamReader&& other) noexcept = default;
        ByteStreamReader& operator=(const ByteStreamReader& other) = default;
        ByteStreamReader& operator=(ByteStreamReader&& other) noexcept = default;
        virtual ~ByteStreamReader()                                    = default;
    };

} // namespace cyanide::cyutil

#endif  // CYANIDE_BYTESTREAMREADER_HPP
