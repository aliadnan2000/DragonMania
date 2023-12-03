#pragma once
#include <SDL.h>
#include <vector>

struct AntiFireball {
    SDL_Rect srcRect, moverRect;
    int speed;
    bool active;
};

extern std::vector<AntiFireball> antiFireballVector;

void createAntiFireball(int x, int y);
void updateAntiFireballs();
void drawAntiFireballs(SDL_Renderer* gRenderer, SDL_Texture* assets);
