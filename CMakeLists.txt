# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(CorebelEngine)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Asset Path
set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)

# Include Directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/third_party
)

# Add Subdirectories for Libraries
add_subdirectory(third_party/bgfx)
add_subdirectory(third_party/SDL)
add_subdirectory(third_party/JoltPhysics)
add_subdirectory(third_party/glm)
add_subdirectory(third_party/zlib)
add_subdirectory(third_party/enet)
add_subdirectory(third_party/imgui)
add_subdirectory(third_party/assimp)

# Source Files
file(GLOB_RECURSE ENGINE_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.h
)

# Define the Executable
add_executable(CorebelEngine ${ENGINE_SOURCES})

# Link Libraries
target_link_libraries(CorebelEngine bgfx SDL JoltPhysics glm zlib imgui enet)

# Debugging and Release Configurations
set_target_properties(CorebelEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
)
