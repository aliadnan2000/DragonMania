#pragma once
#include <SDL.h>


struct Healthbar {
    SDL_Rect srcRect, moverRect;
    int currentHealth;
};

extern Healthbar healthbar;

void drawHealthbar(SDL_Renderer* gRenderer, SDL_Texture* assets);
void initializeHealthbar();
void updateHealthbar(int damage);
void updateHealthbarTexture(const SDL_Rect& newTextureRect);

