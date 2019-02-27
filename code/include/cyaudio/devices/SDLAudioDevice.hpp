#ifndef CYANIDE_AUDIODEVICE_HPP
#define CYANIDE_AUDIODEVICE_HPP

#include <SDL2/SDL_audio.h>

#include "cystd/stdPrototypes.hpp"

#include "cyaudio/IAudioDevice.hpp"

namespace Cyanide
{
namespace cyaudio
{

    class SDLAudioDevice : public IAudioDevice
    {
    private:
        SDL_AudioDeviceID device_id;
        DeviceType        device_type = DeviceType::NONE;
        String            device_name = "";

    public:
        SDLAudioDevice();

        ~SDLAudioDevice() = default;

        SDL_AudioDeviceID getDeviceId() const;

        virtual void lock() override;

        virtual DeviceType getDeviceType() override;

        virtual DeviceStatus getDeviceStatus() const override;

        virtual String getDeviceName() const override;

        virtual void pause() const override;

        virtual void resume() const override;
    };

}  // namespace cyaudio
}  // namespace Cyanide

#endif  // CYANIDE_AUDIODEVICE_HPP
