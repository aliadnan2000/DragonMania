#pragma once
#include <SDL.h>
#include <vector>

class Heart {
private:
    bool active; // if heart is active

public:
    SDL_Rect srcRect, moverRect;
    Heart(int x, int y);
    void draw(SDL_Renderer* gRenderer, SDL_Texture* assets) const; // draw heart on screen
    bool isActive() const; // if heart is active
};

extern std::vector<Heart> heartVector;

void createHeart(int x, int y); // create heart
void drawHeart(SDL_Renderer* gRenderer, SDL_Texture* assets); // draw hearts on screen
