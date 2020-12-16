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

#include "Window.h"

namespace ShatteredEngine::Core {
    Window::Window(std::string pWindowName)
	{
    	this->_window = SDL_CreateWindow(pWindowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
    }

    Window::~Window() {
        SDL_DestroyWindow(_window);
    }

    std::string Window::get_window_name() {
        return SDL_GetWindowTitle(_window);
    }

    void Window::set_window_name(std::string pName) {
        SDL_SetWindowTitle(_window, pName.c_str());
    }

    std::unique_ptr<ShatteredEngine::Geometry::Rectangle> Window::get_window_rectangle() {
        return std::make_unique<ShatteredEngine::Geometry::Rectangle>(*_x, *_y, *_width, *_height);
    }

    void Window::set_window_rectangle(std::unique_ptr<ShatteredEngine::Geometry::Rectangle> pRectangle) {
        SDL_SetWindowPosition(_window, pRectangle->Position->X, pRectangle->Position->Y);
        SDL_SetWindowSize(_window, pRectangle->Size->X, pRectangle->Size->Y);
    }

    SDL_SysWMinfo Window::get_window_context() {
        SDL_VERSION(&_windowHandle.version);
        SDL_GetWindowWMInfo(_window, &_windowHandle);
        return this->_windowHandle;
    }

    SDL_Window* Window::get_window() {
        return this->_window;
    }
}