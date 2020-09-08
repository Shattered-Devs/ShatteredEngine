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
    Init_BGFX(windowInfo);

    switch (bgfx::getRendererType()) {
        case bgfx::RendererType::Noop:
            Logs::WriteLog(Logs::LogType::ERR, "NO GRAPHICAL RENDERER INITIALIZED !!!");
            break;
        case bgfx::RendererType::Direct3D9:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: DirectX9");
            break;
        case bgfx::RendererType::Direct3D11:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: DirectX11");
            break;
        case bgfx::RendererType::Direct3D12:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: DirectX12");
            break;
        case bgfx::RendererType::Metal:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: Metal");
            break;
        case bgfx::RendererType::OpenGL:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: OpenGL");
            break;
        case bgfx::RendererType::OpenGLES:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: OpenGLES");
            break;
        case bgfx::RendererType::Vulkan:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: Vulkan");
            break;
        case bgfx::RendererType::Gnm:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: PlayStation Graphical Render");
            break;
        case bgfx::RendererType::Nvn:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: Nintendo Switch Graphical Render");
            break;
        case bgfx::RendererType::WebGPU:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: WebGPU");
            break;
        case bgfx::RendererType::Count:
            Logs::WriteLog(Logs::LogType::WARN, "DEBUG -> Graphical Renderer initialized with the Renderer: Default");
            break;
    }

    const bgfx::ViewId _clearView = 0;
    bgfx::setViewClear(_clearView, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x6495EDFF, 1.0f, 0);
    bgfx::setViewRect(_clearView, 10, 10, 100, 100);
    
    // TEMP !!!
    while (true)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT)
        {
            Logs::WriteLog(Logs::LogType::INFO, "Closing the SDL Window !");
            break;
        }
        bgfx::touch(_clearView);

        bgfx::frame(false);
    }
}
    
Initialize::~Initialize()
{
    Destroy_BGFX();
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
    if (!SDL_GetWindowWMInfo(window, &windowInfo))
    {
        Logs::WriteLog(Logs::LogType::ERR, "Impossible to get SDL Window informations !");
        return;
    }
    Logs::WriteLog(Logs::LogType::INFO, "SDL Window informations was successfully get !");
}

void Initialize::Init_BGFX(SDL_SysWMinfo pWindowInfo) {
    bgfx::renderFrame();

    bgfx::PlatformData _platformData;
    _platformData.nwh = reinterpret_cast<unsigned int *>(pWindowInfo.info.x11.window);
    _platformData.ndt = pWindowInfo.info.x11.display;
    bgfx::setPlatformData(_platformData);

    bgfx::Init _init;
    _init.deviceId = BGFX_PCI_ID_NONE;
    _init.type = bgfx::RendererType::Vulkan;
    _init.resolution.width = 500;
    _init.resolution.height = 500;
    _init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(_init);
}

void Initialize::Destroy_BGFX() {
    bgfx::shutdown();
}

void Initialize::Destroy_SDL2()
{
    Logs::WriteLog(Logs::LogType::INFO, "Destroy SDL Window...");
    SDL_DestroyWindow(window);
    window = nullptr;
    
    Logs::WriteLog(Logs::LogType::INFO, "Exiting SDL2...");
    SDL_Quit();
}
