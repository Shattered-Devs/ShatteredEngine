# Modules Directories
# Core
add_subdirectory(Core)

# Utils
add_subdirectory(Utils)


add_executable(ShatteredEngine main.cpp)

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine PROPERTY CXX_STANDARD 17)

if(MSVC)
    target_link_libraries(ShatteredEngine "ShatteredEngine_Core" "ShatteredEngine_Utils" "SDL2" "SDL2main" "bx" "bimg" "bgfx" "gdi32" "kernel32" "psapi")
elseif(APPLE)
    set(macOS_Libraries "-framework QuartzCore" "-framework Metal" "-framework IOKit" "-framework CoreVideo" "-framework Foundation")
    target_link_libraries(ShatteredEngine "ShatteredEngine_Core" "ShatteredEngine_Utils" "SDL2" "SDL2main" "bx" "bimg" "bgfx" ${macOS_Libraries})
elseif(UNIX)
    target_link_libraries(ShatteredEngine PRIVATE "ShatteredEngine_Core" PRIVATE "ShatteredEngine_Utils" PUBLIC "SDL2-static" PUBLIC "SDL2main" PUBLIC "bx" PUBLIC "bimg" PUBLIC "bgfx" PUBLIC "X11" PUBLIC "GL" PUBLIC "dl" PUBLIC "rt" PUBLIC "pthread" PUBLIC "vulkan")
endif()
