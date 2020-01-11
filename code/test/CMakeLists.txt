add_subdirectory(cyaudio)
add_subdirectory(cygui)
add_subdirectory(cyinput)
add_subdirectory(cymath)
add_subdirectory(cystd)
add_subdirectory(cyutil)
add_subdirectory(cyvideo)

set(TESTS ${TESTS}
    ${TESTS_AUDIO}
    ${TESTS_GUI}
    ${TESTS_INPUT}
    ${TESTS_MATH}
    ${TESTS_STD}
    ${TESTS_UTIL}
    ${TESTS_VIDEO})
