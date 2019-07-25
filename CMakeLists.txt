project(Cyanide)


#
# CMake
#

cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

set(BIN_PATH "bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${BIN_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BIN_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BIN_PATH}")


#
# Paths
#

set(DIR_CODE code)
set(DIR_INCLUDE ${DIR_CODE}/include)
set(DIR_LIBRARY ${DIR_CODE}/lib)


if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(OS_DIR_INCLUDE /usr/include/)
    set(OS_DIR_LIBRARY /usr/libs/)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(OS_DIR_INCLUDE C:/Include/)
    set(OS_DIR_LIBRARY C:/Libs/)
endif()


include_directories(${DIR_INCLUDE} ${OS_DIR_INCLUDE})
link_directories(${DIR_LIBRARY} ${OS_DIR_LIBRARY})


#
# Libraries
#

set(LIB_SDL2
    -lSDL2main
    -lSDL2
    -lSDL2_gfx
    -lSDL2_image
    -lSDL2_mixer
    -lSDL2_net
    -lSDL2_ttf)

set(LIB_OPENGL
    -lGLEW
    -lGL)

set(LIB_PYTHON
    -lpython3.6m)

set(LIB_LUA
    -llua5.2)

set(LIB_SQLITE3
    -lsqlite3)

set(LIB_MYSQL
    -lmysqlclient)

set(LIBRARIES
    -lpthread
    ${LIB_SDL2}
    #${LIB_OPENGEL}
    #${LIB_PYTHON}
    #${LIB_LUA}
    #${LIB_SQLITE3}
    #${LIB_MYSQL}
    )

set(TEST_LIBRARIES
    -lgtest
    -lgtest_main
    ${LIBRARIES})


#
# Conan
#

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


