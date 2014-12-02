cmake_minimum_required(VERSION 3.0)
project(testing CXX)

include(ext/CMakeLists.txt) # Doesn't work with 'add_subdirectory'

add_subdirectory(src)
