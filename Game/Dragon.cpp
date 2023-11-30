#include <iostream>
#include "Dragon.hpp"
#include <vector>
using namespace std;

Unit dragon = { {442, 19, 151, 118}, {30, 40, 50, 50} };
vector<Unit> dragonVector;

void createObject(int x, int y) {
    Unit newDragon = { {442, 19, 151, 118}, {x, y, 80, 80} };
    dragonVector.push_back(newDragon);
}

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (const auto& unit : dragonVector) {
        SDL_RenderCopy(gRenderer, assets, &unit.srcRect, &unit.moverRect);
    }
}
