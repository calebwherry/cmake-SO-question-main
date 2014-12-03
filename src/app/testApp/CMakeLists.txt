# Add executable:
add_executable(testApp testApp.cpp)

# Link to TestLib:
target_link_libraries(testApp LINK_PUBLIC TestLib ExtLib)

# Install
install(TARGETS testApp DESTINATION bin)
