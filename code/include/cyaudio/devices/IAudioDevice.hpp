#ifndef CYANIDE_IAUDIODEVICE_HPP
#define CYANIDE_IAUDIODEVICE_HPP

#include "cystd/Types.hpp"

namespace cyanide::cyaudio
{

    enum class DEVICE_TYPE : Byte
    {
        NONE = 0,

        CAPTURE,
        PLAYBACK,
        CAPTURE_PLAYBACK,

        INVALID
    };

    enum class DEVICE_STATUS : Byte
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
        virtual ~IAudioDevice()                       = default;
        virtual void          lock()                  = 0;
        virtual DEVICE_TYPE   getDeviceType() const   = 0;
        virtual String        getDeviceName() const   = 0;
        virtual DEVICE_STATUS getDeviceStatus() const = 0;
        virtual void          pause() const           = 0;
        virtual void          resume() const          = 0;
    };

    using IAudioDevicePtr = SharedPtr<IAudioDevice>;

}  // namespace cyanide::cyaudio

#endif  // CYANIDE_IAUDIODEVICE_HPP
