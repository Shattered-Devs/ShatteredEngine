cmake_minimum_required(VERSION "3.0")
project(bgfx)

add_definitions(-D__STDC_FORMAT_MACROS)

set(includes "bx/include" "bimg/include" "bgfx/include" "bgfx/3rdparty" "bgfx/3rdparty/dxsdk/include" "bgfx/3rdparty/khronos")

file(GLOB sources "bgfx/include/bgfx/*.h" "bgfx/src/*.cpp" "bgfx/src/*.h" "bgfx/scripts/*.natvis")
get_filename_component(full_path_sources "bgfx/src" ABSOLUTE)
list(REMOVE_ITEM sources "${full_path_sources}/amalgamated.cpp" "${full_path_sources}/amalgamated.mm")

if(_SHATTERED_MSVC OR _SHATTERED_MINGW)
	list(REMOVE_ITEM sources "${full_path_sources}/glcontext_glx.cpp" "${full_path_sources}/glcontext_egl.cpp")
endif()	
if(_SHATTERED_APPLE)
	list(APPEND sources "${full_path_sources}/glcontext_eagl.mm" "${full_path_sources}/glcontext_nsgl.mm" "${full_path_sources}/renderer_mtl.mm")
endif()

add_library(bgfx ${sources})

set_property(TARGET bgfx PROPERTY CXX_STANDARD 14)

if(_SHATTERED_DEBUG)
	add_definitions(-DBGFX_CONFIG_DEBUG=1)
endif()

target_include_directories(bgfx PUBLIC ${includes})

if(_SHATTERED_MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	target_include_directories(bgfx PRIVATE "bx/include/compat/msvc")
endif()

if(_SHATTERED_MINGW)
	target_include_directories(bgfx PRIVATE "bx/include/compat/mingw")
endif()

if(_SHATTERED_APPLE)
	find_library(COCOA_LIBRARY Cocoa)
	find_library(METAL_LIBRARY Metal)
	find_library(QUARTZCORE_LIBRARY QuartzCore)
	mark_as_advanced(COCOA_LIBRARY)
	mark_as_advanced(METAL_LIBRARY)
	mark_as_advanced(QUARTZCORE_LIBRARY)
	target_link_libraries(bgfx PUBLIC ${COCOA_LIBRARY} PUBLIC ${METAL_LIBRARY} PUBLIC ${QUARTZCORE_LIBRARY})

	target_include_directories(bgfx PRIVATE "bx/include/compat/osx")
endif()

target_link_libraries(bgfx PUBLIC "bx" PUBLIC "bimg")

# Force Vulkan renderer to Objective C on XCode IDE
if(XCODE)
	set_source_files_properties(${full_path_sources}/renderer_vk.cpp PROPERTIES LANGUAGE OBJCXX XCODE_EXPLICIT_FILE_TYPE sourcecode.cpp.objcpp)
endif()
