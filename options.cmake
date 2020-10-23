option(_SHATTERED_WIN32 "(MinGW or MSVC ONLY) Enable Win32 Project" OFF)
option(_SHATTERED_WINRT "(MSVC ONLY) Enable UWP Project" OFF)
option(_SHATTERED_VULKAN "(Linux ONLY) Enable Vulkan Renderer" OFF)


# Enable UWP
if(_SHATTERED_WINRT)
    set(CMAKE_SYSTEM_NAME "WindowsStore")
    set(CMAKE_SYSTEM_VERSION "10.0")
    add_definitions(-DCMAKE_SYSTEM_NAME="WindowsStore" -DCMAKE_SYSTEM_VERSION="10.0")
    add_definitions(-D_SHATTERED_WINRT)
    add_compile_options("/ZW")
    
    if(_SHATTERED_DEBUG)
        add_compile_options("/defaultlib:'vccorlibd.lib' /defaultlib:'msvcrtd.lib'")
    elseif()
        add_compile_options("/defaultlib:'vccorlib.lib' /defaultlib:'msvcrt.lib'")
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