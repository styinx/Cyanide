project(source)

add_subdirectory(cyaudio)
add_subdirectory(cygui)
add_subdirectory(cyinput)
add_subdirectory(cymath)
add_subdirectory(cystd)
add_subdirectory(cyutil)
add_subdirectory(cyvideo)

set(SOURCES
    ${SOURCES_AUDIO}
    ${SOURCES_GUI}
    ${SOURCES_INPUT}
    ${SOURCES_MATH}
    ${SOURCES_STD}
    ${SOURCES_UTIL}
    ${SOURCES_VIDEO})
