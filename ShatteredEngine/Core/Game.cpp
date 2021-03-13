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

#include "Game.h"

namespace ShatteredEngine::Core {
    Game::Game(std::string p_WindowName) {
        std::setlocale(LC_ALL, ".UTF-8");

        SDL_Init(SDL_INIT_EVERYTHING);

        this->window = std::make_unique<Window>(p_WindowName, 500, 500);
    }

    Game::~Game() {
        SDL_Quit();
    }

    void Game::run()
    {
        this->initialize();

        // GAMELOOP
        while (true) {
            SDL_PollEvent(&this->events);
            last = now;
            now = SDL_GetPerformanceCounter();

            deltaTime = (double)((now - last)*1000 / (double)SDL_GetPerformanceFrequency());

            if(events.type == SDL_QUIT)
            {
                break;
            }

            this->update(deltaTime);
            this->render();
        }
        this->shutdown();
    }

	void Game::initialize()
	{
	}

	void Game::update(double p_DeltaTime)
	{
	}

	void Game::render()
	{
	}

    void Game::shutdown()
    {
    }
}
