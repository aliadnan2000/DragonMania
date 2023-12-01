#pragma once
#include <SDL.h>
#include <vector>

struct Healthbar {
    SDL_Rect srcRect, moverRect;
    int currentHealth;
};

extern Healthbar healthbar;  // Declaring the healthbar as external

void drawHealthbar(SDL_Renderer* gRenderer, SDL_Texture* assets);
void initializeHealthbar();
void updateHealthbar(int damage);
