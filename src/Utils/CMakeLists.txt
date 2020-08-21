cmake_minimum_required(VERSION "3.0")
project(ShatteredEngine_Utils)

file(GLOB sources "*.h" "*.cpp")

add_library(ShatteredEngine_Utils STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Utils PROPERTY CXX_STANDARD 17)