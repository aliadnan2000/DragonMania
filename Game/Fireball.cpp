// Fireball.cpp
#include "Fireball.hpp"

std::vector<Fireball> fireballVector;

bool ifdestroyed = false;

void createFireball(int x, int y) {
    Fireball newFireball = { {22, 363, 149, 129}, {x, y, 50, 50}, 20, true, false };
    fireballVector.push_back(newFireball);
}

void updateFireballs() {
    for (auto& fireball : fireballVector) {
        if (fireball.active) {
            fireball.moverRect.x += fireball.speed;
        }
    }
}

