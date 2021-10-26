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

# Detect WinRT/UWP
if("${CMAKE_SYSTEM_NAME}" STREQUAL "WindowsStore")
	set(_SHATTERED_WINRT TRUE)
	add_definitions(-D_SHATTERED_WINRT)
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

message("Building the Engine for OS: ${CMAKE_SYSTEM_NAME}.")