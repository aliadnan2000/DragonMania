#pragma once
#include <SDL.h>

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets);
void createObject(int x, int y);

struct Unit {
    SDL_Rect srcRect, moverRect;
};
