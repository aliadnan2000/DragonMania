#include "Platform.hpp"

std::vector<Platform> platformVector;

void createPlatform(int x, int y, bool type) {
    SDL_Rect platformRect;
    int speed;

    if (type) {
        platformRect = {1142, 440, 130, 388};
        speed = 10;  // Speed for the bottom platform
    } else {
        platformRect = {979, 439, 130, 388};
        speed = 13;  // Speed for the top platform
    }

    Platform newPlatform = {platformRect, {x, y, 130, 388}, speed, true};
    platformVector.push_back(newPlatform);
}

void updatePlatforms() {
    for (auto& platform : platformVector) {
        if (platform.active) {
            platform.moverRect.x -= platform.speed;
            // additional logic to handle when platforms go off-screen
            // and whether to reset or remove them from the vector will decide later
        }
    }
}

void drawPlatforms(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (const auto& platform : platformVector) {
        if (platform.active) {
            SDL_RenderCopy(gRenderer, assets, &platform.srcRect, &platform.moverRect);
        }
    }
}
