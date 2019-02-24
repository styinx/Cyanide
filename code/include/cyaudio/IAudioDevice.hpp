#ifndef CYANIDE_IAUDIODEVICE_HPP
#define CYANIDE_IAUDIODEVICE_HPP

#include "cystd/prototypes.hpp"

namespace Cyanide
{
namespace cyaudio
{

    enum class DeviceType : Byte
    {
        NONE = 0,

        CAPTURE,
        PLAYBACK,
        CAPTURE_PLAYBACK,

        INVALID
    };

    enum class DeviceStatus : Byte
    {
        NONE = 0,

        STOPPED,
        PLAYING,
        PAUSED,

        INVALID
    };

    class IAudioDevice
    {
    public:
        virtual void lock() = 0;

        virtual DeviceType getDeviceType() = 0;

        virtual String getDeviceName() const = 0;

        virtual DeviceStatus getDeviceStatus() const = 0;

        virtual void pause() const = 0;

        virtual void resume() const = 0;
    };

    using IAudioDevicePtr = SharedPtr<IAudioDevice>;

}  // namespace cyaudio
}  // namespace Cyanide

#endif  // CYANIDE_IAUDIODEVICE_HPP
