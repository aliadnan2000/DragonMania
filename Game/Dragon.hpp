// Dragon.hpp
#pragma once
#include <SDL.h>
#include <vector>
#include "Fireball.hpp"
#include "Healthbar.hpp"
#include "Platform.hpp"
#include "Heart.hpp"
#include "AntiFireball.hpp"

struct Unit {
    SDL_Rect srcRect, moverRect;
    int currentFrameIndex;
};

extern std::vector<Unit> dragonVector;
extern int dragonAnimation; // dragon animation
extern int remainingHearts; // remaining hearts

void drawUnit(SDL_Renderer* gRenderer, SDL_Texture* assets, Unit& unit); // draw dragon
void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Texture* fireballTexture);
void createObject(int x, int y); // create dragon
void checkDragonPlatformCollision(); // check if dragon collides with platform
void respawnDragon(); // respawn dragon when dragon collides with platform
void decrementHearts(); // decrement hearts when dragon collides with fireball
void checkDragonAntiFireballCollision(); // check if dragon collides with anti fireball

