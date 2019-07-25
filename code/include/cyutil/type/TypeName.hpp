#ifndef CYANIDE_TYPENAME_HPP
#define CYANIDE_TYPENAME_HPP

#include <string>

namespace cyanide::cyutil
{

    class TypeName
    {
    public:
        static const int SIGNATURE_OFFSET = 10;
        static const int SIGNATURE_LENGTH = 10;

        template<typename T>
        static std::string typeName()
        {
            std::string type_name        = __PRETTY_FUNCTION__;
            size_t      signature_length = SIGNATURE_LENGTH;
            size_t      temp_offset      = SIGNATURE_OFFSET;
            size_t      temp_start       = type_name.find('[', signature_length);
            size_t      temp_end         = type_name.find(';', temp_start);
            std::string type = type_name.substr(temp_start + temp_offset, temp_end - temp_start - temp_offset);
            return type;
        }

        template<typename T>
        static std::string rawTypeName()
        {
            std::string type_name = typeName<T>();
            std::string type      = type_name.substr(type_name.find_last_of(':') + 1);
            return type;
        }
    };

}  // namespace cyanide::cyutil

#endif  // CYANIDE_TYPENAME_HPP
