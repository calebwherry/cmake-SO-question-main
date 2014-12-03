cmake_minimum_required(VERSION 3.0)
project(testing CXX)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/build/install")

include(ext/CMakeLists.txt) # Doesn't work with 'add_subdirectory'

add_subdirectory(src)
