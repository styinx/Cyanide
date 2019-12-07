#ifndef CYANIDE_TYPEENUM_HPP
#define CYANIDE_TYPEENUM_HPP

#include <type_traits>

namespace cyanide::cyutil
{

    template<typename Enum>
    constexpr typename std::underlying_type<Enum>::type castEnum(Enum e) noexcept
    {
        return static_cast<typename std::underlying_type<Enum>::type>(e);
    }

}

#endif //CYANIDE_TYPEENUM_HPP
