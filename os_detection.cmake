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

# Detect CPU Architecture
# Include Checking C Compiles module
include(CheckCSourceCompiles)

# Check x86 compilation
check_c_source_compiles("
#if (_M_IX86 || i386 || __i386 || __i386__)
int main(int argc, char **argv)
{
	return 0;
}
#endif
" _SHATTERED_X86)

if(_SHATTERED_X86)
	add_definitions(-D_SHATTERED_X86)
endif()

# Check x64 compilaiton
check_c_source_compiles("
#if (__amd64__ || __amd64 || __x86_64__ || __x86_64 || _M_AMD64)
int main(int argc, char **argv)
{
	return 0;
}
#endif
" _SHATTERED_X64)

if(_SHATTERED_X64)
	add_definitions(-D_SHATTERED_X64)
endif()

# Check ARM compilaiton
check_c_source_compiles("
#if (__arm__ || _M_ARM || __TARGET_ARCH_ARM)
int main(int argc, char **argv)
{
	return 0;
}
#endif
" _SHATTERED_ARM)

if(_SHATTERED_ARM)
	add_definitions(-D_SHATTERED_ARM)
endif()

# Check ARM64 compilaiton
check_c_source_compiles("
#if (__aarch64__)
int main(int argc, char **argv)
{
	return 0;
}
#endif
" _SHATTERED_ARM64)

if(_SHATTERED_ARM64)
	add_definitions(-D_SHATTERED_ARM64)
endif()

# Print a message with the compilation informations
if(_SHATTERED_X86)
	message("Building the Engine for x86 CPU ARCH.")
elseif(_SHATTERED_X64)
	message("Building the Engine for x64 CPU ARCH.")
elseif(_SHATTERED_ARM)
	message("Building the Engine for ARM CPU ARCH.")
elseif(_SHATTERED_ARM64)
	message("Building the Engine for ARM64 CPU ARCH.")
else()
	message("Building the Engine for UNKNOWN CPU ARCH.")
endif()

message("Building the Engine for ${CMAKE_SYSTEM_NAME}.")