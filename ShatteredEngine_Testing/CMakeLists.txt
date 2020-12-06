project(ShatteredEngine_Testing)

if(_SHATTERED_WIN32 OR _SHATTERED_WINRT)
    add_executable(ShatteredEngine_Testing WIN32 main.cpp)
else()
    add_executable(ShatteredEngine_Testing main.cpp)
endif()

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Testing PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine_Testing PUBLIC "../ShatteredEngine" PUBLIC "../3rdParty/termcolor/include" PUBLIC "../include")

SEARCH_LIBS(ShatteredEngine_Testing)

if((_SHATTERED_MSVC OR _SHATTERED_MINGW) AND NOT _SHATTERED_WINRT)
    target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2" "SDL2main" "gdi32" "kernel32" "psapi")
endif()
if(_SHATTERED_WINRT)
    target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2" "gdi32" "kernel32" "psapi")
endif()
if(_SHATTERED_APPLE)
    target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2" "SDL2main")
endif()
if(_SHATTERED_UNIX)
    target_link_libraries(ShatteredEngine_Testing PUBLIC "ShatteredEngine" PUBLIC "SDL2" PUBLIC "SDL2main" PUBLIC "GL" PUBLIC "dl" PUBLIC "rt" PUBLIC "pthread")
    if(_SHATTERED_VULKAN)
        target_link_libraries(ShatteredEngine_Testing PUBLIC "vulkan")
    endif()
    if(_SHATTERED_WAYLAND)
        target_link_libraries(ShatteredEngine_Testing PUBLIC "wayland")
    else()
        target_link_libraries(ShatteredEngine_Testing PUBLIC "X11")
    endif()
endif()

COPY_DLLS(ShatteredEngine_Testing)