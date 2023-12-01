// Fireball.cpp
#include "Fireball.hpp"

std::vector<Fireball> fireballVector;

void createFireball(int x, int y) {
    Fireball newFireball = { {22, 363, 149, 129}, {x, y, 50, 50}, 15, false };
    fireballVector.push_back(newFireball);
}

void updateFireballs() {
    for (auto& fireball : fireballVector) {
        if (fireball.active) {
            fireball.moverRect.x += fireball.speed;
        }
    }
}

