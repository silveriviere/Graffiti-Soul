cmake_minimum_required(VERSION 3.15)
project(GraffitiSoul VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Source files
set(SOURCES
    src/main.cpp
)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

# Create executable
add_executable(graffiti-soul ${SOURCES})

# Compiler warnings
if(MSVC)
    target_compile_options(graffiti-soul PRIVATE /W4)
else()
    target_compile_options(graffiti-soul PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Add subsystem libraries as you decompile them
# add_subdirectory(src/engine)
# add_subdirectory(src/graphics)
# add_subdirectory(src/physics)
# add_subdirectory(src/game)
