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
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(OS_DIR_INCLUDE C:/Include/)
    set(OS_DIR_LIBRARY C:/Libs/)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")


include_directories(${DIR_INCLUDE} ${OS_DIR_INCLUDE})
link_directories(${DIR_LIBRARY} ${OS_DIR_LIBRARY})


#
# Libraries
#

set(LIB_SDL2
    -lSDL2main
    -lSDL2
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
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
pkg_search_module(SDL2NET REQUIRED SDL2_net>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

#
# Includes
#

set(INCLUDES_STD
    code/include/cystd/NonCopyable.hpp
    code/include/cystd/NonMoveable.hpp
    code/include/cystd/Range.hpp
    code/include/cystd/stdPrototypes.hpp
    code/include/cystd/Enum.hpp)

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
    code/include/cygui/widgets/Widget.hpp)

set(INCLUDES_INPUT
    code/include/cyinput/Keyboard.hpp
    code/include/cyinput/Mouse.hpp
    code/include/cyinput/Controller.hpp)

set(INCLUDES_NET
    code/include/cynet/ISocket.hpp)

set(INCLUDES_SYSTEM
    code/include/cysystem/Platform.hpp)

set(INCLUDES_UTIL
    code/include/cyutil/formats/IParser.hpp
    code/include/cyutil/formats/INIParser.hpp
    code/include/cyutil/io/IReader.hpp
    code/include/cyutil/io/ioPrototypes.hpp
    code/include/cyutil/io/BitStreamReader.hpp
    code/include/cyutil/io/IWriter.hpp
    code/include/cyutil/color/Color.hpp
    code/include/cyutil/formats/Value.hpp
    code/include/cyutil/flags/Flag.hpp)

set(INCLUDES_VIDEO
    code/include/cyvideo/IWindow.hpp
    code/include/cyvideo/IRenderer.hpp
    code/include/cyvideo/ITexture.hpp
    code/include/cyvideo/SDLWindow.hpp
    code/include/cyvideo/SDLRenderer.hpp)

set(INCLUDES
    ${INCLUDES_STD}
    ${INCLUDES_AUDIO}
    ${INCLUDES_MATH}
    ${INCLUDES_GUI}
    ${INCLUDES_INPUT}
    ${INCLUDES_NET}
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
    code/source/cygui/styles/ObjectStyle.cpp)

set(SOURCES_INPUT
    code/source/cyinput/Keyboard.cpp
    code/source/cyinput/Controller.cpp
    code/source/cyinput/Mouse.cpp)

set(SOURCES_NET)

set(SOURCES_SYSTEM
    code/source/cysystem/Platform.cpp)

set(SOURCES_UTIL
    code/include/cyutil/io/BitStreamReader.cpp
    code/source/cyutil/formats/INIParser.cpp
    code/source/cyutil/color/Color.cpp
    code/source/cyutil/flags/Flag.cpp
    code/source/cyutil/formats/Value.cpp)

set(SOURCES_VIDEO
    code/source/cyvideo/SDLRenderer.cpp
    code/source/cyvideo/SDLWindow.cpp)

set(SOURCES
    ${SOURCES_AUDIO}
    ${SOURCES_MATH}
    ${SOURCES_GUI}
    ${SOURCES_INPUT}
    ${SOURCES_NET}
    ${SOURCES_UTIL}
    ${SOURCES_VIDEO})


#
# All files
#

set(FILES ${INCLUDES} ${SOURCES})

#
# Tests
#

set(TEST_SOURCES
    code/test/cyaudio/test.cpp
    code/test/cymath/test_point.cpp
    code/test/cyvideo/test.cpp)

set(TEST_LIBRARIES
    ${LIBRARIES}
    -lgtest
    -lgtest_main)

set(TEST_FILES
    ${FILES}
    ${TEST_SOURCES})


#
# Builds
#

add_executable(${PROJECT_NAME} ${FILES} code/apps/main.cpp)
add_executable(${PROJECT_NAME}_Test ${TEST_FILES} code/test/test.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
target_link_libraries(${PROJECT_NAME}_Test ${TEST_LIBRARIES})