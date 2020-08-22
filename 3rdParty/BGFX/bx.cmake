cmake_minimum_required(VERSION "3.0")
project(bx)

add_definitions(-D__STDC_FORMAT_MACROS)

set(includes "bx/include" "bx/3rdparty")

file(GLOB sources "bx/include/bx/*.h" "bx/include/bx/inline/*.inl" "bx/src/*.cpp")
get_filename_component(full_path_sources "bx/src" ABSOLUTE)
list(REMOVE_ITEM sources "${full_path_sources}/amalgamated.cpp" "${full_path_sources}/crtnone.cpp")

add_library(bx ${sources})

set_property(TARGET bx PROPERTY CXX_STANDARD 14)

target_include_directories(bx PRIVATE ${includes})

if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	target_include_directories(bx PRIVATE "bx/include/compat/msvc")
elseif(WIN32)
	target_include_directories(bx PRIVATE "bx/include/compat/mingw")
elseif(APPLE AND NOT UNIX)
	target_include_directories(bx PRIVATE "bx/include/compat/osx")
endif()