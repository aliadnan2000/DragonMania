#include "Healthbar.hpp"
#include <iostream>

Healthbar healthbar = { {891, 329, 481, 27}, {400, 10, 481, 27}, 100 };

void drawHealthbar(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    SDL_RenderCopy(gRenderer, assets, &healthbar.srcRect, &healthbar.moverRect);
}

void initializeHealthbar() {
    healthbar.moverRect.x = (1280 - healthbar.moverRect.w) / 2;
    healthbar.moverRect.y = 15;
}

void updateHealthbar(int damage) {
    healthbar.currentHealth -= damage;
    if (healthbar.currentHealth < 0) {
        healthbar.currentHealth = 0;
    }
}

void updateHealthbarTexture(const SDL_Rect& newTextureRect) {
    // Update the health bar texture
    healthbar.srcRect = newTextureRect;
}