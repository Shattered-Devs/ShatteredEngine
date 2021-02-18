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
#if (_M_IA64 || __ia64__ || _IA64 || __IA64__ || __amd64__ || __amd64 || __x86_64__ || __x86_64 || _M_AMD64)
int main(int argc, char **argv)
{
	return 0;
}
#endif
" _SHATTERED_X64)

if(_SHATTERED_X64)
	add_definitions(-D_SHATTERED_X64)
endif()