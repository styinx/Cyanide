#include "cysystem/Platform.hpp"

#include <SDL2/SDL_config.h>
#include <SDL2/SDL_cpuinfo.h>

namespace Cyanide
{
namespace cysystem
{

    void Platform::setEnvironment(const char* var, const char* path, bool override)
    {
        setenv(var, path, override ? 1 : 0);
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

}  // namespace cysystem
}  // namespace Cyanide