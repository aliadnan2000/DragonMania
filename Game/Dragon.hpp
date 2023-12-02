
// Dragon.hpp
#pragma once
#include <SDL.h>
#include <vector>
#include "Fireball.hpp"
#include "Healthbar.hpp"
#include "Platform.hpp"

struct Unit {
    SDL_Rect srcRect, moverRect;
    int currentFrameIndex;
};

extern std::vector<Unit> dragonVector;
extern int dragonAnimation;

void drawUnit(SDL_Renderer* gRenderer, SDL_Texture* assets, Unit& unit);
void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Texture* fireballTexture);
void createObject(int x, int y);
void checkDragonPlatformCollision();
void respawnDragon();
void updateHealthbar(int damage);
