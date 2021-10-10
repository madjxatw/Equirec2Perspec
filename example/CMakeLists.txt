cmake_minimum_required(VERSION 3.2)

project(e2p_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# package config file search path in build-tree
set(CMAKE_PREFIX_PATH ${PROJECT_BINARY_DIR}/cmake ${CMAKE_PREFIX_PATH})
find_package(Equirec2Perspec NO_MODULE)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/common.h.in"
  "${CMAKE_CURRENT_SOURCE_DIR}/common.h" @ONLY)

add_executable(e2p example.cpp)
target_link_libraries(e2p ${OpenCV_LIBS} Equirec2Perspec)

file(COPY data DESTINATION .)
