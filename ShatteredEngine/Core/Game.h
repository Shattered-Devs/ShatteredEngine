//
// Shattered Engine
//
// Copyright (c) 2021 John (Linuxydable) Benard
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

#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <clocale>
#include <iostream>
#include <locale.h>

#include <SDL/SDL.h>

#include "Window.h"


namespace ShatteredEngine::Core {
    class Game {
    private:
        Uint64 now = SDL_GetPerformanceCounter();
        Uint64 last = 0;
        
    public:
        double deltaTime = 0;

        std::unique_ptr<Window> window;

        SDL_Event events;

        Game(std::string p_WindowName);

        ~Game();

        void run();

        virtual void initialize();
        virtual void update(double p_DeltaTime);
        virtual void render();
        virtual void shutdown();
    };
}


#endif // GAME_H
