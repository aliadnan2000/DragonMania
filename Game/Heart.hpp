#pragma once
#include <SDL.h>
#include <vector>

class Heart {
private:
    bool active;

public:
    SDL_Rect srcRect, moverRect;
    Heart(int x, int y);
    void draw(SDL_Renderer* gRenderer, SDL_Texture* assets) const;
    bool isActive() const;
};

extern std::vector<Heart> heartVector;

void createHeart(int x, int y);
void drawHeart(SDL_Renderer* gRenderer, SDL_Texture* assets);
