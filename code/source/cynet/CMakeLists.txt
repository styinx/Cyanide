project(cynet CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Third party
#

find_package(sdl2-net CONFIG REQUIRED)


#
# Sources
#

set(SOURCES
        IP4Address.cpp
        ISDLSocket.cpp
        ISocket.cpp
        NetworkPackage.cpp

        tcp/ITCPClient.cpp
        tcp/ITCPServer.cpp
        tcp/ITCPSocket.cpp
        tcp/SDLTCPClient.cpp
        tcp/SDLTCPServer.cpp
        tcp/SDLTCPSocket.cpp)


#
# Builds
#

add_library(cynet SHARED STATIC ${SOURCES})
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(cynet PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()
target_link_libraries(cynet PRIVATE SDL2::SDL2_net)
