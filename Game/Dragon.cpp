#include <iostream>
#include "Dragon.hpp"
#include <vector>
using namespace std;

std::vector<Unit> dragonVector;
int dragonAnimation = 0;
SDL_Point lastDragonPosition = {0, 0};

//for the delay animation
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









// #include <iostream>
// #include "Dragon.hpp"
// #include <vector>
// #include <SDL_keyboard.h>
// #include <SDL_keycode.h>
// using namespace std;

// std::vector<Unit> dragonVector;
// int dragonAnimation = 0;
// SDL_Point lastDragonPosition = {0, 0};

// const int ANIMATION_DELAY_MS = 100;

// void createObject(int x, int y) {
//     Unit newDragon = { {31, 27, 113, 89}, {x, y, 90, 50}, 0 };
//     dragonVector.push_back(newDragon);
//     createFireball(x + 90, y + 20);
// }

// void drawUnit(SDL_Renderer* gRenderer, SDL_Texture* assets, Unit& unit) {
//     SDL_RenderCopy(gRenderer, assets, &unit.srcRect, &unit.moverRect);
// }

// void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Texture* fireballTexture) {
//     const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

//     if (currentKeyStates[SDL_SCANCODE_LEFT]) {
//         lastDragonPosition.x -= 10;
//     }
//     if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
//         lastDragonPosition.x += 10;
//     }
//     if (currentKeyStates[SDL_SCANCODE_UP]) {
//         lastDragonPosition.y -= 10;
//     }
//     if (currentKeyStates[SDL_SCANCODE_DOWN]) {
//         lastDragonPosition.y += 10;
//     }


//     for (size_t i = 0; i < dragonVector.size(); i++) {
//         Unit& dragon = dragonVector[i];
//         dragon.moverRect.x = lastDragonPosition.x;
//         dragon.moverRect.y = lastDragonPosition.y;
//         drawUnit(gRenderer, assets, dragon);

//         if (dragonAnimation == i % 3) {
//             dragon.srcRect = {31, 27, 113, 89};
//         } else if (dragonAnimation == (i + 1) % 3) {
//             dragon.srcRect = {176, 56, 112, 60};
//         } else {
//             dragon.srcRect = {320, 61, 112, 57};
//         }
//     }

//     dragonAnimation = (dragonAnimation + 1) % 3;

//     for (const auto& fireball : fireballVector) {
//         if (fireball.active) {
//             SDL_RenderCopy(gRenderer, fireballTexture, &fireball.srcRect, &fireball.moverRect);
//         }
//     }
//     SDL_Delay(ANIMATION_DELAY_MS);


// }





// dragon.cpp
// #include <iostream>
// #include "Dragon.hpp"
// #include <vector>
// #include <SDL_keyboard.h>
// #include <SDL_keycode.h>
// #include "Platform.hpp"
// #include "Healthbar.hpp" // Include Healthbar.hpp
// using namespace std;

// std::vector<Unit> dragonVector;
// int dragonAnimation = 0;
// SDL_Point lastDragonPosition = {0, 0};

// const int ANIMATION_DELAY_MS = 100;

// void createObject(int x, int y) {
//     Unit newDragon = { {31, 27, 113, 89}, {x, y, 90, 50}, 0 };
//     dragonVector.push_back(newDragon);
//     createFireball(x + 90, y + 20);
// }

// void drawUnit(SDL_Renderer* gRenderer, SDL_Texture* assets, Unit& unit) {
//     SDL_RenderCopy(gRenderer, assets, &unit.srcRect, &unit.moverRect);
// }

// bool checkDragonCollision(const SDL_Rect& dragonRect) {
//     for (const auto& platform : platformVector) {
//         if (platform.active && SDL_HasIntersection(&dragonRect, &platform.moverRect)) {
//             // Collision detected
//             return true;
//         }
//     }
//     return false; // No collision detected
// }

// void updateHealthbar(int damage) {
//     healthbar.currentHealth -= damage;
//     if (healthbar.currentHealth < 0) {
//         healthbar.currentHealth = 0;
//     }
// }

// void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Texture* fireballTexture) {
//     const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

//     if (currentKeyStates[SDL_SCANCODE_LEFT]) {
//         lastDragonPosition.x -= 5;
//     }
//     if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
//         lastDragonPosition.x += 5;
//     }
//     if (currentKeyStates[SDL_SCANCODE_UP]) {
//         lastDragonPosition.y -= 5;
//     }
//     if (currentKeyStates[SDL_SCANCODE_DOWN]) {
//         lastDragonPosition.y += 5;
//     }


//     SDL_Rect dragonRect = { lastDragonPosition.x, lastDragonPosition.y, 90, 50 };

//     // Check collision before drawing
//     if (!checkDragonCollision(dragonRect)) {
//         for (size_t i = 0; i < dragonVector.size(); i++) {
//             Unit& dragon = dragonVector[i];
//             dragon.moverRect.x = lastDragonPosition.x;
//             dragon.moverRect.y = lastDragonPosition.y;
//             drawUnit(gRenderer, assets, dragon);

//             if (dragonAnimation == i % 3) {
//                 dragon.srcRect = {31, 27, 113, 89};
//             } else if (dragonAnimation == (i + 1) % 3) {
//                 dragon.srcRect = {176, 56, 112, 60};
//             } else {
//                 dragon.srcRect = {320, 61, 112, 57};
//             }
//         }
//     } else {
//         // Dragon collided with a platform, update health
//         updateHealthbar(10); // Adjust the damage value as needed
//     }

//     dragonAnimation = (dragonAnimation + 1) % 3;

//     for (const auto& fireball : fireballVector) {
//         if (fireball.active) {
//             SDL_RenderCopy(gRenderer, fireballTexture, &fireball.srcRect, &fireball.moverRect);
//         }
//     }


//     SDL_Delay(ANIMATION_DELAY_MS);
// }
