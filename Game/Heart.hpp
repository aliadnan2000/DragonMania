#pragma once
#include <SDL.h>
#include <vector>

struct Heart {
    SDL_Rect srcRect, moverRect;
    bool active;  
};

extern std::vector<Heart> heartVector;

void createHeart(int x, int y);
void drawHeart(SDL_Renderer* gRenderer, SDL_Texture* assets);
