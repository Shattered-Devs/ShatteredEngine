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

#include "Game.h"

const bgfx::ViewId viewID = 0;

namespace ShatteredEngine::Core {
    Game::Game(std::string pWindowName, bgfx::RendererType::Enum renderer) {
        std::setlocale(LC_ALL, ".UTF-8");
        SDL_Init(SDL_INIT_EVERYTHING);

        this->window = std::make_unique<Window>(pWindowName);

        bgfx::renderFrame(-1);

        bgfx::Init init;

        init.type = renderer;
#if _SHATTERED_WINRT
        init.platformData.nwh = window->get_window_context().info.winrt.window;
#elif _SHATTERED_WINDOWS
        init.platformData.nwh = window->get_window_context().info.win.window;
#endif
        init.resolution.width = 500;
        init.resolution.height = 500;
        init.resolution.reset = BGFX_RESET_VSYNC;

        bgfx::init(init);

        bgfx::setViewClear(viewID, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x6495EDFF, 1.0f, 0);
        bgfx::setViewRect(viewID, 0, 0, 500, 500);
    }

    Game::~Game() {
        SDL_Quit();
    }

    void Game::run()
    {
        this->initialize();
        while (true) {
            SDL_PollEvent(&this->event);

            if (this->event.type == SDL_QUIT) {
                break;
            }

            this->update();
            this->render();

            bgfx::touch(viewID);
            bgfx::frame(true);
        }
        this->shutdown();
    }

	void Game::initialize()
	{
	}

	void Game::update()
	{
	}

	void Game::render()
	{
	}

    void Game::shutdown()
    {
        bgfx::shutdown();
    }
}
