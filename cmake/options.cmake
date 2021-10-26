option(_SHATTERED_WIN32 "(MinGW or MSVC ONLY) Enable Win32 Project" OFF)
option(_SHATTERED_VULKAN "(Linux ONLY) Enable Vulkan Renderer" OFF)
option(_SHATTERED_WAYLAND "(Linux ONLY) Enable Wayland Backend." OFF)
option(_SHATTERED_BUNDLE "(macOS ONLY) Enable application Bundle." OFF)

# Enable Win32
if(_SHATTERED_WIN32)
    add_definitions(-D_SHATTERED_WIN32)
endif()

# Enable macOS Bundle
if(_SHATTERED_BUNDLE)
    add_definitions(-D_SHATTERED_BUNDLE)
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