#include "Platform.hpp"
#include <cstdlib>
#include <ctime>

std::vector<Platform> platformVector;

void createPlatform(int x, int y, bool type) {
    SDL_Rect platformRect;
    int speed;

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
    Uint32 currentTime = SDL_GetTicks();
    Uint32 elapsedTime = currentTime - startTime;

    for (auto& platform : platformVector) {
        if (platform.active) {
            platform.moverRect.x -= platform.speed;

            // Check if the platform has reached the left side of the screen
            if (platform.moverRect.x + platform.moverRect.w < 0) {
                platform.active = false;  // Deactivate the platform

                // Randomly generate a new platform (top or bottom)
                bool isTopPlatform = rand() % 2 == 0;
                int newY = isTopPlatform ? 0 : 500;  // Adjust the y-coordinate as needed

                createPlatform(1280, newY, isTopPlatform);
            }
        }
    }

    // Check if 30 seconds have elapsed, reset the timer, and clear the platforms
    if (elapsedTime >= 40000) {
        startTime = currentTime;
        clearPlatforms();
    }
}

void drawPlatforms(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (const auto& platform : platformVector) {
        if (platform.active) {
            SDL_RenderCopy(gRenderer, assets, &platform.srcRect, &platform.moverRect);
        }
    }
}

void clearPlatforms() {
    platformVector.clear();
}
