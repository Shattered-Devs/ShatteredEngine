# Dependencies
function(bx_deps target_name)
	if(_SHATTERED_MSVC)
		target_include_directories(${target_name} PRIVATE "bx/include/compat/msvc")
	endif()
	if(_SHATTERED_MINGW)
		target_include_directories(${target_name} PRIVATE "bx/include/compat/mingw")
	endif()
	if(_SHATTERED_APPLE)
		target_include_directories(${target_name} PRIVATE "bx/include/compat/osx")
	endif()
endfunction()

# BX
include("bx.cmake")
# BIMG
include("bimg.cmake")
# BGFX
include("bgfx.cmake")