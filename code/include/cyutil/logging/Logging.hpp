#ifndef CYANIDE_LOGGING_HPP
#define CYANIDE_LOGGING_HPP

#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"
#include "cystd/Types.hpp"

#include <fmt/format.h>

namespace cyanide::cyutil
{

    enum class LOG_LEVEL : Uint8
    {
        NONE = 0x00,
        ANY
    };

    class Logging final
        : public cystd::NonCopyable
        , public cystd::NonMoveable
    {
    private:
        Logging() = default;

        static LOG_LEVEL s_log_level;

    public:
        virtual ~Logging() = default;

        static void log(const String& message);

        template<typename... Args>
        static void log(const String& format, Args&&... args)
        {
            // todo
        }

        static void print(const String& message);

        template<typename... Args>
        static void print(const String& format, Args&&... args)
        {
            fmt::print(format, args...);
        }

        static void setLogLevel(const LOG_LEVEL log_level);
    };

    void log(const String& message);

    template<typename... Args>
    static void log(const String& format, Args&&... args)
    {
        Logging::log(format, args...);
    }

    void print(const String& message);

    template<typename... Args>
    static void print(const String& format, Args&&... args)
    {
        Logging::print(format, args...);
    }

}  // namespace cyanide::cyutil

#endif  // CYANIDE_LOGGING_HPP
