#include "Initialize.h"

using namespace ShatteredEngine_Core;
using namespace ShatteredEngine_Utils;

SDL_Window *window = nullptr;
SDL_SysWMinfo windowInfo;
SDL_Event event;

Initialize::Initialize()
{
    std::setlocale(LC_ALL, "en_US.UTF-8");
    std::locale::global(std::locale("en_US.UTF-8"));
    std::cout.imbue(std::locale());

    Init_SDL2();
    
    // TEMP !!!
    while (true)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT)
        {
            Logs::WriteLog(Logs::LogType::INFO, "Closing the SDL Window !");
            break;
        }
    }
}
    
Initialize::~Initialize()
{
    Destroy_SDL2();
    std::cout << "Bye CORE !" << std::endl;
}

void Initialize::Init_SDL2()
{
    Logs::WriteLog(Logs::LogType::INFO, "Initializing the Engine...");
    
    Logs::WriteLog(Logs::LogType::INFO, "Initializing SDL2...");
    SDL_Init(SDL_INIT_EVERYTHING);
    
    Logs::WriteLog(Logs::LogType::INFO, "Creating SDL Window...");
    window = SDL_CreateWindow("Hello ShatteredEngine !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
    
    if (window == nullptr)
    {
        Logs::WriteLog(Logs::LogType::ERR, "Impossible to create the SDL Window !");
        return;
    }
    Logs::WriteLog(Logs::LogType::INFO, "SDL Window has been created !");
    
    Logs::WriteLog(Logs::LogType::INFO, "Getting SDL2 Version...");
    SDL_GetVersion(&windowInfo.version);
    
    Logs::WriteLog(Logs::LogType::INFO, "Getting SDL Window informations...");
    if (SDL_GetWindowWMInfo(window, &windowInfo) != SDL_TRUE)
    {
        Logs::WriteLog(Logs::LogType::ERR, "Impossible to get SDL Window informations !");
        return;
    }
    Logs::WriteLog(Logs::LogType::INFO, "SDL Window informations was successfully get !");
}

void Initialize::Destroy_SDL2()
{
    Logs::WriteLog(Logs::LogType::INFO, "Destroy SDL Window...");
    SDL_DestroyWindow(window);
    window = nullptr;
    
    Logs::WriteLog(Logs::LogType::INFO, "Exiting SDL2...");
    SDL_Quit();
}
