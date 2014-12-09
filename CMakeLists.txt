cmake_minimum_required(VERSION 3.0)
project(testing CXX)


#
# RPATH Settings:
#
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
LIST(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
IF("${isSystemDir}" STREQUAL "-1")
   SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
ENDIF("${isSystemDir}" STREQUAL "-1")


#
# Compile external project:
#
set(EXT_LIB_NAME "libExtLib.so")
include(ExternalProject)
ExternalProject_add(
  ExtLibBuild
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake-SO-question-ExtLib"
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND ""
  BUILD_COMMAND $(MAKE)
  INSTALL_COMMAND cp ${EXT_LIB_NAME} "${CMAKE_BINARY_DIR}/${EXT_LIB_NAME}"
)


#
# Add external project as imported library target:
#
add_library(ExtLib SHARED IMPORTED)
set_property(TARGET ExtLib PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/${EXT_LIB_NAME}")
#set_property(TARGET ExtLib PROPERTY IMPORTED_NO_SONAME 1) # CMake side fix for problem
add_dependencies(ExtLib ExtLibBuild)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/cmake-SO-question-ExtLib")


#
# Add sub for all src:
#
add_subdirectory(src)
