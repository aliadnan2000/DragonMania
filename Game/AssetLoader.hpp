#pragma once
#include <SDL.h>
#include <string>

class AssetLoader {
public:
    static SDL_Texture* LoadTexture(const std::string& filePath, SDL_Renderer* renderer);
};
