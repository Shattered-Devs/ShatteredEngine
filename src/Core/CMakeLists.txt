cmake_minimum_required(VERSION "3.0")
project(ShatteredEngine_Core)

# Headers
set(headers "../../3rdParty/SDL/include" "../../3rdParty/BGFX/bx/include" "../../3rdParty/BGFX/bgfx/include")
# Sources code
file(GLOB sources "*.h" "*.cpp")

add_library(ShatteredEngine_Core STATIC ${sources})

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Core PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine_Core PUBLIC ${headers})

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    target_include_directories(ShatteredEngine_Core PRIVATE "../../3rdParty/BGFX/bx/include/compat/msvc")
elseif(WIN32)
    target_include_directories(ShatteredEngine_Core PRIVATE "../../3rdParty/BGFX/bx/include/compat/mingw")
elseif(APPLE AND NOT UNIX)
    target_include_directories(ShatteredEngine_Core PRIVATE "../../3rdParty/BGFX/bx/include/compat/osx")
endif()