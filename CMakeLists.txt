project(Cyanide CXX)


#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Paths
#

set(DIR_ROOT "${PROJECT_SOURCE_DIR}")
set(DIR_CODE "${DIR_ROOT}/code")
set(DIR_APP "${DIR_CODE}/apps")
set(DIR_INCLUDE "${DIR_CODE}/include")
set(DIR_SOURCE "${DIR_CODE}/source")
set(DIR_TEST "${DIR_CODE}/test")
set(DIR_LIBRARY "${DIR_ROOT}/lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${DIR_LIBRARY}/deb")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${DIR_LIBRARY}/deb")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${DIR_ROOT})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${DIR_LIBRARY}/rel")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${DIR_LIBRARY}/rel")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${DIR_ROOT})

set(DIR_VCPKG_INSTALL "${DIR_VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET}")
set(DIR_VCPKG_INCLUDE "${DIR_VCPKG_INSTALL}/include")
set(DIR_VCPKG_LIBRARY "${DIR_VCPKG_INSTALL}/lib")
set(DIR_VCPKG_LIBRARY_DEBUG "${DIR_VCPKG_INSTALL}/debug/lib")


if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(OS_DIR_INCLUDE /usr/include/)
    set(OS_DIR_LIBRARY /usr/libs/)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(OS_DIR_INCLUDE C:/Include/)
    set(OS_DIR_LIBRARY C:/Libs/)
endif()


if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
    set(LIBRARY_DIRECTORIES
            ${DIR_VCPKG_LIBRARY}
            ${DIR_VCPKG_LIBRARY}/deb)
else()
    set(LIBRARY_DIRECTORIES
            ${DIR_VCPKG_LIBRARY}
            ${DIR_VCPKG_LIBRARY}/rel)
endif()


#
# Functions
#

# Build a static library from files in a given path.
function(cy_add_module module)
    add_library(${module} SHARED STATIC ${ARGN})
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        set_target_properties(${module} PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif ()
    set_target_properties(${module} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${DIR_LIBRARY} LINKER_LANGUAGE CXX)
endfunction()

# Build the executable from library dependencies.
function(cy_build_target name target_file libs)
    add_executable(${name} ${DIR_CODE}/${target_file})
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        set_target_properties(${name} PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif ()

    target_link_libraries(${name} PRIVATE ${libs})
endfunction()

function(dump_vars)
    get_cmake_property(_variableNames VARIABLES)
    list (SORT _variableNames)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
endfunction()


#
# Compiler
#

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang") # Clang
    #
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU") # GCC
    set(COMPILER_FLAGS "-Wall -Wextra -ansi -pedantic")
    set(COMPILER_FLAGS_DEBUG "-MTd")
    set(COMPILER_FLAGS_RELEASE "-O3 -DNDEBUG -MT")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") # MSVC
    set(COMPILER_FLAGS "")
    set(COMPILER_FLAGS_DEBUG "/Zi /Ob0 /Od /RTC1 /MTd")
    set(COMPILER_FLAGS_RELEASE "/O2 /Ob2 /DNDEBUG /MT")
endif ()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${COMPILER_FLAGS} ${COMPILER_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${COMPILER_FLAGS} ${COMPILER_FLAGS_RELEASE}")


#
# Libraries
#

set(LIB_OPENGL -lGLEW -lGL)

set(LIB_SQLITE3 -lsqlite3)

set(LIB_MYSQL -lmysqlclient)

set(LIBRARIES -lpthread -lSDL2main -lSDL2)

set(TEST_LIBRARIES -lgtest -lgtest_main ${LIBRARIES})


#
# Third party
#

find_package(SDL2 REQUIRED)


#
# Dependencies
#

# SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static

include_directories(${DIR_INCLUDE} ${OS_DIR_INCLUDE} ${SDL2_INCLUDE_DIRS} ${LUA_INCLUDE_DIR} ${Python3_INCLUDE_DIR})
link_directories(${DIR_LIBRARY} ${OS_DIR_LIBRARY} ${LIBRARY_DIRECTORIES})

add_subdirectory(code/source/cyaudio)
add_subdirectory(code/source/cygui)
add_subdirectory(code/source/cyinput)
add_subdirectory(code/source/cymath)
add_subdirectory(code/source/cynet)
add_subdirectory(code/source/cyscript)
add_subdirectory(code/source/cysystem)
add_subdirectory(code/source/cyutil)
add_subdirectory(code/source/cyvideo)
add_subdirectory(code/test)


#
# Builds
#

cy_build_target(Main apps/main.cpp "cyaudio;cygui;cyinput;cymath;cynet;cyutil;cysystem;cyvideo")
cy_build_target(Animation apps/animation.cpp "cyaudio;cyinput;cymath;cynet;cyutil;cysystem;cyvideo")
#cy_build_target(Input apps/input.cpp "${LIBRARIES}" "cygui;cyinput;cymath;cyutil;cysystem;cyvideo")
#cy_build_target(Client apps/client.cpp "${LIBRARIES}" "cynet;cysystem;cyutil;")
#cy_build_target(Server apps/server.cpp "${LIBRARIES}" "cynet;cysystem;cyutil;")
#cy_build_target(UI apps/ui.cpp "${LIBRARIES}" "cygui;cyinput;cymath;cyutil;cysystem;cyvideo")
