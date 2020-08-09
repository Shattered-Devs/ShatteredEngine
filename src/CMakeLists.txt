# Modules Directories
# Core
add_subdirectory(Core)

set(CXX_STANDARD 17)

add_executable(ShatteredEngine main.cpp)

target_link_libraries(ShatteredEngine "ShatteredEngine_Core")