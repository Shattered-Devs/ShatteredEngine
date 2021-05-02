project(ShatteredEngine_Testing)

add_executable(ShatteredEngine_Testing "src/main.cpp" "src/MainGame.cpp")

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Testing PROPERTY CXX_STANDARD 17)

if(_SHATTERED_WINRT)
    if(_SHATTERED_DEBUG)
        target_link_libraries(ShatteredEngine_Testing "vccorlibd" "msvcrtd")
    else()
        target_link_libraries(ShatteredEngine_Testing "vccorlib" "msvcrt")
    endif()
endif()

target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2main")

target_include_directories(ShatteredEngine_Testing PRIVATE "../ShatteredEngine/" PRIVATE "../include/" PRIVATE "./")

if(_SHATTERED_WINDOWS)
    set(libraries "SDL2" "bgfx-shared-libRelease")
    if(_SHATTERED_X86)
        target_link_directories(ShatteredEngine_Testing PRIVATE "../libs/Windows/x86/")
        foreach(lib IN LISTS libraries)
            file(COPY "../libs/Windows/x86/${lib}.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
        endforeach()
    elseif(_SHATTERED_X64)
        target_link_directories(ShatteredEngine_Testing PRIVATE "../libs/Windows/x64/")
        foreach(lib IN LISTS libraries)
            file(COPY "../libs/Windows/x64/${lib}.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
        endforeach()
    endif()

    target_link_libraries(ShatteredEngine_Testing SDL2main SDL2 bgfx-shared-libRelease)
endif()