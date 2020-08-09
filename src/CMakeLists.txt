# Modules Directories
# Core
add_subdirectory(Core)

# Utils
add_subdirectory(Utils)

set(CXX_STANDARD 17)

add_executable(ShatteredEngine main.cpp)

target_link_libraries(ShatteredEngine "ShatteredEngine_Core")
target_include_directories(ShatteredEngine PRIVATE "../3rdParty/termcolor/include")