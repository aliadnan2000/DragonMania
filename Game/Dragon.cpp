#include <iostream>
#include "Dragon.hpp"
#include <vector>
using namespace std;

std::vector<Unit> dragonVector;
int dragonAnimation = 0;
SDL_Point lastDragonPosition = {0, 0};


const int ANIMATION_DELAY_MS = 100; // Delay set in milliseconds

void createObject(int x, int y) {
    Unit newDragon = { {31, 27, 113, 89}, {x, y, 90, 50}, 0 }; // Initial frame index is 0
    dragonVector.push_back(newDragon);

    // Create a fireball along with each dragon
    createFireball(x + 90, y + 20);
}

void drawUnit(SDL_Renderer* gRenderer, SDL_Texture* assets, Unit& unit) {
    SDL_RenderCopy(gRenderer, assets, &unit.srcRect, &unit.moverRect);
}

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Texture* fireballTexture) {
    for (size_t i = 0; i < dragonVector.size(); i++) {
        Unit& dragon = dragonVector[i];
        drawUnit(gRenderer, assets, dragon);

        // Dragon animation based on the object's position in the vector
        if (dragonAnimation == i % 3) {
            dragon.srcRect = {31, 27, 113, 89}; // Set the first frame values
        } else if (dragonAnimation == (i + 1) % 3) {
            dragon.srcRect = {176, 56, 112, 60}; // second frame values
        } else {
            dragon.srcRect = {320, 61, 112, 57}; // third frame values
        }
    }

    // Update the animation counter for the dragon
    dragonAnimation = (dragonAnimation + 1) % 3;

    SDL_Delay(ANIMATION_DELAY_MS);

    for (const auto& fireball : fireballVector) {
        if (fireball.active) {
            SDL_RenderCopy(gRenderer, fireballTexture, &fireball.srcRect, &fireball.moverRect);
        }
    }
}

bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB) {
    return (rectA.x < rectB.x + rectB.w &&
            rectA.x + rectA.w > rectB.x &&
            rectA.y < rectB.y + rectB.h &&
            rectA.y + rectA.h > rectB.y);
}

void checkDragonPlatformCollision() {
    for (const auto& platform : platformVector) {
        for (auto& dragon : dragonVector) {
            if (checkCollision(dragon.moverRect, platform.moverRect)) {
                respawnDragon();
                updateHealthbar(-20);  // Decrease health by 20%
            }
        }
    }
}

void respawnDragon() {
    lastDragonPosition = {10, 360 - 25};  // Center of the screen minus half the dragon size
    dragonVector[0].moverRect.x = lastDragonPosition.x;
    dragonVector[0].moverRect.y = lastDragonPosition.y;
}

