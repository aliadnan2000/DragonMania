#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init failed. SDL_ERROR: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        std::cout << "IMG_Init failed. Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    RenderWindow window("GAME v1.0", 1280, 720);

    // Load background image
    SDL_Surface* backgroundImage = IMG_Load("bg.png");
    if (!backgroundImage)
    {
        std::cout << "Failed to load background image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Convert the surface to a texture
    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(window.getRenderer(), backgroundImage);
    SDL_FreeSurface(backgroundImage);

    if (!backgroundTexture)
    {
        std::cout << "Failed to create texture from background image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning)
    {
        // Get our controls and events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        // Clear the renderer
        SDL_RenderClear(window.getRenderer());

        // Render the background
        SDL_RenderCopy(window.getRenderer(), backgroundTexture, nullptr, nullptr);

        // Present the renderer
        SDL_RenderPresent(window.getRenderer());
    }

    // Clean up resources
    SDL_DestroyTexture(backgroundTexture);
    window.cleanUp();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
