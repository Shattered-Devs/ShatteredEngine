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

#include "Window.h"

namespace ShatteredEngine::Core {
    Window::Window(std::string p_WindowName, int p_Width, int p_Height)
	{
    	this->Window::Window(p_WindowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_Width, p_Height);
    }

    Window::Window(std::string p_WindowName, int p_X, int p_Y, int p_Width, int p_Height)
    {
        _window = SDL_CreateWindow(p_WindowName.c_str(), p_X, p_Y, p_Width, p_Height, SDL_WINDOW_RESIZABLE);
    }

    Window::~Window() {
        SDL_DestroyWindow(_window);
    }

    SDL_SysWMinfo Window::GetWindowHandle()
    {
        SDL_GetVersion(&this->_windowHandle.version);

        SDL_GetWindowWMInfo(this->_window, &this->_windowHandle);

        return _windowHandle;
    }
}