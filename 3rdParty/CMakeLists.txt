# 3rdParty CMake file

# SDL2
if(NOT _SHATTERED_WINRT)
    # set(SDL_SHARED OFF)
    set(SDL_STATIC ON)
    add_subdirectory("SDL")
endif()

# BGFX
add_subdirectory("bgfx.cmake")