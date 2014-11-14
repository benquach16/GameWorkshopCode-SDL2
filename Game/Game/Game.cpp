// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "globals.h"
#include "object.h"
#include <SDL.h>

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2test.lib")


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Game", 50, 50,
		640, 480, 0);

	globals::renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(globals::renderer, 0, 0, 0, 255);
	Object *obj= new Object(
		window,
		"Resources/Art/pacman.bmp",
		Vector2(0,0),
		0.0f,
		Vector2(0,0));
	
	while (true)
	{
		SDL_RenderClear(globals::renderer);
		//game stuff goes here
		for (unsigned i = 0; i < Object::allObjects.size(); i++)
		{
			Object::allObjects[i]->draw();
		}
		SDL_RenderPresent(globals::renderer);
		SDL_UpdateWindowSurface(window);
	}
	SDL_DestroyWindow(window);
	return 0;
}