#
# SDL
#

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2GFX REQUIRED SDL2_gfx>=1.0.4)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
pkg_search_module(SDL2NET REQUIRED SDL2_net>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

#
# Includes
#

set(INCLUDES_AUDIO
    code/include/cyaudio/SDLAudio.hpp
    code/include/cyaudio/SDLMixerAudio.hpp
    code/include/cyaudio/devices/IAudioDevice.hpp
    code/include/cyaudio/devices/SDLAudioDevice.hpp
    code/include/cyaudio/medium/IMedium.hpp
    code/include/cyaudio/medium/SDLMusic.hpp)

set(INCLUDES_MATH
    code/include/cymath/Point.hpp
    code/include/cymath/Line.hpp
    code/include/cymath/Vector.hpp
    code/include/cymath/Rectangle.hpp
    code/include/cymath/Space.hpp
    code/include/cymath/Size.hpp)

set(INCLUDES_GUI
    code/include/cygui/styles/ObjectStyle.hpp
    code/include/cygui/widgets/Object.hpp
    code/include/cygui/styles/WidgetStyle.hpp
    code/include/cygui/widgets/Widget.hpp
    code/include/cygui/styles/Style.hpp
    code/include/cygui/widgets/Button.hpp
    code/include/cygui/styles/ButtonStyle.hpp
    code/include/cygui/styles/TextStyle.hpp)

set(INCLUDES_INPUT
    code/include/cyinput/Keyboard.hpp
    code/include/cyinput/Mouse.hpp
    code/include/cyinput/Controller.hpp
    code/include/cyinput/Keys.hpp
    code/include/cyinput/Key.hpp
    code/include/cyinput/IKey.hpp
    code/include/cyinput/Keymod.hpp
    code/include/cyinput/KeyCombination.hpp)

set(INCLUDES_NET
    code/include/cynet/netPrototypes.hpp
    code/include/cynet/ISocket.hpp
    code/include/cynet/ISDLSocket.hpp
    code/include/cynet/SDLTCPSocket.hpp
    code/include/cynet/IP4Address.hpp
    code/include/cynet/IIPAddress.hpp
    code/include/cynet/ITCPServer.hpp
    code/include/cynet/IServer.hpp
    code/include/cynet/IClient.hpp
    code/include/cynet/ITCPClient.hpp
    code/include/cynet/ITCPSocket.hpp
    code/include/cynet/SDLTCPClient.hpp
    code/include/cynet/SDLTCPServer.hpp
    code/include/cynet/NetworkPackage.hpp)

set(INCLUDES_STD
    code/include/cystd/NonCopyable.hpp
    code/include/cystd/NonMoveable.hpp
    code/include/cystd/Range.hpp
    code/include/cystd/stdPrototypes.hpp
    code/include/cystd/Enum.hpp
    code/include/cystd/CyObj.hpp)

set(INCLUDES_SYSTEM
    code/include/cysystem/Platform.hpp
    code/include/cysystem/IScheduler.hpp
    code/include/cysystem/Scheduler.hpp
    code/include/cysystem/ITask.hpp
    code/include/cysystem/SchedulerTask.hpp
    code/include/cysystem/Thread.hpp)

set(INCLUDES_UTIL
    code/include/cyutil/color/Color.hpp
    code/include/cyutil/time/ITimer.hpp
    code/include/cyutil/io/Print.hpp
    code/source/cyutil/time/SDLTimer.cpp
    code/include/cyutil/time/SDLTimer.hpp
    code/source/cyutil/time/SDLPerformanceTimer.cpp
    code/include/cyutil/time/SDLPerformanceTimer.hpp
    code/include/cyutil/util.hpp
    code/include/cyutil/type/TypeName.hpp
    code/include/cyutil/serialize/ISerialize.hpp)

set(INCLUDES_VIDEO
    code/include/cyvideo/IWindow.hpp
    code/include/cyvideo/IRenderer.hpp
    code/include/cyvideo/ITexture.hpp
    code/include/cyvideo/SDLWindow.hpp
    code/include/cyvideo/SDLRenderer.hpp
    code/include/cyvideo/SDLVideo.hpp
    code/include/cyvideo/SDLDisplay.hpp
    code/include/cyvideo/IDisplay.hpp
    code/include/cyvideo/ISurface.hpp
    code/include/cyvideo/IFont.hpp
    code/include/cyvideo/SDLFont.hpp
    code/include/cyvideo/SDLTexture.hpp
    code/include/cyvideo/SDLSurface.hpp
    code/include/cyvideo/videoPrototypes.hpp)

set(INCLUDES
    ${INCLUDES_STD}
    ${INCLUDES_AUDIO}
    ${INCLUDES_MATH}
    ${INCLUDES_GUI}
    ${INCLUDES_INPUT}
    ${INCLUDES_NET}
    ${INCLUDES_SYSTEM}
    ${INCLUDES_UTIL}
    ${INCLUDES_VIDEO})


#
# Sources
#

set(SOURCES_STD)

set(SOURCES_AUDIO
    code/source/cyaudio/SDLAudio.cpp
    code/source/cyaudio/SDLMixerAudio.cpp
    code/source/cyaudio/medium/SDLMusic.cpp
    code/source/cyaudio/devices/SDLAudioDevice.cpp)

set(SOURCES_MATH
    code/source/cymath/Point.cpp
    code/source/cymath/Line.cpp
    code/source/cymath/Vector.cpp
    code/source/cymath/Rectangle.cpp
    code/source/cymath/Space.cpp
    code/source/cymath/Size.cpp)

set(SOURCES_GUI
    code/source/cygui/widgets/Widget.cpp
    code/source/cygui/styles/WidgetStyle.cpp
    code/source/cygui/widgets/Object.cpp
    code/source/cygui/styles/ObjectStyle.cpp
    code/source/cygui/widgets/Button.cpp
    code/source/cygui/styles/ButtonStyle.cpp
    code/include/cygui/styles/TextStyle.cpp)

set(SOURCES_INPUT
    code/source/cyinput/Controller.cpp
    code/source/cyinput/KeyCombination.cpp
    code/source/cyinput/Keyboard.cpp
    code/source/cyinput/Keymod.cpp
    code/source/cyinput/Mouse.cpp)

set(SOURCES_NET
    code/source/cynet/ISDLSocket.cpp
    code/source/cynet/SDLTCPSocket.cpp
    code/source/cynet/ITCPServer.cpp
    code/source/cynet/IP4Address.cpp
    code/source/cynet/ITCPClient.cpp
    code/source/cynet/ISocket.cpp
    code/source/cynet/ITCPSocket.cpp
    code/source/cynet/SDLTCPClient.cpp
    code/source/cynet/SDLTCPServer.cpp
    code/source/cynet/NetworkPackage.cpp)

set(SOURCES_STD
    )

set(SOURCES_SYSTEM
    code/source/cysystem/Platform.cpp
    code/source/cysystem/Scheduler.cpp
    code/source/cysystem/SchedulerTask.cpp)

set(SOURCES_UTIL
    code/source/cyutil/color/Color.cpp
    code/source/cyutil/io/Print.cpp
    code/source/cyutil/time/Clock.cpp
    code/include/cyutil/time/Clock.hpp
    code/include/cyutil/time/time.hpp
    code/source/cyutil/serialize/ISerialize.cpp
    code/include/cyutil/type/TypeEnum.hpp)

set(SOURCES_VIDEO
    code/source/cyvideo/SDLRenderer.cpp
    code/source/cyvideo/SDLWindow.cpp
    code/source/cyvideo/SDLVideo.cpp
    code/source/cyvideo/SDLDisplay.cpp
    code/source/cyvideo/SDLFont.cpp
    code/source/cyvideo/SDLTexture.cpp
    code/source/cyvideo/SDLSurface.cpp)

set(SOURCES
    ${SOURCES_AUDIO}
    ${SOURCES_MATH}
    ${SOURCES_GUI}
    ${SOURCES_INPUT}
    ${SOURCES_NET}
    ${SOURCES_STD}
    ${SOURCES_SYSTEM}
    ${SOURCES_UTIL}
    ${SOURCES_VIDEO})


#
# All files
#

set(FILES ${INCLUDES} ${SOURCES})


#
# Tests
#

set(TEST_SOURCES_AUDIO)

set(TEST_SOURCES_GUI)

set(TEST_SOURCES_INPUT)

set(TEST_SOURCES_MATH
    code/test/cymath/test_point.cpp)

set(TEST_SOURCES_NET)

set(TEST_SOURCES_STD)

set(TEST_SOURCES_SYSTEM)

set(TEST_SOURCES_UTIL)

set(TEST_SOURCES_VIDEO)

set(TEST_SOURCES
    ${TEST_SOURCES_AUDIO}
    ${TEST_SOURCES_GUI}
    ${TEST_SOURCES_INPUT}
    ${TEST_SOURCES_MATH}
    ${TEST_SOURCES_NET}
    ${TEST_SOURCES_STD}
    ${TEST_SOURCES_SYSTEM}
    ${TEST_SOURCES_UTIL}
    ${TEST_SOURCES_VIDEO})

set(TEST_FILES
    ${FILES}
    ${TEST_SOURCES})


#
# Builds
#

add_executable(${PROJECT_NAME} ${FILES} code/apps/main.cpp)
add_executable(${PROJECT_NAME}_Server ${FILES} code/apps/server.cpp)
add_executable(${PROJECT_NAME}_Client ${FILES} code/apps/client.cpp)
add_executable(${PROJECT_NAME}_Test ${TEST_FILES} code/test/test.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
target_link_libraries(${PROJECT_NAME}_Server ${LIBRARIES})
target_link_libraries(${PROJECT_NAME}_Client ${LIBRARIES})
target_link_libraries(${PROJECT_NAME}_Test ${TEST_LIBRARIES})