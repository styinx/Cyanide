#include "cyutil/logging/Logging.hpp"

namespace cyanide::cyutil
{
    LOG_LEVEL Logging::s_log_level = LOG_LEVEL::ANY;

    void Logging::log(const String& message)
    {
        // todo
    }

    void Logging::print(const String& message)
    {
        fmt::print("{}", message);
    }

    void Logging::setLogLevel(const LOG_LEVEL log_level)
    {
        Logging::s_log_level = log_level;
    }

    void log(const String& message)
    {
        Logging::log(message);
    }

    void print(const String& message)
    {
        Logging::print(message);
    }

}  // namespace cyanide::cyutil
