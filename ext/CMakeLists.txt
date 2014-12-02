include(ExternalProject)

set(EXT_LIB_NAME "libExtLib.so")

ExternalProject_add(
  ExtLibBuild
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ext/cmake-superprj-lib-test"
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND ""
  BUILD_COMMAND $(MAKE)
  INSTALL_COMMAND cp ${EXT_LIB_NAME} "${CMAKE_BINARY_DIR}/src/lib/${EXT_LIB_NAME}"
)

add_library(ExtLib SHARED IMPORTED)
set_property(TARGET ExtLib PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/src/lib/${EXT_LIB_NAME}")
add_dependencies(ExtLib ExtLibBuild)
