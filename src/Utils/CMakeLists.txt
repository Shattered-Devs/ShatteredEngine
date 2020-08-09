cmake_minimum_required(VERSION "3.0")
set(CXX_STANDARD 17)

project(ShatteredEngine_Utils)

set(headers "../../3rdParty/termcolor/include")

file(GLOB sources "*.h" "*.cpp")

add_library(ShatteredEngine_Utils STATIC ${sources})
target_include_directories(ShatteredEngine_Utils PRIVATE ${headers})