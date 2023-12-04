#pragma once
#include <SDL.h>
#include <vector>

struct Boss {
    SDL_Rect srcRect, moverRect;
    int currentFrameIndex;
    bool movingUp; // if boss is moving up
    bool active; // if boss is active
    bool spawned; // if boss is spawned
};

extern std::vector<Boss> bossVector; // boss vector
extern int bossHealth; // boss health

void createBoss(); // create boss dragon
void updateBoss(); // update boss dragon
void drawBoss(SDL_Renderer* gRenderer, SDL_Texture* assets); // draw boss dragon on screen
bool isBossDefeated(); // if boss is defeated
void updateBossHealth(); // update boss health bar

