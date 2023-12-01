#pragma once
#include <SDL.h>
#include <vector>

struct Platform {
    SDL_Rect srcRect, moverRect;
    int speed;
    bool active;
};

extern std::vector<Platform> platformVector;

void createPlatform(int x, int y, bool type);
void updatePlatforms();
void drawPlatforms(SDL_Renderer* gRenderer, SDL_Texture* assets);
void clearPlatforms();