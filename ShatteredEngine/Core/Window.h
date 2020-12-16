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

#ifndef SHATTERED_ENGINE_CORE_WINDOW_H
#define SHATTERED_ENGINE_CORE_WINDOW_H

#include <string>
#include <memory>
#include <SDL/SDL.h>
#include <SDL/SDL_syswm.h>
#include "../Geometry/Rectangle.h"

namespace ShatteredEngine::Core {
    class Window {
    private:
        SDL_Window *_window;
        SDL_SysWMinfo _windowHandle;

        int *_x;
        int *_y;
        int *_width;
        int *_height;

        std::string _windowName;


    public:
        Window(std::string pWindowName);

        ~Window();

        std::string get_window_name();
        void set_window_name(std::string pName);

        std::unique_ptr<ShatteredEngine::Geometry::Rectangle> get_window_rectangle();
        void set_window_rectangle(std::unique_ptr<ShatteredEngine::Geometry::Rectangle> pRectangle);

        SDL_SysWMinfo get_window_context();

        SDL_Window* get_window();
    };
}


#endif //SHATTERED_ENGINE_CORE_WINDOW_H
