project(ShatteredEngine_Testing)

if(_SHATTERED_WINRT)
    add_executable(ShatteredEngine_Testing WIN32 main.cpp "../libs/UWP/x64/SDL2.dll")
else()
    add_executable(ShatteredEngine_Testing main.cpp)
endif()

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Testing PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine_Testing PUBLIC "../ShatteredEngine/")

if(MSVC)
    if(_SHATTERED_WINRT)
        # SDL2 Includes for WinRT App
        target_include_directories(ShatteredEngine_Testing PUBLIC "../3rdParty/SDL/include")
        target_link_directories(ShatteredEngine_Testing PUBLIC "../libs/UWP/x64")
        target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2" "bx" "bimg" "bgfx" "gdi32" "kernel32" "psapi")
    else()
        target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2-static" "SDL2main" "bx" "bimg" "bgfx" "gdi32" "kernel32" "psapi")
    endif()
elseif(APPLE)
    set(macOS_Libraries "-framework QuartzCore" "-framework Metal" "-framework IOKit" "-framework CoreVideo" "-framework Foundation")
    target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2" "SDL2main" "bx" "bimg" "bgfx" ${macOS_Libraries})
elseif(UNIX)
    target_link_libraries(ShatteredEngine_Testing PUBLIC "ShatteredEngine" PUBLIC "SDL2-static" PUBLIC "SDL2main" PUBLIC "bx" PUBLIC "bimg" PUBLIC "bgfx" PUBLIC "X11" PUBLIC "GL" PUBLIC "dl" PUBLIC "rt" PUBLIC "pthread" PUBLIC "vulkan")
endif()
