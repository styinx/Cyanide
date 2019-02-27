#ifndef CYANIDE_IMEDIUM_HPP
#define CYANIDE_IMEDIUM_HPP

#include "cystd/stdPrototypes.hpp"

namespace Cyanide
{
namespace cyaudio
{

    class IMedium
    {
    public:
        virtual ~IMedium() = default;
        virtual const char* getResource() const = 0;
        virtual void setResource(const char* resource) = 0;
    };

    using IMediumPtr = SharedPtr<IMedium>;

}  // namespace
}  // namespace Cyanide

#endif  // CYANIDE_IMEDIUM_HPP
