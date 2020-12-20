project(ShatteredEngine)

file(GLOB_RECURSE sources "*.cpp" "*.h")

add_library(ShatteredEngine STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine PUBLIC "../3rdParty/SDL/include" PUBLIC "../3rdParty/termcolor/include" PUBLIC "../3rdParty/bgfx.cmake/bx/include" PUBLIC "../3rdParty/bgfx.cmake/bimg/include" PUBLIC "../3rdParty/bgfx.cmake/bgfx/include")

SEARCH_LIBS(ShatteredEngine)

target_link_libraries(ShatteredEngine PUBLIC "SDL2" PUBLIC "bgfx" PUBLIC "bx" PUBLIC "bimg")
