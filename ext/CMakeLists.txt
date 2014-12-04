include(ExternalProject)

# Static and shared lib names:
set(EXT_LIB_NAME_SHARED "libExtLib.so")
set(EXT_LIB_NAME_STATIC "libExtLib.a")

# Which lib to use:
# NOTE: SHARED does not work and is the reason for the SO question. Changing to STATIC 'fixes' the issue for now.
set(EXT_LIB_NAME "${EXT_LIB_NAME_SHARED}")

# Add external project:
ExternalProject_add(
  ExtLibBuild
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ext/cmake-superprj-lib-test"
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND ""
  BUILD_COMMAND $(MAKE) ${EXT_LIB_NAME}
  INSTALL_COMMAND cp ${EXT_LIB_NAME} "${CMAKE_BINARY_DIR}/src/lib/${EXT_LIB_NAME}" && mkdir -p "${CMAKE_INSTALL_PREFIX}/lib" && cp ${EXT_LIB_NAME} "${CMAKE_INSTALL_PREFIX}/lib"
)

add_library(ExtLib UNKNOWN IMPORTED)
set_property(TARGET ExtLib PROPERTY IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/src/lib/${EXT_LIB_NAME}")
add_dependencies(ExtLib ExtLibBuild)

# Add to include directories:
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/ext/cmake-superprj-lib-test")
