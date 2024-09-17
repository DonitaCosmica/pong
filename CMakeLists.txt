cmake_minimum_required(VERSION 3.10)
project(Pong)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES
  ${CMAKE_SOURCE_DIR}/src/*.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(Pong ${SOURCES})
target_link_libraries(Pong ${CURSES_LIBRARIES} pthread)
