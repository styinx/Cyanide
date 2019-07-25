#ifndef CYANIDE_IKEY_HPP
#define CYANIDE_IKEY_HPP

#include "cystd/stdPrototypes.hpp"
#include "cyinput/Keys.hpp"

namespace cyanide
{
namespace cyinput
{

    class IKey
    {
    public:
        virtual ~IKey() = default;
        virtual Uint32 getCode() const = 0;
        virtual IKey& setCode(const Uint32 key) = 0;
        virtual IKey& setCode(const KEY key) = 0;
        virtual IKey& setCode(const IKey& key) = 0;
    };

}  // namespace cyinput
}  // namespace cyanide

#endif  // CYANIDE_IKEY_HPP
