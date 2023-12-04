#pragma once
#include <SDL.h>
#include <vector>

struct Fireball {
    SDL_Rect srcRect, moverRect;
    int speed; // speed of fireball
    bool active; // if fireball is active
    bool ifdestroyed; // if fireball is destroyed
};

extern std::vector<Fireball> fireballVector;

void createFireball(int x, int y); // create fireball
void updateFireballs(); // update fireballs
