#include "Healthbar.hpp"
#include <iostream>

Healthbar healthbar = { {891, 329, 481, 27}, {400, 10, 481, 27}, 100 };  // Initial health is set to 100

void drawHealthbar(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    SDL_RenderCopy(gRenderer, assets, &healthbar.srcRect, &healthbar.moverRect);
}


void initializeHealthbar() {
    // Set the initial position of the health bar
    healthbar.moverRect.x = (1280 - healthbar.moverRect.w) / 2;  // Centered horizontally
    healthbar.moverRect.y = 15;  // 10 pixels from the top
}