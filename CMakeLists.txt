cmake_minimum_required(VERSION 3.12)

project(Cyanide)

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

set(LIB_SDL
    -lSDL2main
    -lSDL2
    -lSDL2_image
    -lSDL2_mixer
    -lSDL2_ttf
    -lSDL2_net
    -lSDL2_gfx)

set(LIBRARIES
    -lpthread
    -lsqlite3
    -lmysqlclient

    ${LIB_SDL}

    -llua5.2
    -lpython3.6m
    -lGLEW -lGL)


#
# Includes
#

set(INCLUDES_AUDIO
    code/include/audio/audio_devices/AudioDevice.hpp
    code/include/audio/interfaces/IAudioDevice.hpp
    code/include/audio/interfaces/IAudioDriver.hpp)

set(INCLUDES
    ${INCLUDES_AUDIO})


#
# Sources
#

#set(sources_audio
#        code/source/audio/audio.cpp)

set(SOURCES
    ${APPS})

set(FILES ${INCLUDES} ${SOURCES})


#
# Builds
#

add_executable(${PROJECT_NAME} code/apps/main.cpp ${FILES})

#target_link_libraries(${LIBRARIES})