option(_SHATTERED_DEBUG "Activate Debug Build" ON)
option(_SHATTERED_WIN32 "(MinGW or MSVC ONLY) Enable Win32 Project" OFF)
option(_SHATTERED_WINRT "(MSVC ONLY) Enable UWP Project" OFF)
option(_SHATTERED_VULKAN "(Linux ONLY) Enable Vulkan Renderer" OFF)
option(_SHATTERED_WAYLAND "(Linux ONLY) Enable Wayland Backend." OFF)


# Enable DEBUG
if(_SHATTERED_DEBUG)
    set(CMAKE_BUILD_TYPE "Debug")
    add_definitions(-D_SHATTERED_DEBUG)
else()
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Enable UWP
if(_SHATTERED_WINRT)
    set(CMAKE_SYSTEM_NAME "WindowsStore")
    set(CMAKE_SYSTEM_VERSION "10.0")
    add_definitions(-DCMAKE_SYSTEM_NAME="WindowsStore" -DCMAKE_SYSTEM_VERSION="10.0")
    add_definitions(-D_SHATTERED_WINRT)
    
    if(_SHATTERED_DEBUG)
        add_compile_options("/nodefaultlib:vccorlibd /nodefaultlib:msvcrtd")
    elseif()
        add_compile_options("/nodefaultlib:vccorlib /nodefaultlib:msvcrt")
    endif()
endif()

# Enable Win32
if(_SHATTERED_WIN32)
    add_definitions(-D_SHATTERED_WIN32)
endif()

# Enable Vulkan Renderer
if(_SHATTERED_VULKAN)
    add_definitions(-D_SHATTERED_VULKAN)
endif()

if(UNIX AND NOT APPLE)
    # Enable Wayland Backend
    if(_SHATTERED_WAYLAND)
        add_definitions(-D_SHATTERED_WAYLAND)
    else()
        set(_SHATTERED_X11 TRUE)
        add_definitions(-D_SHATTERED_X11)
    endif()
endif()