add_library(TestLib SHARED TestLib.cpp)
target_include_directories(TestLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add dependencies:
target_link_libraries(TestLib LINK_PUBLIC ExtLib)
