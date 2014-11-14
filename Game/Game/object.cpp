#include "stdafx.h"
#include "object.h"

std::vector<Object*> Object::allObjects;

Object::Object(
	SDL_Window *window,
	const std::string filepath,
	const Vector2 &position,
	const float rotation,
	const Vector2 &scale) 
	:
	window(window),
	filepath(filepath),
	position(position),
	rotation(rotation),
	scale(scale)
{
	texture = SDL_LoadBMP(filepath.c_str());

	allObjects.push_back(this);
	index = allObjects.size() - 1;
}

Object::~Object()
{

}

void Object::draw()
{
	SDL_Surface *s = SDL_GetWindowSurface(window);
	SDL_BlitSurface(texture, 0, s, 0);
}

void Object::run()
{

}

