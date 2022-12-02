file(GLOB SRC_FILES *.cpp)

set(LIBS "")

foreach(file ${SRC_FILES})
    get_filename_component(lib_name ${file} NAME_WE)
    add_library(${lib_name} SHARED ${file})
    list(APPEND LIBS ${lib_name})
endforeach()

set(ADVENT_LIBS ${LIBS} PARENT_SCOPE)