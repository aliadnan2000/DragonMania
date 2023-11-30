#include <iostream>
#include "Dragon.hpp"
#include <vector>
using namespace std;

std::vector<Unit> dragonVector; // Define the vector

void createObject(int x, int y) {
    Unit newDragon = { {442, 19, 151, 118}, {x, y, 75, 75} };
    dragonVector.push_back(newDragon);
}

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (const auto& unit : dragonVector) {
        SDL_RenderCopy(gRenderer, assets, &unit.srcRect, &unit.moverRect);
    }
}
