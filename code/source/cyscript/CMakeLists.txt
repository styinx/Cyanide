project(cynet CXX)

#
# CMake
#

cmake_minimum_required(VERSION 3.21.1)


#
# Third party
#

find_package(Lua REQUIRED)
find_package(Python3 COMPONENTS Development REQUIRED)


#
# Sources
#

set(SOURCES
        lua/Lua.cpp
        python/Python.cpp)


#
# Builds
#

cy_add_module(cyscript ${SOURCES})
target_link_libraries(cyscript PRIVATE ${LUA_LIBRARIES} Python3::Python)
