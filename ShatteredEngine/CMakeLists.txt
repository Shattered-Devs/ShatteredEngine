project(ShatteredEngine)

file(GLOB_RECURSE sources "*.cpp" "*.h")

add_library(ShatteredEngine STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine PUBLIC "../include" PUBLIC "../3rdParty/termcolor/include")

SEARCH_LIBS(ShatteredEngine)

target_link_libraries(ShatteredEngine PUBLIC "SDL2" PUBLIC "bgfx-shared-libRelease")