#
# Add internal library:
#
add_library(TestLib SHARED TestLib.cpp)
target_include_directories(TestLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_libraries(TestLib LINK_PUBLIC ExtLib)
target_link_libraries(TestLib LINK_PUBLIC "${CMAKE_BINARY_DIR}/${EXT_LIB_NAME}")


#
# Add executable:
#
add_executable(testApp testApp.cpp)
#target_link_libraries(testApp LINK_PUBLIC TestLib ExtLib)
target_link_libraries(testApp LINK_PUBLIC TestLib "${CMAKE_BINARY_DIR}/${EXT_LIB_NAME}")
