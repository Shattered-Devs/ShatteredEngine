project(ShatteredEngine_Testing)

add_executable(ShatteredEngine_Testing "src/main.cpp" "src/MainGame.h" "src/MainGame.cpp")

# Force C++ 17 Standard
set_property(TARGET ShatteredEngine_Testing PROPERTY CXX_STANDARD 17)

if(_SHATTERED_WINRT)
    if(_SHATTERED_DEBUG)
        target_link_libraries(ShatteredEngine_Testing "vccorlibd" "msvcrtd")
    else()
        target_link_libraries(ShatteredEngine_Testing "vccorlib" "msvcrt")
    endif()
endif()

target_link_libraries(ShatteredEngine_Testing "ShatteredEngine")

target_include_directories(ShatteredEngine_Testing PRIVATE "../ShatteredEngine")