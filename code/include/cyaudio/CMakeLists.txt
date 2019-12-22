set(INCLUDES_AUDIO
    ${INCLUDES_AUDIO}

    ${CMAKE_CURRENT_SOURCE_DIR}/SDLAudio.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SDLMixerAudio.hpp

    ${CMAKE_CURRENT_SOURCE_DIR}/devices/IAudioDevice.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/devices/SDLAudioDevice.hpp

    ${CMAKE_CURRENT_SOURCE_DIR}/medium/IMedium.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/medium/SDLMusic.hpp

    PARENT_SCOPE)
