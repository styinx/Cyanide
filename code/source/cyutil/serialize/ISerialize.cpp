#include "cyutil/serialize/ISerialize.hpp"

#include <cmath>

namespace cyanide::cyutil
{

    template<typename T>
    const char SerializationType<T>::Bytes = sizeof(T);
    template<typename T>
    const char SerializationType<T>::Bits = sizeof(T) * 8;
    template<typename T>
    const T SerializationType<T>::Mask = std::pow(2, sizeof(T) * 8 - 1);

}  // namespace cyanide::cyutil