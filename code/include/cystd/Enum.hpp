#ifndef CYANIDE_ENUM_HPP
#define CYANIDE_ENUM_HPP

#include <type_traits>

namespace cyanide
{
namespace cystd
{

    template<typename T>
    constexpr auto fromEnum(T t)
    {
        return static_cast<typename std::underlying_type<T>::type>(t);
    }

}  // namespace cystd
}  // namespace cyanide

#endif  // CYANIDE_ENUM_HPP
