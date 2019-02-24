#ifndef CYANIDE_AUDIO_HPP
#define CYANIDE_AUDIO_HPP

#include <SDL2/SDL_audio.h>

#include "cystd/NonCopyable.hpp"
#include "cystd/NonMoveable.hpp"
#include "cystd/prototypes.hpp"

#include "cyaudio/IAudioDevice.hpp"

namespace Cyanide
{
namespace cyaudio
{

    class SDLAudio
        : public cystd::NonCopyable
        , public cystd::NonMoveable
    {
    public:
        //List<IAudioDevice> devices; TODO

        static void pause();
        static void resume();

        static Uint32       getCaptureDeviceId(String name);
        static Uint32       getPlaybackDeviceId(String name);
        static String       getCaptureDeviceName(Uint32 index);
        static String       getPlaybackDeviceName(Uint32 index);
        static Uint32       getNumberOfCaptureDevices();
        static Uint32       getNumberOfPlaybackDevices();
        static Uint32       getNumberOfDevices();
        static List<String> getCaptureDeviceNames();
        static List<String> getPlaybackDeviceNames();
        static List<String> getDeviceNames();
    };

}  // namespace cyaudio
}  // namespace Cyanide

#endif  // CYANIDE_AUDIO_HPP
