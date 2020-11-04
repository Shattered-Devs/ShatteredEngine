cmake_minimum_required(VERSION "3.0")
project(bgfx)

add_definitions(-D__STDC_FORMAT_MACROS)

set(includes "bx/include" "bimg/include" "bgfx/include" "bgfx/3rdparty" "bgfx/3rdparty/khronos")

file(GLOB sources "bgfx/include/**.h" "bgfx/src/**.h" "bgfx/scripts/**.natvis")

if(_SHATTERED_APPLE)
	add_library(bgfx ${sources} "bgfx/src/amalgamated.mm")
else()
	add_library(bgfx ${sources} "bgfx/src/amalgamated.cpp")
endif()

set_property(TARGET bgfx PROPERTY CXX_STANDARD 14)

if(_SHATTERED_DEBUG)
	add_definitions(-DBGFX_CONFIG_DEBUG=1)
endif()

target_include_directories(bgfx PUBLIC ${includes})

if(_SHATTERED_MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	target_include_directories(bgfx PUBLIC "bgfx/3rdparty/dxsdk/include")
	target_include_directories(bgfx PRIVATE "bx/include/compat/msvc")
endif()

if(_SHATTERED_MINGW)
	target_include_directories(bgfx PRIVATE "bx/include/compat/mingw")
endif()

if(_SHATTERED_APPLE)
	find_library(COCOA_LIBRARY Cocoa)
	find_library(QUARTZCORE_LIBRARY QuartzCore)
	find_library(OPENGL_LIBRARY OpenGL)
	find_library(METAL_LIBRARY Metal)
	find_library(METALKIT_LIBRARY MetalKit)

	mark_as_advanced(COCOA_LIBRARY)
	mark_as_advanced(QUARTZCORE_LIBRARY)
	mark_as_advanced(OPENGL_LIBRARY)
	mark_as_advanced(METAL_LIBRARY)
	mark_as_advanced(METALKIT_LIBRARY)
	target_link_libraries(bgfx PUBLIC ${METALKIT_LIBRARY} PUBLIC ${OPENGL_LIBRARY} PUBLIC ${COCOA_LIBRARY} PUBLIC ${METAL_LIBRARY} PUBLIC ${QUARTZCORE_LIBRARY})

	target_include_directories(bgfx PRIVATE "bx/include/compat/osx")
endif()

target_link_libraries(bgfx PUBLIC "bx" PUBLIC "bimg")
