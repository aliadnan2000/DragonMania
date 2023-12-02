#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Dragon.hpp"
#include "Fireball.hpp"
#include "Healthbar.hpp"
#include "Platform.hpp"

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

    RenderWindow window("Dragoon v1.0", 1280, 720);

    // Load intro image
    SDL_Surface* introSurface = IMG_Load("starting screen.png");
    if (!introSurface)
    {
        std::cout << "Failed to load intro image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* introTexture = SDL_CreateTextureFromSurface(window.getRenderer(), introSurface);
    SDL_FreeSurface(introSurface);

    if (!introTexture)
    {
        std::cout << "Failed to create texture from intro image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Render the intro image
    SDL_RenderCopy(window.getRenderer(), introTexture, nullptr, nullptr);
    SDL_RenderPresent(window.getRenderer());

    // Wait for a key press or mouse click to start the game
    bool introComplete = false;
    while (!introComplete)
    {
        SDL_Event introEvent;
        while (SDL_PollEvent(&introEvent))
        {
            if (introEvent.type == SDL_QUIT)
            {
                introComplete = true;
            }
            else if (introEvent.type == SDL_KEYDOWN || introEvent.type == SDL_MOUSEBUTTONDOWN)
            {
                introComplete = true;
            }
        }
    }

    SDL_DestroyTexture(introTexture);

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

    // Load dragon image
    SDL_Surface* dragonSurface = IMG_Load("assets.png");
    if (!dragonSurface)
    {
        std::cout << "Failed to load dragon image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* dragonTexture = SDL_CreateTextureFromSurface(window.getRenderer(), dragonSurface);
    SDL_FreeSurface(dragonSurface);

    // Load fireball image
    SDL_Surface* fireballSurface = IMG_Load("assets.png");
    if (!fireballSurface)
    {
        std::cout << "Failed to load fireball image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* fireballTexture = SDL_CreateTextureFromSurface(window.getRenderer(), fireballSurface);
    SDL_FreeSurface(fireballSurface);

    // Load healthbar image
    SDL_Surface* healthbarSurface = IMG_Load("assets.png");
    if (!healthbarSurface) {
        std::cout << "Failed to load healthbar image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* healthbarTexture = SDL_CreateTextureFromSurface(window.getRenderer(), healthbarSurface);
    SDL_FreeSurface(healthbarSurface);

    if (!healthbarTexture) {
        std::cout << "Failed to create texture from assets image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Load platform image
    SDL_Surface* platformSurface = IMG_Load("assets.png");
    if (!platformSurface) {
        std::cout << "Failed to load platform image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* platformTexture = SDL_CreateTextureFromSurface(window.getRenderer(), platformSurface);
    SDL_FreeSurface(platformSurface);

    if (!platformTexture) {
        std::cout << "Failed to create texture from assets image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Create dragon objects
    createObject(100, 100);  // Example position (just testing for now)

    // Create fireball objects
    //createFireball(0, 0);

    // Create health bar object
    initializeHealthbar();
    
    // Create platform objects
    createPlatform(1280, 500, true);

    bool gameRunning = true;
    SDL_Event event;
    Uint32 startTime = SDL_GetTicks();
    bool secondPlatformCreated = false;

    while (gameRunning)
    {
        Uint32 currentTime = SDL_GetTicks();
        Uint32 elapsedTime = currentTime - startTime;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;

            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_w:
                        for (auto& unit : dragonVector)
                            unit.moverRect.y -= 20;  // To adjust movement speed
                        break;

                    case SDLK_s:
                        for (auto& unit : dragonVector)
                            unit.moverRect.y += 20;
                        break;

                    case SDLK_SPACE:
                        for (auto& fireball : fireballVector)
                        {
                            fireball.active = true;
                        }

                        for (auto& unit : dragonVector)
                        {
                            createFireball(unit.moverRect.x + unit.moverRect.w, unit.moverRect.y + unit.moverRect.h / 2);
                        }
                        break;
                }
            }
        }

        SDL_RenderClear(window.getRenderer());

        // Render the background
        SDL_RenderCopy(window.getRenderer(), backgroundTexture, nullptr, nullptr);

        // Render the dragon
        drawObjects(window.getRenderer(), dragonTexture, fireballTexture);

        // Update and move fireballs
        updateFireballs();
        checkDragonPlatformCollision();

        // Update and draw platforms
        if (elapsedTime >= 4000 && !secondPlatformCreated)
        {
            createPlatform(1280, 0, false);
            secondPlatformCreated = true;
        }
        updatePlatforms();
        drawPlatforms(window.getRenderer(), platformTexture);

        // Update and draw the healthbar
        drawHealthbar(window.getRenderer(), healthbarTexture);

        SDL_RenderPresent(window.getRenderer());
    }

    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(dragonTexture);
    SDL_DestroyTexture(fireballTexture);
    SDL_DestroyTexture(healthbarTexture);
    SDL_DestroyTexture(platformTexture);
    window.cleanUp();
    IMG_Quit();
    SDL_Quit();

    return 0;
}