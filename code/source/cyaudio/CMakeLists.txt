project(cyaudio CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Third party
#

find_package(sdl2-mixer CONFIG REQUIRED)


#
# Sources
#

set(SOURCES
        player/AudioPlayer.cpp
        player/Playlist.cpp

        SDLAudio.cpp
        SDLMixerAudio.cpp

        devices/SDLAudioDevice.cpp

        medium/SDLMusic.cpp)


#
# Builds
#

cy_add_module(cyaudio ${SOURCES})
target_link_libraries(cyaudio PRIVATE SDL2::SDL2_mixer)
