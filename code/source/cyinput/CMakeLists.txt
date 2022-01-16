project(cyinput CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Sources
#

set(SOURCES
        SDLEventLoop.cpp

        controller/Controller.cpp
        controller/ControllerInput.cpp

        joystick/Joystick.cpp
        joystick/JoystickInput.cpp

        keyboard/Key.cpp
        keyboard/Keyboard.cpp
        keyboard/KeyboardInput.cpp
        keyboard/KeyCombination.cpp
        keyboard/Keymod.cpp
        keyboard/SDLKey.cpp

        mouse/Mouse.cpp
        mouse/MouseInput.cpp)


#
# Builds
#

add_library(cyinput SHARED STATIC ${SOURCES})
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(cyinput PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()
