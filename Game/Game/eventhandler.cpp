#include "stdafx.h"
#include "eventhandler.h"

EventHandler::EventHandler()
{
	for (unsigned i = 0; i < 256; i++)
		keys[i] = false;
}

EventHandler::~EventHandler()
{

}

void EventHandler::getEvent()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{

		}
		if (e.type == SDL_KEYDOWN)
		{
			keys[e.key.keysym.sym] = true;
		}
		if (e.type == SDL_KEYUP)
		{
			keys[e.key.keysym.sym] = false;
		}
	}
}

bool EventHandler::isKeyDown(SDL_Keycode key)
{
	return keys[key];
}
