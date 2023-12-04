#pragma once
#include <SDL.h>
#include <vector>

struct Platform {
    SDL_Rect srcRect, moverRect;
    int speed; // speed of platform
    bool active; // if platform is active
};

extern std::vector<Platform> platformVector;

void createPlatform(int x, int y, bool type); // create platform
void updatePlatforms(); // update platforms
void drawPlatforms(SDL_Renderer* gRenderer, SDL_Texture* assets); // draw platforms
void clearPlatforms(); // clear platforms when player contacts with platform
