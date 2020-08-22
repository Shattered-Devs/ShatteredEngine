cmake_minimum_required(VERSION "3.0")
project(bx)

add_definitions(-D__STDC_FORMAT_MACROS)

set(includes "bx/include" "bx/3rdparty")

file(GLOB sources "bx/include/bx/*.h" "bx/include/bx/inline/*.inl" "bx/src/*.cpp")
list(REMOVE_ITEM sources "bx/src/amalgamated.cpp" "bx/src/crtnone.cpp")

add_library(bx ${sources})

set_property(TARGET bx PROPERTY CXX_STANDARD 14)

if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	target_include_directories(bx PRIVATE "bx/include/compat/msvc" PRIVATE ${includes})
elseif(WIN32)
	target_include_directories(bx PRIVATE "bx/include/compat/mingw" PRIVATE ${includes})
elseif(APPLE AND NOT UNIX)
	target_include_directories(bx PRIVATE "bx/include/compat/osx" PRIVATE ${includes})
endif()