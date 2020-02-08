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

set(DIR_CODE ${PROJECT_SOURCE_DIR}/code)
set(DIR_APP ${DIR_CODE}/apps)
set(DIR_INCLUDE ${DIR_CODE}/include)
set(DIR_SOURCE ${DIR_CODE}/source)
set(DIR_TEST ${DIR_CODE}/test)
set(DIR_LIBRARY /lib)


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
# Functions
#

function(cy_add_library library)
    set(${library}_includes)
    set(${library}_sources)

    include("${DIR_INCLUDE}/${library}/CMakeLists.txt")
    include("${DIR_SOURCE}/${library}/CMakeLists.txt")

    add_library(${library} STATIC ${${library}_includes} ${${library}_sources})
    target_link_libraries(${library} ${ARGN})
    set_target_properties(
            ${library} PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY ${DIR_LIBRARY}
            LINKER_LANGUAGE CXX)
endfunction()

function(cy_add_test library)
    set(${library}_files)

    include("${DIR_TEST}/CMakeLists.txt")

    add_library(${library} STATIC ${${library}_files})
    target_link_libraries(${library} ${ARGN})
    set_target_properties(
            ${library} PROPERTIES
            LIBRARY_OUTPUT_DIRECTORY ${DIR_LIBRARY}
            LINKER_LANGUAGE CXX)
endfunction()

function(cy_add_target_files target)
    set(files "")
    foreach(file ${ARGN})
        list(APPEND files "${CMAKE_CURRENT_LIST_DIR}/${file}")
    endforeach()

    set(${target} ${files} PARENT_SCOPE)
endfunction()

function(cy_build_target name target_file libs)
    set(exe_name ${PROJECT_NAME})

    if(${name} MATCHES "")
        set(exe_name ${PROJECT_NAME}_${name})
    endif()

    add_executable(${exe_name} ${DIR_CODE}/${target_file})

    set(module_list "")
    foreach(module ${ARGN})
        list(APPEND module_list "${module}")
    endforeach()

    target_link_libraries(${exe_name} ${module_list} ${libs})
endfunction()

#
# Compiler
#

SET(GCC_COMPILE_FLAGS "-Wall -Wextra -ansi -pedantic")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

set(CMAKE_BUILD_TYPE RELEASE)


#
# Libraries
#

set(LIB_OPENGL -lGLEW -lGL)

set(LIB_PYTHON -lpython3.6m)

set(LIB_LUA -llua5.2)

set(LIB_SQLITE3 -lsqlite3)

set(LIB_MYSQL -lmysqlclient)

set(LIBRARIES -lpthread -lSDL2main -lSDL2)

set(TEST_LIBRARIES -lgtest -lgtest_main ${LIBRARIES})


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
pkg_search_module(SDL2GFX REQUIRED SDL2_gfx>=1.0.0)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
pkg_search_module(SDL2NET REQUIRED SDL2_net>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

#
# Builds
#

cy_add_library(cyaudio -lSDL2_mixer)
cy_add_library(cygui)
cy_add_library(cyinput)
cy_add_library(cymath)
cy_add_library(cynet -lSDL2_net)
cy_add_library(cystd)
cy_add_library(cysystem "-lSDL2_image;-lSDL2_gfx;-lSDL2_mixer;-lSDL2_net;-lSDL2_ttf")
cy_add_library(cyutil)
cy_add_library(cyvideo "cymath;-lSDL2_image;-lSDL2_gfx;-lSDL2_ttf")

cy_add_test(cytest ${TEST_LIBRARIES})

cy_build_target(Main apps/main.cpp "${LIBRARIES}" "cygui;cyinput;cymath;cyutil;cysystem;cyvideo")
cy_build_target(Animation apps/animation.cpp "${LIBRARIES}" "cyinput;cymath;cyutil;cysystem;cyvideo")
cy_build_target(Client apps/client.cpp "${LIBRARIES}" "cynet")
cy_build_target(Server apps/server.cpp "${LIBRARIES}" "cynet")
cy_build_target(Test test/test.cpp "${TEST_LIBRARIES}" "cytest")
