#include "Heart.hpp"
#include "Dragon.hpp"
#include <iostream>
#include <vector>

std::vector<Heart> heartVector;

// Constructor for Heart class
Heart::Heart(int x, int y) : srcRect({660, 36, 86, 76}), moverRect({x, y, 40, 36}), active(true) {}

// Function to create hearts
void createHeart(int x, int y) {
    Heart newHeart(x, y); // create new heart
    heartVector.push_back(newHeart); // heart to vector
}

// Function to draw hearts
void drawHeart(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (const auto& heart : heartVector) {
        if (heart.isActive()) {
            heart.draw(gRenderer, assets);
        }
    }
}

// Member function to draw a single heart
void Heart::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) const {
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

// Member function to check the status of 'active'
bool Heart::isActive() const {
    return active;
}
