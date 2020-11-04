# 3rdParty CMake file

# SDL2
if(NOT _SHATTERED_WINRT)
    set(SDL_STATIC ON)
    set(SDL_SHARED OFF)

    add_subdirectory(SDL)
endif()

# BGFX
add_subdirectory(BGFX)
