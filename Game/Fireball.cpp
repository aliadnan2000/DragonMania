// Fireball.cpp
#include "Fireball.hpp"

std::vector<Fireball> fireballVector;

bool ifdestroyed = false; // bool to check fireball is destroyed

// Function to create fireball
void createFireball(int x, int y) {
    Fireball newFireball = { {22, 363, 149, 129}, {x, y, 50, 50}, 20, true, false };
    fireballVector.push_back(newFireball);
}

// Function to draw fireballs
void updateFireballs() {
    for (auto& fireball : fireballVector) {
        if (fireball.active) {
            fireball.moverRect.x += fireball.speed;
        }
    }
}

