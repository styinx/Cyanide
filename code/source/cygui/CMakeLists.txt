project(cygui CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Sources
#

set(SOURCES
        input/ObjectInput.cpp

        layout/Box.cpp
        layout/Grid.cpp
        layout/HBox.cpp
        layout/VBox.cpp

        styles/BoxStyle.cpp
        styles/ButtonStyle.cpp
        styles/ObjectStyle.cpp
        styles/TextWidgetStyle.cpp
        styles/WidgetStyle.cpp

        widgets/Button.cpp
        widgets/Object.cpp
        widgets/TextWidget.cpp
        widgets/Widget.cpp)


#
# Builds
#

add_library(cygui SHARED STATIC ${SOURCES})
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(cygui PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()
target_link_libraries(cygui PRIVATE cyinput)
