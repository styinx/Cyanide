#ifndef CYANIDE_SCALING_HPP
#define CYANIDE_SCALING_HPP

namespace cyanide::cymath
{

    template<typename ValueType, typename DesiredType = float>
    DesiredType scale(const ValueType v1, const ValueType v2)
    {
        return static_cast<DesiredType>(v1 / v2);
    }

}  // namespace cyanide::cymath

#endif  // CYANIDE_SCALING_HPP
