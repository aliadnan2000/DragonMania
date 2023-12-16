#include "AssetLoader.hpp"
#include <SDL_image.h>
#include <iostream>

SDL_Texture* AssetLoader::LoadTexture(const std::string& filePath, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(filePath.c_str());
    if (tempSurface == nullptr) {
        std::cout << "Failed to load image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        //return 1;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if (texture == nullptr) {
        std::cout << "Failed to create texture from image. Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        //return 1;
    }
    return texture;
}
