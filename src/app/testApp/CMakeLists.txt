# Add executable:
add_executable(testApp testApp.cpp)

# Link to TestLib:
target_link_libraries(testApp LINK_PUBLIC TestLib ExtLib)
