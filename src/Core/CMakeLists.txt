cmake_minimum_required(VERSION "3.0")
project(ShatteredEngine_Core)
# Headers
set(headers "../../3rdParty/SDL/include")
# Sources code
file(GLOB sources "*.h" "*.cpp")

add_library(ShatteredEngine_Core STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Core PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine_Core PRIVATE ${headers})