# The main CMake file of ShatteredEngine
cmake_minimum_required(VERSION "3.0")

# Detect if Debug
if(CMAKE_BUILD_TYPE EQUAL "Debug")
	set(_SHATTERED_DEBUG TRUE)
	add_definitions(-D_SHATTERED_DEBUG)
endif()

# Options
include(options.cmake)

project(ShatteredEngine_Testing)

# OS Options
include(os_detection.cmake)


# 3rdParty
add_subdirectory(3rdParty)

# Source Code
add_subdirectory(ShatteredEngine)

# Testing Project
add_subdirectory(ShatteredEngine_Testing)