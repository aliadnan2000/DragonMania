#include "Boss.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "AntiFireball.hpp"

std::vector<Boss> bossVector;

//const int BOSS_ANIMATION_DELAY_MS = 90; // Delay set in milliseconds

void updateBossAnimation(Boss& boss) {
    // Dragon animation based on the object's position in the vector
    if (boss.currentFrameIndex == 0) {
        boss.srcRect = {18, 211, 148, 76}; // First frame values
    } else if (boss.currentFrameIndex == 1) {
        boss.srcRect = {208, 204, 152, 80}; // Second frame
    } else {
        boss.srcRect = {399, 166, 151, 118}; // Third frame
    }
}

void updateBossMovement(Boss& boss) {
    // Implementation for boss dragon movement logic

    int moveDirection = rand() % 2 == 0 ? 1 : -1;  // 1 for up, -1 for down
    int moveAmount = rand() % 15 + 5;  // Random move amount

    // Check if the boss is at the top or bottom of the screen then change direction
    if ((boss.moverRect.y <= 0 && moveDirection == -1) ||
        (boss.moverRect.y + boss.moverRect.h >= 720 && moveDirection == 1)) {
        moveDirection *= -1;  // Changing direction
    }

    // Update boss position
    boss.moverRect.y += moveAmount * moveDirection;
}

void createBoss() {
    Boss newBoss = {{18, 211, 148, 76}, {1100, 360, 160, 82}, 0, true, false};
    bossVector.push_back(newBoss);
}

void updateBoss() {
    for (auto& boss : bossVector) {
        if (boss.active) {
            // Update boss animation
            updateBossAnimation(boss);

            // Update boss movement
            updateBossMovement(boss);

            // Randomly shoot fireballs
            if (rand() % 100 < 5) {  // 5% chance to shoot a fireball
                //function to create a fireball for the boss
                createAntiFireball(boss.moverRect.x, boss.moverRect.y + boss.moverRect.h / 2);
            }

            // Update boss animation counter
            boss.currentFrameIndex = (boss.currentFrameIndex + 1) % 3;

            //SDL_Delay(BOSS_ANIMATION_DELAY_MS);
        }
    }
}

void drawBoss(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (auto& boss : bossVector) {
        if (boss.active) {
            SDL_RenderCopy(gRenderer, assets, &boss.srcRect, &boss.moverRect);
        }
    }
}
