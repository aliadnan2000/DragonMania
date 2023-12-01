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

/* void updateHealthbar(int damage) {
    // Update the healthbar based on the damage taken
    healthbar.currentHealth -= damage;

    // Ensure that health does not go below 0
    if (healthbar.currentHealth < 0) {
        healthbar.currentHealth = 0;
    }

    // Adjust the width of the healthbar based on the current health percentage
    int newWidth = static_cast<int>(static_cast<double>(healthbar.currentHealth) / 100.0 * healthbar.srcRect.w);
    healthbar.moverRect.w = newWidth;
}
 */