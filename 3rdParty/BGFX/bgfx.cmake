cmake_minimum_required(VERSION "3.0")
project(bgfx)

add_definitions(-D__STDC_FORMAT_MACROS)

set(includes "bx/include" "bimg/include" "bgfx/include" "bgfx/3rdparty" "bgfx/3rdparty/dxsdk/include" "bgfx/3rdparty/khronos")

file(GLOB sources "bgfx/include/bgfx/**.h" "bgfx/src/*.cpp" "bgfx/src/*.h")
list(REMOVE_ITEM sources "bgfx/src/amalgamated.cpp")

if(MSVC)
	list(REMOVE_ITEM sources "bgfx/src/glcontext_glx.cpp" "bgfx/src/glcontext_egl.cpp")
elseif(APPLE AND NOT UNIX)
	list(APPEND sources "bgfx/src/*.mm")
endif()

add_library(bgfx ${sources})

set_property(TARGET bgfx PROPERTY CXX_STANDARD 14)

if(CMAKE_BUILD_TYPE EQUAL "Debug")
	add_definitions(-DBGFX_CONFIG_DEBUG=1)
endif()
	

if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	target_include_directories(bgfx PRIVATE "bx/include/compat/msvc" ${includes})
elseif(WIN32)
	target_include_directories(bgfx PRIVATE "bx/include/compat/mingw" ${includes})
elseif(APPLE AND NOT UNIX)
	target_include_directories(bgfx PRIVATE "bx/include/compat/osx" ${includes})
endif()