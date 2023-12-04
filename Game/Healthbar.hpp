#pragma once
#include <SDL.h>


struct Healthbar {
    SDL_Rect srcRect, moverRect; // source rectangle and mover rectangle
    int currentHealth; // current health
};

extern Healthbar healthbar;

void drawHealthbar(SDL_Renderer* gRenderer, SDL_Texture* assets); // Draw the health bar
void initializeHealthbar(); // Initialize the health bar
void updateHealthbar(int damage); // Update the health bar
void updateHealthbarTexture(const SDL_Rect& newTextureRect); // Update the health bar texture

