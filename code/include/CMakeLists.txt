project(include)

add_subdirectory(cyaudio)
add_subdirectory(cygui)
add_subdirectory(cyinput)
add_subdirectory(cymath)
add_subdirectory(cystd)
add_subdirectory(cyutil)
add_subdirectory(cyvideo)

set(INCLUDES
    ${INCLUDES_AUDIO}
    ${INCLUDES_GUI}
    ${INCLUDES_INPUT}
    ${INCLUDES_MATH}
    ${INCLUDES_STD}
    ${INCLUDES_UTIL}
    ${INCLUDES_VIDEO})
