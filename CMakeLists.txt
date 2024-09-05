cmake_minimum_required(VERSION 3.10)
project(Pong)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES 
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(Pong ${SOURCES})
