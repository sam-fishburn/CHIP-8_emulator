cmake_minimum_required(VERSION 3.16)
project(main)

# Set the output directory for built objects.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

# Create your game executable target as usual
add_executable(main WIN32 main.c memory.c fetch.c stack.c decode.c memory.h fetch.h registers.h stack.h decode.h)

# Link to SDL3 manually if SDL3::SDL3 is not set automatically
target_link_libraries(main PRIVATE SDL3::SDL3)
