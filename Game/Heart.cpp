#include "Heart.hpp"
#include "Dragon.hpp"  
#include <iostream>
#include <vector>

std::vector<Heart> heartVector;

//function to create hearts
void createHeart(int x, int y) {
    Heart newHeart = { {660, 36, 86, 76}, {x, y, 40, 36}, true };
    heartVector.push_back(newHeart);
}

//function to draw hearts
void drawHeart(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (const auto& heart : heartVector) {
        if (heart.active) {
            SDL_RenderCopy(gRenderer, assets, &heart.srcRect, &heart.moverRect);
        }
    }
}
