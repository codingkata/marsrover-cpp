cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

aux_source_directory(. DIR_SRCS)
add_library(marsrover STATIC  ${DIR_SRCS})
target_include_directories(marsrover PUBLIC ${DIR_SRCS})

