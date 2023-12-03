#include <iostream>
#include "Dragon.hpp"
#include <vector>
using namespace std;

std::vector<Unit> dragonVector;
int dragonAnimation = 0;
SDL_Point lastDragonPosition = {0, 0};
int remainingHearts = 3;


const int ANIMATION_DELAY_MS = 85; // Delay set in milliseconds

// function to decrement hearts and print the remaining hearts
void decrementHearts() {
    remainingHearts = std::max(0, remainingHearts - 1);
    std::cout<<"Remaining Hearts: "<<remainingHearts<<std::endl;
}

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

//function to check collision
bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB) {
    return (rectA.x < rectB.x + rectB.w &&
            rectA.x + rectA.w > rectB.x &&
            rectA.y < rectB.y + rectB.h &&
            rectA.y + rectA.h > rectB.y);
}

//function to check collision between platform and fireball
void destroyPlatform(int index) {
    if (index >= 0 && index < platformVector.size()) {
        platformVector[index].active = false;
    }
}

void destroyFireball(int index) {
    if (index >= 0 && index < fireballVector.size()) {
        fireballVector[index].active = false;
        fireballVector[index].ifdestroyed = true;
    }
}

//function to check collision between dragon and platform and respawn dragon and decrement hearts
void checkDragonPlatformCollision() {
    // Check collision between dragon and platform
    for (auto& dragon : dragonVector) {
        for (size_t i = 0; i < platformVector.size(); ++i) {
            if (platformVector[i].active && checkCollision(dragon.moverRect, platformVector[i].moverRect)) {
                respawnDragon();
                decrementHearts();
                destroyPlatform(i);
            }
        }
    }

    // Check collision between fireball and platform
    for (size_t i = 0; i < fireballVector.size(); ++i) {
        if (fireballVector[i].active) {
            for (size_t j = 0; j < platformVector.size(); ++j) {
                if (platformVector[j].active && checkCollision(fireballVector[i].moverRect, platformVector[j].moverRect)) {
                    fireballVector[i].active = false;
                    std::cout << "Fireball destroyed" << std::endl;
                    destroyFireball(i);
                    break;
                }
            }
        }
    }
}

void checkDragonAntiFireballCollision() {
    for (auto& dragon : dragonVector) {
        for (auto& antiFireball : antiFireballVector) {
            if (antiFireball.active && checkCollision(dragon.moverRect, antiFireball.moverRect)) {
                std::cout << "Dragon hit by AntiFireball! Decreasing hearts..." << std::endl;
                respawnDragon();
                decrementHearts();
                antiFireball.active = false;  // Deactivate the AntiFireball after collision
            }
        }
    }
}


//function to respawn dragon
void respawnDragon() {
    lastDragonPosition = {10, 360 - 25};  // Center of the screen minus half the dragon size
    dragonVector[0].moverRect.x = lastDragonPosition.x;
    dragonVector[0].moverRect.y = lastDragonPosition.y;
}

