project(cyvideo CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Third party
#

find_package(sdl2-gfx CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)


#
# Sources
#

set(SOURCES
        SDLSurface.cpp
        SDLTexture.cpp
        SDLVideo.cpp

        display/SDLDisplay.cpp

        font/SDLFont.cpp
        font/SDLFontCollection.cpp

        renderer/SDLRenderer.cpp
        renderer/GUIRenderManager.cpp

        window/SDLWindow.cpp)


#
# Builds
#

add_library(cyvideo SHARED STATIC ${SOURCES})
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(cyvideo PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()
target_link_libraries(cyvideo PRIVATE SDL2::SDL2_image SDL2::SDL2_gfx SDL2::SDL2_ttf)
