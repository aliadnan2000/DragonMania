#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init failed. SDL_ERROR: " << SDL_GetError() << std::endl;
		return 1;
	}

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		std::cout << "IMG_Init failed. Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	RenderWindow window("GAME v1.0", 1280, 720);

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
	}

	window.cleanUp();
	SDL_Quit();
	return 0;
}