cmake_minimum_required(VERSION "3.0")
set(CXX_STANDARD 17)

# Headers
set(headers "../../3rdParty/SDL/include")
# Sources code
file(GLOB sources "*.h" "*.cpp")

project(ShatteredEngine_Core)

add_library(ShatteredEngine_Core STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Core PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine_Core PRIVATE ${headers})
target_link_libraries(ShatteredEngine_Core "SDL2" "SDL2main" "ShatteredEngine_Utils")