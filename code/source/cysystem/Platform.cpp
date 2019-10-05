#include "cysystem/Platform.hpp"

#include <SDL2/SDL_config.h>
#include <SDL2/SDL_cpuinfo.h>

namespace cyanide::cysystem
{

    void Platform::setEnvironment(const String& var, const String& path, const bool& override)
    {
        setenv(var.c_str(), path.c_str(), override ? 1 : 0);
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