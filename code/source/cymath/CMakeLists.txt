project(cymath CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Sources
#

set(SOURCES
        Line.cpp
        Point.cpp
        Size.cpp
        Space.cpp
        Rectangle.cpp
        Vector.cpp)


#
# Builds
#

add_library(cymath SHARED STATIC ${SOURCES})
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(cymath PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()
