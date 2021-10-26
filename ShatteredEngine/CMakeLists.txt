project(ShatteredEngine)

file(GLOB_RECURSE sources "*.cpp")

add_library(ShatteredEngine STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine PRIVATE "../third-parties/SDL2/include/")

target_link_libraries(ShatteredEngine SDL2-static)