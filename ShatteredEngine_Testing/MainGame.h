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

#ifndef SHATTEREDENGINE_TESTING_MAINGAME_H
#define SHATTEREDENGINE_TESTING_MAINGAME_H

#include <Core/Game.h>
#include <Utils/Logs.h>

class MainGame : public ShatteredEngine::Core::Game {
public:
    MainGame(std::string pWindowName, bgfx_renderer_type renderer);
    ~MainGame();

    void initialize() override;
    void update() override;
    void render() override;
	void shutdown() override;
};


#endif //SHATTEREDENGINE_TESTING_MAINGAME_H
