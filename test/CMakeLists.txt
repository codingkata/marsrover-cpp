project(unittest)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/include)

aux_source_directory(. DIR_TESTS)

add_executable(unittest ${DIR_TESTS})
target_link_libraries(unittest ${CMAKE_CURRENT_SOURCE_DIR}/../lib/libgmock_main.a  ${CMAKE_CURRENT_SOURCE_DIR}/../lib/libgmock.a ${CMAKE_CURRENT_SOURCE_DIR}/../lib/libgtest.a gildedRose)

include_directories(${CMAKE_SOURCE_DIR}/lib/include)
