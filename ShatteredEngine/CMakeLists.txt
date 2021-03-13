project(ShatteredEngine)

file(GLOB_RECURSE sources "*.cpp" "*.h")

add_library(ShatteredEngine STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine PRIVATE "../3rdParty/SDL/include" PRIVATE "../3rdParty/BGFX/bx/include" PRIVATE "../3rdParty/BGFX/bimg/include" PRIVATE "../3rdParty/BGFX/bgfx/include" PRIVATE "../3rdParty/BGFX/bgfx/3rdparty/dear-imgui")

target_link_libraries(ShatteredEngine "SDL2-static" "bx" "bimg" "bgfx" "dear-imgui")