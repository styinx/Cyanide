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
set(DIR_INCLUDE ${DIR_CODE}/include)
set(DIR_SOURCE ${DIR_CODE}/source)
set(DIR_TEST ${DIR_CODE}/test)
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
# Functions
#

function(cy_add_include_dir path)
    include("${DIR_INCLUDE}/${path}/CMakeLists.txt")
    set(INCLUDES ${INCLUDES} PARENT_SCOPE)
endfunction()

function(cy_add_source_dir path)
    include("${DIR_SOURCE}/${path}/CMakeLists.txt")
    set(SOURCES ${SOURCES} PARENT_SCOPE)
endfunction()

function(cy_add_test_dir path)
    include("${DIR_TEST}/${path}/CMakeLists.txt")
    set(TEST_SOURCES ${TEST_SOURCES} PARENT_SCOPE)
endfunction()

function(cy_add_includes)
    set(files "")
    foreach(file ${ARGN})
        list(APPEND files "${CMAKE_CURRENT_LIST_DIR}/${file}")
    endforeach()

    set(INCLUDES ${INCLUDES} ${files} PARENT_SCOPE)
endfunction()

function(cy_add_sources)
    set(files "")
    foreach(file ${ARGN})
        list(APPEND files "${CMAKE_CURRENT_LIST_DIR}/${file}")
    endforeach()

    set(SOURCES ${SOURCES} ${files} PARENT_SCOPE)
endfunction()

function(cy_add_test_sources)
    set(files "")
    foreach(file ${ARGN})
        list(APPEND files "${CMAKE_CURRENT_LIST_DIR}/${file}")
    endforeach()

    set(TEST_SOURCES ${TEST_SOURCES} ${files} PARENT_SCOPE)
endfunction()


#
# Compiler
#

SET(GCC_COMPILE_FLAGS "-Wall -Wextra -ansi -pedantic")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")


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
pkg_search_module(SDL2GFX REQUIRED SDL2_gfx>=1.0.0)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
pkg_search_module(SDL2NET REQUIRED SDL2_net>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

#
# Includes
#

cy_add_include_dir(cyaudio)
cy_add_include_dir(cygui)
cy_add_include_dir(cyinput)
cy_add_include_dir(cymath)
cy_add_include_dir(cynet)
cy_add_include_dir(cystd)
cy_add_include_dir(cysystem)
cy_add_include_dir(cyutil)
cy_add_include_dir(cyvideo)


#
# Sources
#

cy_add_source_dir(cyaudio)
cy_add_source_dir(cygui)
cy_add_source_dir(cyinput)
cy_add_source_dir(cymath)
cy_add_source_dir(cynet)
cy_add_source_dir(cystd)
cy_add_source_dir(cysystem)
cy_add_source_dir(cyutil)
cy_add_source_dir(cyvideo)


#
# All files
#

set(FILES ${INCLUDES} ${SOURCES})


#
# Tests
#

cy_add_test_dir(cyaudio)
cy_add_test_dir(cygui)
cy_add_test_dir(cyinput)
cy_add_test_dir(cymath)
cy_add_test_dir(cynet)
cy_add_test_dir(cystd)
cy_add_test_dir(cysystem)
cy_add_test_dir(cyutil)
cy_add_test_dir(cyvideo)


set(TEST_FILES
    ${FILES}
    ${TEST_SOURCES})


#
# Builds
#

add_executable(${PROJECT_NAME} ${FILES} code/apps/main.cpp)
add_executable(${PROJECT_NAME}_Client ${FILES} code/apps/client.cpp)
add_executable(${PROJECT_NAME}_Server ${FILES} code/apps/server.cpp)
add_executable(${PROJECT_NAME}_Test ${TEST_FILES} code/test/test.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
target_link_libraries(${PROJECT_NAME}_Client ${LIBRARIES})
target_link_libraries(${PROJECT_NAME}_Server ${LIBRARIES})
target_link_libraries(${PROJECT_NAME}_Test ${TEST_LIBRARIES})
