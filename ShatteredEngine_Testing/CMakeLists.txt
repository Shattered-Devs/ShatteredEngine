project(ShatteredEngine_Testing)

### Specify executable for for each systems
if(_SHATTERED_WIN32)
    add_executable(ShatteredEngine_Testing WIN32 "src/main.cpp" "src/MainGame.cpp")
elseif(_SHATTERED_BUNDLE)
    add_executable(ShatteredEngine_Testing MACOSX_BUNDLE "src/main.cpp" "src/MainGame.cpp")
else()
    add_executable(ShatteredEngine_Testing "src/main.cpp" "src/MainGame.cpp")
endif()

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Testing PROPERTY CXX_STANDARD 17)

# Select Debug or Release runtime for UWP
if(_SHATTERED_WINRT)
    if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        target_link_libraries(ShatteredEngine_Testing "vccorlibd" "msvcrtd")
    else()
        target_link_libraries(ShatteredEngine_Testing "vccorlib" "msvcrt")
    endif()
endif()

target_include_directories(ShatteredEngine_Testing PRIVATE "../ShatteredEngine/" PRIVATE "../third-parties/SDL2/include/")

### UWP Dependancies resolution
if(_SHATTERED_WINRT)
    target_link_libraries(ShatteredEngine_Testing ShatteredEngine)
### Windows Dependancies resolution
elseif(_SHATTERED_WINDOWS)
    target_link_libraries(ShatteredEngine_Testing SDL2main ShatteredEngine)
endif()
