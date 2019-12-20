
#include <cyaudio/SDLAudio.hpp>

namespace cyanide::cyaudio
{

    void SDLAudio::pause()
    {
        SDL_PauseAudio(1);
    }

    void SDLAudio::resume()
    {
        SDL_PauseAudio(0);
    }

    Uint32 SDLAudio::getPlaybackDeviceId(const String name)
    {
        //TODO
        return 0;
    }

    Uint32 SDLAudio::getCaptureDeviceId(const String name)
    {
        //TODO
        return 0;
    }

    String SDLAudio::getPlaybackDeviceName(const Uint32 id)
    {
        return String(SDL_GetAudioDeviceName(id, 0));
    }

    String SDLAudio::getCaptureDeviceName(const Uint32 id)
    {
        return String(SDL_GetAudioDeviceName(id, 1));
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

        for(Uint32 id = 0; id < SDLAudio::getNumberOfCaptureDevices(); ++id)
        {
            capture_devices.emplace_back(SDLAudio::getCaptureDeviceName(id));
        }

        return capture_devices;
    }

    List<String> SDLAudio::getPlaybackDeviceNames()
    {
        List<String> playback_devices;

        for(Uint32 id = 0; id < SDLAudio::getNumberOfPlaybackDevices(); ++id)
        {
            playback_devices.emplace_back(SDLAudio::getPlaybackDeviceName(id));
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

    Uint32 SDLAudio::getAudioDriverId(const String name)
    {
        // TODO
        return 0;
    }

    String SDLAudio::getAudioDriverName(const Uint32 id)
    {
        return String(SDL_GetAudioDriver(id));
    }

    String SDLAudio::getCurrentAudioDriverName(const Uint32 id)
    {
        return String(SDL_GetCurrentAudioDriver());
    }

    Uint32 SDLAudio::getNumberOfAudioDrivers()
    {
        int audio_drivers = SDL_GetNumAudioDrivers();

        if(audio_drivers > 0)
            return static_cast<Uint32>(audio_drivers);
        else
            return 0;
    }

    List<String> SDLAudio::getAudioDriverNames()
    {
        List<String> audio_drivers;

        for(Uint32 id = 0; id < SDLAudio::getNumberOfAudioDrivers(); ++id)
        {
            audio_drivers.emplace_back(SDLAudio::getAudioDriverName(id));
        }

        return audio_drivers;
    }

}  // namespace cyanide
