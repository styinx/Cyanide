project(Cyanide)


#
# CMake
#

cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

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

set(LIB_PYTHON -lpython3.6m)

set(LIB_LUA -llua5.2)

set(LIB_SQLITE3 -lsqlite3)

set(LIB_MYSQL -lmysqlclient)

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

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
PKG_SEARCH_MODULE(SDL2NET REQUIRED SDL2_net>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

#
# Includes
#

set(INCLUDES_CYSTD
    code/include/cystd/prototypes.hpp
    code/include/cystd/NonCopyable.hpp
    code/include/cystd/NonMoveable.hpp)

set(INCLUDES_CYAUDIO
    code/include/cyaudio/audio_devices/SDLAudioDevice.hpp
    code/include/cyaudio/IAudioDevice.hpp)

set(INCLUDES
    ${INCLUDES_CYSTD}
    ${INCLUDES_CYAUDIO})


#
# Sources
#

set(SOURCES_CYSTD
    )

set(SOURCES_AUDIO
    code/source/cyaudio/audio_devices/SDLAudioDevice.cpp
    code/source/cyaudio/SDLAudio.cpp
    code/include/cyaudio/SDLAudio.hpp)

set(SOURCES
    ${SOURCES_AUDIO})

#
# Tests
#

set(TESTS
    code/test/cyaudio/test.cpp)

set(FILES ${INCLUDES} ${SOURCES})


#
# Builds
#

add_executable(${PROJECT_NAME} code/apps/main.cpp ${FILES})

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})