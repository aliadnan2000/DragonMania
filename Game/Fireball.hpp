#pragma once
#include <SDL.h>
#include <vector>

struct Fireball {
    SDL_Rect srcRect, moverRect;
    int speed;
    bool active;
};

extern std::vector<Fireball> fireballVector;

void createFireball(int x, int y);
void updateFireballs();
