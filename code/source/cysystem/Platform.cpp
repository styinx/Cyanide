#include "cysystem/Platform.hpp"

#include <SDL2/SDL_config.h>
#include <SDL2/SDL_cpuinfo.h>

#include <fmt/core.h>

namespace cyanide::cysystem
{

    void Platform::setEnvironment(const String& var, const String& path, const bool& override)
    {
        if(getenv(var.c_str()) == nullptr || override)
        {
            putenv(fmt::format("{}={}", var.c_str(), path.c_str()).c_str());
        }
    }

    std::string Platform::getPlatform()
    {
        return SDL_GetPlatform();
    }

    Sint32 Platform::getLogicalCPUs()
    {
        return SDL_GetCPUCount();
    }

    Sint32 Platform::getCPUCacheSize()
    {
        return SDL_GetCPUCacheLineSize();
    }

    Sint32 Platform::getRAM()
    {
        return SDL_GetSystemRAM();
    }

}  // namespace cyanide::cysystem