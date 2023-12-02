// // Dragon.hpp
// #pragma once
// #include <SDL.h>
// #include <vector>
// #include "Fireball.hpp"

// struct Unit {
//     SDL_Rect srcRect, moverRect;
//     int currentFrameIndex;
// };


// extern std::vector<Unit> dragonVector; // Declaring the vector as external
// extern int dragonAnimation;

// void drawUnit(SDL_Renderer* gRenderer, SDL_Texture* assets, Unit& unit);
// void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Texture* fireballTexture); // Passing  fireballTexture now
// void createObject(int x, int y);


// Dragon.hpp
#pragma once
#include <SDL.h>
#include <vector>
#include "Fireball.hpp"

struct Unit {
    SDL_Rect srcRect, moverRect;
    int currentFrameIndex;
};

extern std::vector<Unit> dragonVector;
extern int dragonAnimation;
extern SDL_Point lastDragonPosition;

void drawUnit(SDL_Renderer* gRenderer, SDL_Texture* assets, Unit& unit);
void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Texture* fireballTexture);
void createObject(int x, int y);
