# Modules Directories
# Core
add_subdirectory(Core)

# Utils
add_subdirectory(Utils)


add_executable(ShatteredEngine main.cpp)

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine PROPERTY CXX_STANDARD 17)

target_link_libraries(ShatteredEngine "ShatteredEngine_Core" "ShatteredEngine_Utils" "SDL2" "SDL2main")