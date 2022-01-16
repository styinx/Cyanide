project(cysystem CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Sources
#

set(SOURCES
        Cyanide.cpp

        Platform.cpp

        sdl/SDL.cpp)


#
# Builds
#

add_library(cysystem SHARED STATIC ${SOURCES})
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(cysystem PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()
