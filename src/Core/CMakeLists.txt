cmake_minimum_required(VERSION "3.0")
set(CXX_STANDARD 17)

# Find Vulkan
find_package(Vulkan)

# Headers
set(headers "../../3rdParty/SDL/include"
            "../../3rdParty/Vulkan-Headers"
            "../../3rdParty/termcolor/include")
# Sources code
file(GLOB sources "*.h" "*.cpp")

project(ShatteredEngine_Core)

add_library(ShatteredEngine_Core STATIC "Initialize.h" "Initialize.cpp")

target_include_directories(ShatteredEngine_Core PRIVATE ${headers})
target_link_libraries(ShatteredEngine_Core "SDL2" "SDL2main" ${Vulkan_LIBRARY})