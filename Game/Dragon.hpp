#pragma once
#include <SDL.h>
#include <vector>

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets);
void createObject(int x, int y);

struct Unit {
    SDL_Rect srcRect, moverRect;
};

extern std::vector<Unit> dragonVector; // Declare the vector as external