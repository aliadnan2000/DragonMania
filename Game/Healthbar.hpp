#pragma once
#include <SDL.h>
#include <vector>

struct Healthbar {
    SDL_Rect srcRect, moverRect;
    int currentHealth;
};

extern Healthbar healthbar;  // Declaring the healthbar as external

void drawHealthbar(SDL_Renderer* gRenderer, SDL_Texture* assets);
void initializeHealthbar();
void updateHealthbar(int damage);




// platform.hpp


// #pragma once
// #include <SDL.h>
// #include <vector>

// struct Platform {
//     SDL_Rect srcRect, moverRect;
//     int speed;
//     bool active;
// };

// extern std::vector<Platform> platformVector;

// void createPlatform(int x, int y, bool type);
// void updatePlatforms();
// void drawPlatforms(SDL_Renderer* gRenderer, SDL_Texture* assets);
// void clearPlatforms();


// healthbar.hpp
// #pragma once
// #include <SDL.h>

// struct Healthbar {
//     SDL_Rect srcRect, moverRect;
//     int currentHealth;
// };

// extern Healthbar healthbar;

// void drawHealthbar(SDL_Renderer* gRenderer, SDL_Texture* assets);
// void initializeHealthbar();
// void updateHealthbar(int damage);
