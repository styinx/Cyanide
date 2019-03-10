#include "cyaudio/devices/SDLAudioDevice.hpp"

namespace Cyanide
{
namespace cyaudio
{

    SDLAudioDevice::SDLAudioDevice()
        : IAudioDevice()
    {
        //TODO init
    }

    SDL_AudioDeviceID SDLAudioDevice::getDeviceId() const
    {
        return m_device_id;
    }

    void SDLAudioDevice::lock()
    {
        SDL_LockAudioDevice(m_device_id);
    }

    DEVICE_TYPE SDLAudioDevice::getDeviceType() const
    {
        return m_device_type;
    }

    DEVICE_STATUS SDLAudioDevice::getDeviceStatus() const
    {
        switch(SDL_GetAudioDeviceStatus(m_device_id))
        {
        case SDL_AUDIO_STOPPED: return DEVICE_STATUS::STOPPED;
        case SDL_AUDIO_PLAYING: return DEVICE_STATUS::PLAYING;
        case SDL_AUDIO_PAUSED: return DEVICE_STATUS::PAUSED;
        default: return DEVICE_STATUS::INVALID;
        }
    }

    String SDLAudioDevice::getDeviceName() const
    {
        return m_device_name;
    }

    void SDLAudioDevice::pause() const
    {
        SDL_PauseAudioDevice(m_device_id, 1);
    }

    void SDLAudioDevice::resume() const
    {
        SDL_PauseAudioDevice(m_device_id, 0);
    }

}  // namespace cyaudio
}  // namespace Cyanide