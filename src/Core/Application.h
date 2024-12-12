#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>

class Application {
public:
    Application();
    ~Application();
    void Run();

private:
    SDL_Window* window;
    bool isRunning;
};

#endif // APPLICATION_H
