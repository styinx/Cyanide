#ifndef CYANIDE_PLATFORM_HPP
#define CYANIDE_PLATFORM_HPP

#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"
#include "cystd/Types.hpp"

namespace cyanide::cysystem
{

    class Platform
        : cystd::NonCopyable
        , cystd::NonMoveable
    {
    private:
    public:
        static void setEnvironment(const String& var, const String& path, const bool& override);
        static std::string getPlatform();
        static Sint32 getLogicalCPUs();
        static Sint32 getCPUCacheSize();
        static Sint32 getRAM();
    };

}  // namespace cyanide

#endif  // CYANIDE_PLATFORM_HPP
