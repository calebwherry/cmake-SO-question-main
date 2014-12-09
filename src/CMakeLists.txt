#
# Solution: 
#   I was incorrectly compiling the external project. I did not set 
#   the '-soname' CLI option for g++ right (causing DT_SONAME to not be set) 
#   so the path to the SO was getting used instead of just the library name.
#   Check the StackOverflow link in the README for my write up the solution.
#   The commented out target_link_library work regardless of doing the correct
#   SO name but is a suboptimal solution, IMO.
#


#
# Add internal library:
#
add_library(TestLib SHARED TestLib.cpp)
target_include_directories(TestLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(TestLib LINK_PUBLIC ExtLib)
#target_link_libraries(TestLib LINK_PUBLIC "${CMAKE_BINARY_DIR}/${EXT_LIB_NAME}")


#
# Add executable:
#
add_executable(testApp testApp.cpp)
target_link_libraries(testApp LINK_PUBLIC TestLib ExtLib)
#target_link_libraries(testApp LINK_PUBLIC TestLib "${CMAKE_BINARY_DIR}/${EXT_LIB_NAME}")
