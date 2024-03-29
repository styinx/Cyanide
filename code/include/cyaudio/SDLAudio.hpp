#ifndef CYANIDE_AUDIO_HPP
#define CYANIDE_AUDIO_HPP

#include "cyaudio/devices/IAudioDevice.hpp"
#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"
#include "cystd/Types.hpp"

#include <SDL2/SDL_audio.h>

namespace cyanide::cyaudio
{

    class SDLAudio final
        : public cystd::NonCopyable
        , public cystd::NonMoveable
    {
    public:
        // UMap<Uint32, IAudioDevice*> devices;

        static void open(const String& filename);

        static void play();
        static void pause();

        static Uint32       getCaptureDeviceId(const String name);
        static Uint32       getPlaybackDeviceId(const String name);
        static String       getCaptureDeviceName(const Uint32 id);
        static String       getPlaybackDeviceName(const Uint32 id);
        static Uint32       getNumberOfCaptureDevices();
        static Uint32       getNumberOfPlaybackDevices();
        static Uint32       getNumberOfDevices();
        static List<String> getCaptureDeviceNames();
        static List<String> getPlaybackDeviceNames();
        static List<String> getDeviceNames();
        static Uint32       getAudioDriverId(const String name);
        static String       getCurrentAudioDriverName(const Uint32 id);
        static String       getAudioDriverName(const Uint32 id);
        static Uint32       getNumberOfAudioDrivers();
        static List<String> getAudioDriverNames();
    };

}  // namespace cyanide

#endif  // CYANIDE_AUDIO_HPP
