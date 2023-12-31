#include "Platform.hpp"
#include <cstdlib>
#include <ctime>

std::vector<Platform> platformVector; // Vector to hold all the platforms

void createPlatform(int x, int y, bool type) {
    SDL_Rect platformRect;
    int speed; // intialized speed of the platform

    if (type) {
        platformRect = {1142, 473, 130, 355};
        speed = 10;  // Speed for the bottom platform
    } else {
        platformRect = {979, 439, 130, 351};
        speed = 10;  // Speed for the top platform
    }

    Platform newPlatform = {platformRect, {x, y, 130, 388}, speed, true};
    platformVector.push_back(newPlatform);
}

void updatePlatforms() {
    static Uint32 startTime = SDL_GetTicks();  // Static to keep track of the start time
    Uint32 currentTime = SDL_GetTicks(); // Get the current time
    Uint32 elapsedTime = currentTime - startTime; // Calculate the elapsed time

    for (auto& platform : platformVector) {
        if (platform.active) {
            platform.moverRect.x -= platform.speed;

            // Check if the platform has reached the left side of the screen
            if (platform.moverRect.x + platform.moverRect.w < 0) {
                platform.active = false;  // Deactivate the platform

                // Randomly generate a new platform (top or bottom)
                bool isTopPlatform = rand() % 2 == 0;
                int newY = isTopPlatform ? 0 : 500;  // Adjust the y-coordinate as needed

                //createPlatform(1280, , isTopPlatform); // Create the new platform
                createPlatform(1280, 0 - rand() % 150, false);
                createPlatform(1280, 500 + rand() % 151, false);
            }
        }
    }

    // Check if 40 seconds have elapsed, reset the timer, and clear the platforms
    if (elapsedTime >= 40000) {
        startTime = currentTime;
        clearPlatforms();
    }
}

void drawPlatforms(SDL_Renderer* gRenderer, SDL_Texture* assets) { // draw platforms
    for (const auto& platform : platformVector) {
        if (platform.active) {
            SDL_RenderCopy(gRenderer, assets, &platform.srcRect, &platform.moverRect);
        }
    }
}

void clearPlatforms() { // clear platforms when player contacts with platform
    platformVector.clear();
}
