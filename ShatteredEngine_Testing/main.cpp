#include <SDL/SDL.h>
#include <memory>
#include "MainGame.h"
#include "Utils/Logs.h"

using namespace ShatteredEngine::Utils;

#if _SHATTERED_WINRT
#include <windows.h>

int fake_main(int argc, char** argv);
int real_main(int argc, char** argv);


int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SDL_main_func mainFunc = fake_main;

    SDL_WinRTRunApp(mainFunc, nullptr);

    return 0;
}

int fake_main(int argc, char** argv)
{
    real_main(argc, argv);

    return 0;
}

int real_main(int argc, char** argv)
#elif _SHATTERED_WIN32 || _SHATTERED_MINGW
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main(int argc, char** argv)
#endif
{
    Logs::WriteLog(Logs::LogType::INFO, L"Initialization of the Engine.");
    std::unique_ptr<MainGame> game = std::make_unique<MainGame>("Hello Shattered Engine NEXT !");
    game->run();

    return 0;
}