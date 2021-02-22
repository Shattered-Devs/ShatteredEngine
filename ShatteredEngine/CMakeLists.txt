project(ShatteredEngine)

file(GLOB_RECURSE sources "*.cpp" "*.h")

add_library(ShatteredEngine STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine PRIVATE "../3rdParty/SDL/include" PRIVATE "../3rdParty/termcolor/include" PRIVATE "../3rdParty/bgfx.cmake/bx/include" PRIVATE "../3rdParty/bgfx.cmake/bimg/include" PRIVATE "../3rdParty/bgfx.cmake/bgfx/include")

SEARCH_LIBS(ShatteredEngine)

target_link_libraries(ShatteredEngine PRIVATE "SDL2-static" PRIVATE "bx" PRIVATE "bimg" PRIVATE "bgfx")
