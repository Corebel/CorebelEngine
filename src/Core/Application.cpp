#include "Application.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

Application::Application() : window(nullptr), isRunning(true) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        isRunning = false;
        return;
    }

    // Create SDL Window
    window = SDL_CreateWindow("CorebelEngine",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              1280, 720, SDL_WINDOW_SHOWN);

    // Initialize bgfx
    bgfx::Init bgfxInit;
    bgfxInit.type = bgfx::RendererType::Count; // Auto-detect renderer
    bgfxInit.platformData.nwh = SDL_GetWindowWMInfo(window)->info.win.window;
    bgfx::init(bgfxInit);
}

Application::~Application() {
    // Cleanup
    bgfx::shutdown();
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::Run() {
    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) isRunning = false;
        }

        // Render Frame
        bgfx::touch(0); // Clear screen
        bgfx::frame();
    }
}
