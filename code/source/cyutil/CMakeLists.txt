project(cyutil CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Third party
#

find_package(fmt)


#
# Sources
#

set(SOURCES
        animation/Animation.cpp

        color/RGBAColor.cpp
        color/animation/ColorAnimation.cpp

        io/Print.cpp

        logging/Logging.cpp

        serialize/ISerialize.cpp

        threading/IntervalScheduler.cpp
        threading/Scheduler.cpp
        threading/Thread.cpp
        threading/ThreadedTask.cpp

        time/Clock.cpp
        time/Timer.cpp)


#
# Builds
#

add_library(cyutil SHARED STATIC ${SOURCES})
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(cyutil PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()
target_link_libraries(cyutil PRIVATE fmt::fmt)
