#pragma once
#include <SDL.h>
#include <SDL_image.h>

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    ~RenderWindow() { cleanUp(); } // Destructor to ensure cleanup
    void cleanUp();
    SDL_Renderer* getRenderer() const { return renderer; } // Added function to get the renderer
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
