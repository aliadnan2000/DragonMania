#pragma once
#include <SDL.h>

struct Healthbar {
    SDL_Rect srcRect, moverRect;
    int currentHealth;
};

extern Healthbar healthbar;

void drawHealthbar(SDL_Renderer* gRenderer, SDL_Texture* assets);
void initializeHealthbar();
inline void updateHealthbar(int damage);

