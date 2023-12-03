#pragma once
#include <SDL.h>
#include <vector>

struct Boss {
    SDL_Rect srcRect, moverRect;
    int currentFrameIndex;
    bool movingUp;
    bool active;
    bool spawned;
};

extern std::vector<Boss> bossVector;

void createBoss();
void updateBoss();
void drawBoss(SDL_Renderer* gRenderer, SDL_Texture* assets);

