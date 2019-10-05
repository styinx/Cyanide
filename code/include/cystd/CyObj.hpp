#ifndef CYANIDE_CYOBJ_HPP
#define CYANIDE_CYOBJ_HPP

#include "stdPrototypes.hpp"

namespace cyanide
{
namespace cystd
{

    template<typename T>
    class CyObj
    {
    public:
        using SPtr = SharedPtr<T>;
        using UPtr = UniquePtr<T>;
        using WPtr = WeakPtr<T>;
    };

}  // namespace cystd
}  // namespace cyanide

#endif  // CYANIDE_CYOBJ_HPP
