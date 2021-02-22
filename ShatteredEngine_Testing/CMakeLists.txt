project(ShatteredEngine_Testing)

if(_SHATTERED_WIN32 AND NOT _SHATTERED_WINRT)
    add_executable(ShatteredEngine_Testing WIN32 "WinAPI/main.cpp" "MainGame.h" "MainGame.cpp")
elseif(_SHATTERED_WINRT)
    add_executable(ShatteredEngine_Testing WIN32 "WinRT/WinRTmain.cpp" "WinRT/SDL_winrt_main_NonXAML.cpp" "MainGame.h" "MainGame.cpp")
else()
    add_executable(ShatteredEngine_Testing "Default/main.cpp" "MainGame.h" "MainGame.cpp")
endif()

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Testing PROPERTY CXX_STANDARD 17)

target_include_directories(ShatteredEngine_Testing PRIVATE "../ShatteredEngine" PRIVATE "../3rdParty/termcolor/include" PRIVATE "../3rdParty/SDL/include" PRIVATE "../3rdParty/bgfx.cmake/bx/include" PRIVATE "../3rdParty/bgfx.cmake/bimg/include" PRIVATE "../3rdParty/bgfx.cmake/bgfx/include")

SEARCH_LIBS(ShatteredEngine_Testing)

if((_SHATTERED_MSVC OR _SHATTERED_MINGW) AND NOT _SHATTERED_WINRT)
    target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2-static" "SDL2main")
endif()
if(_SHATTERED_WINRT)
    target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2")
    if(_SHATTERED_DEBUG)
        target_link_libraries(ShatteredEngine_Testing "vccorlibd" "msvcrtd")
    else()
    target_link_libraries(ShatteredEngine_Testing "vccorlib" "msvcrt")
    endif()

    # Set "SDL_winrt_main_NonXAML.cpp" with /ZW compilation flag.
    set_source_files_properties("WinRT/SDL_winrt_main_NonXAML.cpp" PROPERTIES COMPILE_FLAGS "/ZW")
endif()
if(_SHATTERED_APPLE)
    target_link_libraries(ShatteredEngine_Testing "ShatteredEngine" "SDL2-static" "SDL2main")
endif()
if(_SHATTERED_UNIX)
    target_link_libraries(ShatteredEngine_Testing PRIVATE "ShatteredEngine" PRIVATE "SDL2-static" PRIVATE "SDL2main")
endif()

COPY_DLLS(ShatteredEngine_Testing)