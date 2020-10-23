# The main CMake file of ShatteredEngine
cmake_minimum_required(VERSION "3.0")
project(ShatteredEngine_Testing)

# Detect WinRT
if(CMAKE_SYSTEM_NAME MATCHES "WindowsStore")
	set(_SHATTERED_WINRT TRUE)
	add_definitions(-D_SHATTERED_WINRT)
	add_compile_options("/ZW")
endif()

# 3rdParty
add_subdirectory(3rdParty)

# Source Code
add_subdirectory(ShatteredEngine)

# Testing Project
add_subdirectory(ShatteredEngine_Testing)