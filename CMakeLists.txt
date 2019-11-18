cmake_minimum_required(VERSION 3.13)
project(main)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
# Add the source in project root directory
aux_source_directory(. DIRSRCS)
# Add header file include directories
include_directories(./ ./src)

# Add block directories
add_subdirectory(src)
add_subdirectory(test)
# Target
add_executable(main ${DIRSRCS})
target_link_libraries(main gildedRose)

