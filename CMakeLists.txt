# The main CMake file of ShatteredEngine
cmake_minimum_required(VERSION "3.0")

# Options
include(options.cmake)

project(ShatteredEngine_Testing)

# OS Options
include(os_detection.cmake)


# Source Code
add_subdirectory(ShatteredEngine)

# Testing Project
add_subdirectory(ShatteredEngine_Testing)