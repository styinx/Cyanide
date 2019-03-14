#ifndef CYANIDE_ENUM_HPP
#define CYANIDE_ENUM_HPP

#include <type_traits>

namespace Cyanide
{
namespace cystd
{

    template<typename T>
    constexpr auto fromEnum(T t)
    {
        return static_cast<typename std::underlying_type<T>::type>(t);
    }

}  // namespace cystd
}  // namespace Cyanide

#endif  // CYANIDE_ENUM_HPP
