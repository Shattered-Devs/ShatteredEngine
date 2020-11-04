project(ShatteredEngine)

file(GLOB_RECURSE sources "*.cpp" "*.h")

add_library(ShatteredEngine STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine PUBLIC "../3rdParty/SDL/include" PUBLIC "../3rdParty/termcolor/include" PUBLIC "../3rdParty/BGFX/bx/include" PUBLIC "../3rdParty/BGFX/bgfx/include")

target_link_libraries(ShatteredEngine PUBLIC "bgfx" PUBLIC "SDL2-static")
