#ifndef CORE_INITIALIZE_H
#define CORE_INITIALIZE_H

#include <iostream>
#include <clocale>
#include "../Utils/Logs.h"
#include <SDL.h>
#include <SDL_syswm.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

namespace ShatteredEngine_Core
{
    class Initialize
    {
        private:
        void Init_SDL2();
        static void Init_BGFX(SDL_SysWMinfo pWindowInfo);

        static void Destroy_BGFX();
        void Destroy_SDL2();
        
        public:
        SDL_Window *window = nullptr;
        SDL_SysWMinfo windowInfo;
        SDL_Event event;

        Initialize();
        ~Initialize();
    };    
}

#endif //CORE_INITIALIZE_H
