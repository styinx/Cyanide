
#include <cyutil/formats/Value.hpp>

#include "cyutil/formats/Value.hpp"

namespace cyanide
{
namespace cyutil
{

    Value::Value()
        : u8(0)
    {
    }

    Value::Value(bool b)
        : b(b)
    {
    }

    Value::Value(char c)
        : c(c)
    {
    }

    Value::Value(Uint8 u8)
        : u8(u8)
    {
    }

    Value::Value(Uint16 u16)
        : u16(u16)
    {
    }

    Value::Value(Uint32 u32)
        : u32(u32)
    {
    }

    Value::Value(Sint32 s32)
        : s32(s32)
    {
    }

    Value::Value(float f)
        : f(f)
    {
    }

    Value::Value(String s)
        : s(s)
    {
    }

    Value::TYPE Value::getType() { return type; }
    bool        Value::getBool() { return std::get<bool>(b); }
    char        Value::getChar() { return std::get<char>(c); }
    Uint8       Value::getUint8() { return std::get<Uint8>(u8); }
    Uint16      Value::getUint16() { return std::get<Uint16>(u16); }
    Uint32      Value::getUint32() { return std::get<Uint32>(u32); }
    Sint32      Value::getSint32() { return std::get<Sint32>(s32); }
    float       Value::getFloat() { return std::get<float>(f); }
    String      Value::getString() { return std::get<String>(s); }

    bool Value::get(bool& b) const
    {
        b = std::get<bool>(this->b);
        return b;
    }

    Value::operator bool() const { return std::get<bool>(b); }

    char Value::get(char& b) const
    {
        b = std::get<char>(this->b);
        return b;
    }

    Value::operator char() const { return std::get<char>(b); }

    Uint8 Value::get(Uint8& u8) const
    {
        u8 = std::get<Uint8>(this->u8);
        return u8;
    }

    Value::operator Uint8() const { return std::get<Uint8>(u8); }

    Uint16 Value::get(Uint16& u16) const
    {
        u16 = std::get<Uint8>(this->u16);
        return u16;
    }

    Value::operator Uint16() const { return std::get<Uint8>(u16); }

    Uint32 Value::get(Uint32& u32) const
    {
        u32 = std::get<Uint8>(this->u32);
        return u32;
    }

    Value::operator Uint32() const { return std::get<Uint32>(u32); }

    Sint32 Value::get(Sint32& s32) const
    {
        s32 = std::get<Uint8>(this->s32);
        return s32;
    }

    Value::operator Sint32() const { return std::get<Sint32>(s32); }

    float Value::get(float& f) const
    {
        f = std::get<float>(this->f);
        return f;
    }

    Value::operator float() const { return std::get<float>(f); }

    String Value::get(String& d) const
    {
        d = std::get<String>(this->s);
        return d;
    }

    Value::operator String() const { return std::get<String>(s); }

    void Value::set(bool b)
    {
        b    = b;
        type = TYPE::BOOL;
    }

    Value& Value::operator=(bool b)
    {
        set(b);
        type = TYPE::BOOL;
        return *this;
    }

    void Value::set(char c)
    {
        c    = c;
        type = TYPE::CHAR;
    }

    Value& Value::operator=(char c)
    {
        set(c);
        type = TYPE::CHAR;
        return *this;
    }

    void Value::set(Uint8 u8)
    {
        u8   = u8;
        type = TYPE::UINT8;
    }

    Value& Value::operator=(Uint8 u8)
    {
        set(u8);
        type = TYPE::UINT8;
        return *this;
    }

    void Value::set(Uint16 u16)
    {
        u16  = u16;
        type = TYPE::UINT16;
    }

    Value& Value::operator=(Uint16 u16)
    {
        set(u16);
        type = TYPE::UINT16;
        return *this;
    }

    void Value::set(Uint32 u32)
    {
        u32  = u32;
        type = TYPE::UINT32;
    }

    Value& Value::operator=(Uint32 u32)
    {
        set(u32);
        type = TYPE::UINT32;
        return *this;
    }

    void Value::set(Sint32 s32)
    {
        s32  = s32;
        type = TYPE::SINT32;
    }

    Value& Value::operator=(Sint32 s32)
    {
        set(s32);
        type = TYPE::SINT32;
        return *this;
    }

    void Value::set(float f)
    {
        f    = f;
        type = TYPE::FLOAT;
    }

    Value& Value::operator=(float f)
    {
        set(f);
        type = TYPE::FLOAT;
        return *this;
    }

    void Value::set(String s)
    {
        s    = s;
        type = TYPE::STRING;
    }

    Value& Value::operator=(String s)
    {
        set(s);
        type = TYPE::STRING;
        return *this;
    }

}  // namespace cyutil
}  // namespace cyanide