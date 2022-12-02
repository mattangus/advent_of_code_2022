add_subdirectory(lib)

file(GLOB SRC_FILES *.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(advent ${SRC_FILES})
target_link_libraries(advent ${ADVENT_LIBS})