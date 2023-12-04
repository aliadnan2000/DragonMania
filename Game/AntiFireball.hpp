#pragma once
#include <SDL.h>
#include <vector>

struct AntiFireball {
    SDL_Rect srcRect, moverRect;
    int speed; // speed of anti-fireball
    bool active; // if anti-fireball is active
};

extern std::vector<AntiFireball> antiFireballVector;

void createAntiFireball(int x, int y); // create anti-fireball
void updateAntiFireballs(); // update anti-fireballs
void drawAntiFireballs(SDL_Renderer* gRenderer, SDL_Texture* assets); // draw anti-fireballs on screen
