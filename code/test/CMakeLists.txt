project(cyaudio CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Third party
#

find_package(sdl2-mixer CONFIG REQUIRED)


#
# Sources
#

set(SOURCES
        test/cygui/test_Box.cpp

        test/cymath/test_Line.cpp
        test/cymath/test_Point.cpp
        test/cymath/test_Rectangle.cpp
        test/cymath/test_Size.cpp
        test/cymath/test_Space.cpp
        test/cymath/test_Vector.cpp

        test/cyvideo/test_SDLTexture.cpp)

#
# Builds
#

cy_build_target(cytest ${SOURCES})
target_link_libraries(cytest PRIVATE ${TEST_LIBRARIES})

