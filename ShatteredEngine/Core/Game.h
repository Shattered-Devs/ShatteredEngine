//
// Shattered Engine
//
// Copyright (c) 2020 John (Linuxydable) Benard
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.c
//

#ifndef SHATTERED_ENGINE_CORE_GAME_H
#define SHATTERED_ENGINE_CORE_GAME_H

#include <memory>
#include <string>
#include <clocale>
#include <iostream>
#include <locale.h>

#include <SDL/SDL_syswm.h>

#include <bgfx/c99/bgfx.h>

#include "Window.h"


namespace ShatteredEngine::Core {
    class Game {
    public:
        SDL_Event event;

        std::unique_ptr<Window> window;

        Game(std::string pWindowName);

        ~Game();

        void run();

        virtual void initialize();
        virtual void update();
        virtual void render();
        virtual void shutdown();
    };
}


#endif //SHATTERED_ENGINE_CORE_GAME_H
