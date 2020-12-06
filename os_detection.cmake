# Detect MSVC
if(MSVC)
	set(_SHATTERED_WINDOWS TRUE)
	set(_SHATTERED_MSVC TRUE)
	add_definitions(-D_SHATTERED_WINDOWS)
	add_definitions(-D_SHATTERED_MSVC)
endif()

# Detect MinGW
if(MINGW)
	set(_SHATTERED_WINDOWS TRUE)
	set(_SHATTERED_MINGW TRUE)
	add_definitions(-D_SHATTERED_WINDOWS)
	add_definitions(-D_SHATTERED_MINGW)
endif()

# Detect Apple
if(APPLE)
	set(_SHATTERED_APPLE TRUE)
	add_definitions(-D_SHATTERED_APPLE)
endif()

# Detect Unix
if(UNIX AND NOT APPLE)
	set(_SHATTERED_UNIX TRUE)
	add_definitions(-D_SHATTERED_UNIX)
endif()

if(_SHATTERED_WINDOWS)
	# Detect 32 or 64 Bits
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		# 64 bits
		set(_SHATTERED_WINDOWS_X64 TRUE)
		add_definitions(-D_SHATTERED_WINDOWS_X64)
	elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
		# 32 bits
		set(_SHATTERED_WINDOWS_X86 TRUE)
		add_definitions(-D_SHATTERED_WINDOWS_X86)
	endif()
endif()