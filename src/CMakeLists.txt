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
endif()