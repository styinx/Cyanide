#ifndef CYANIDE_AUDIODEVICE_HPP
#define CYANIDE_AUDIODEVICE_HPP

#include <SDL2/SDL_audio.h>

#include "cystd/stdPrototypes.hpp"

#include "IAudioDevice.hpp"

namespace cyanide
{
namespace cyaudio
{

    class SDLAudioDevice : public IAudioDevice
    {
    private:
        SDL_AudioDeviceID m_device_id;
        DEVICE_TYPE       m_device_type = DEVICE_TYPE::NONE;
        String            m_device_name = "";

    public:
        SDLAudioDevice();

        ~SDLAudioDevice() = default;

        SDL_AudioDeviceID getDeviceId() const;

        virtual void lock() override;

        virtual DEVICE_TYPE getDeviceType() const override;

        virtual DEVICE_STATUS getDeviceStatus() const override;

        virtual String getDeviceName() const override;

        virtual void pause() const override;

        virtual void resume() const override;
    };

}  // namespace cyaudio
}  // namespace cyanide

#endif  // CYANIDE_AUDIODEVICE_HPP
