#ifndef CYANIDE_IMEDIUM_HPP
#define CYANIDE_IMEDIUM_HPP

#include "cystd/prototypes.hpp"

namespace Cyanide
{
namespace cyaudio
{

    class IMedium
    {
    public:
        virtual const char* getResource() const = 0;
        virtual void setResource(const char* resource) = 0;
    };

}  // namespace
}  // namespace Cyanide

#endif  // CYANIDE_IMEDIUM_HPP
