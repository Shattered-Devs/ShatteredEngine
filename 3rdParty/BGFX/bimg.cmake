cmake_minimum_required(VERSION "3.0")
project(bimg)

set(includes "bx/include" "bimg/include" "bimg/3rdparty/astc-codec" "bimg/3rdparty/astc-codec/include")

file(GLOB sources "bimg/include/bimg/*.h" "bimg/src/image.cpp" "bimg/src/image_gnf.cpp" "bimg/src/*.h" "bimg/3rdparty/astc-codec/src/decoder/*.cc")

add_library(bimg ${sources})

set_property(TARGET bimg PROPERTY CXX_STANDARD 14)

target_include_directories(bimg PUBLIC ${includes})

BX_DEPS(bimg)

target_link_libraries(bimg PUBLIC "bx")
