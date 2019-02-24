#include "cyaudio/SDLAudio.hpp"

namespace Cyanide
{
namespace cyaudio
{

    void SDLAudio::pause()
    {
        SDL_PauseAudio(1);
    }

    void SDLAudio::resume()
    {
        SDL_PauseAudio(0);
    }

    Uint32 SDLAudio::getPlaybackDeviceId(String name)
    {
        //TODO
        return 0;
    }

    Uint32 SDLAudio::getCaptureDeviceId(String name)
    {
        //TODO
        return 0;
    }

    String SDLAudio::getPlaybackDeviceName(Uint32 index)
    {
        return String(SDL_GetAudioDeviceName(index, 0));
    }

    String SDLAudio::getCaptureDeviceName(Uint32 index)
    {
        return String(SDL_GetAudioDeviceName(index, 1));
    }

    Uint32 SDLAudio::getNumberOfPlaybackDevices()
    {
        int playback_devices = SDL_GetNumAudioDevices(0);

        if(playback_devices > 0)
            return static_cast<Uint32>(playback_devices);
        else
            return 0;
    }

    Uint32 SDLAudio::getNumberOfCaptureDevices()
    {
        int capture_devices = SDL_GetNumAudioDevices(1);

        if(capture_devices > 0)
            return static_cast<Uint32>(capture_devices);
        else
            return 0;
    }

    Uint32 SDLAudio::getNumberOfDevices()
    {
        return SDLAudio::getNumberOfPlaybackDevices() + SDLAudio::getNumberOfCaptureDevices();
    }

    List<String> SDLAudio::getCaptureDeviceNames()
    {
        List<String> capture_devices;

        for(Uint32 index = 0; index < SDLAudio::getNumberOfCaptureDevices(); ++index)
        {
            capture_devices.emplace_back(SDLAudio::getCaptureDeviceName(index));
        }

        return capture_devices;
    }

    List<String> SDLAudio::getPlaybackDeviceNames()
    {
        List<String> playback_devices;

        for(Uint32 index = 0; index < SDLAudio::getNumberOfPlaybackDevices(); ++index)
        {
            playback_devices.emplace_back(SDLAudio::getPlaybackDeviceName(index));
        }

        return playback_devices;
    }

    List<String> SDLAudio::getDeviceNames()
    {
        List<String> devices = SDLAudio::getCaptureDeviceNames();
        List<String> playback_devices = SDLAudio::getPlaybackDeviceNames();

        devices.splice(devices.end(), playback_devices);
        devices.unique();

        return devices;
    }

}  // namespace cyaudio
}  // namespace Cyanide