#include "Initialize.h"

using namespace ShatteredEngine_Core;
using namespace ShatteredEngine_Utils;

// SDL_Window *window = nullptr;
// SDL_SysWMinfo *windowInfo = nullptr;
// SDL_Event event;

Initialize::Initialize()
{
    std::setlocale(LC_ALL, "en_US.UTF-8");
    std::locale::global(std::locale("en_US.UTF-8"));
    std::cout.imbue(std::locale());

    Logs::WriteLog(Logs::LogType::INFO, "Ceci est un message d'information. Test charactères: \"éè&à\".");
    Logs::WriteLog(Logs::LogType::WARN, "Ceci est un message d'alerte. Test charactères: \"éè&à\".");
    Logs::WriteLog(Logs::LogType::ERR, "Ceci est un message d'erreur. Test charactères: \"éè&à\".");
}
    
Initialize::~Initialize()
{
    std::cout << "Bye CORE !" << std::endl;
}

void Init_SDL2()
{
    // window = SDL_CreateWindow(window, "Hello ShatteredEngine !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
}