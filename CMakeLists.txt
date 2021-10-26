# The main CMake file of ShatteredEngine
cmake_minimum_required(VERSION "3.0")

# Options
include("cmake/options.cmake")

# Project name
project(ShatteredEngine_Testing)

# Third Parties
add_subdirectory(third-parties)

# Check if a build type is set
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    message(WARNING "No build type set, setted the build type to Debug !")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# OS Options
include("cmake/os_detection.cmake")

# Source Code
add_subdirectory(ShatteredEngine)

# Testing Project
add_subdirectory(ShatteredEngine_Testing)
