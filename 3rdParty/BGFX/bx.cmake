cmake_minimum_required(VERSION "3.0")
project(bx)

add_definitions(-D__STDC_FORMAT_MACROS)

set(includes "bx/include" "bx/3rdparty")

file(GLOB sources "bx/include/**.h" "bx/include/**.inl" "bx/scripts/**.natvis")

add_library(bx ${sources} "bx/src/amalgamated.cpp")

set_property(TARGET bx PROPERTY CXX_STANDARD 14)

target_include_directories(bx PUBLIC ${includes})

BX_DEPS(bx)

if(_SHATTERED_MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()
