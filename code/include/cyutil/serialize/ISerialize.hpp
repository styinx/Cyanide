#ifndef CYANIDE_ISERIALIZE_HPP
#define CYANIDE_ISERIALIZE_HPP

#include "cystd/stdPrototypes.hpp"

#include "cyutil/type/TypeName.hpp"

namespace cyanide::cyutil
{
    template<typename T>
    struct SerializationType
    {
        static const char Bytes;
        static const char Bits;
        static const T    Mask;
    };

    template<typename Class, typename Buffer>
    class ISerialize
    {
    protected:
        Vector<Buffer> m_buffer;
        Byte           m_index = 0;
        String         m_name;

        ISerialize()
            : m_name(cyutil::TypeName::rawTypeName<Class>())
        {
        }

    public:
        virtual ~ISerialize()      = default;
        virtual void serialize()   = 0;
        virtual void unserialize() = 0;
        //        Byte serializeByte(const Byte& u8);
        //        Byte serializeShort(const Uint16& u16);
        //        Byte serializeInt(const Uint16& u16);
        //        Byte serializeFloat(const float& f);
        //        Byte serializeLong(const Uint64& u64);
        //        Byte serializeDouble(const double& d);
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_ISERIALIZE_HPP
