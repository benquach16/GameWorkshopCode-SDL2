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
	SDL_Rect rect;
	rect.x = position.x;
	rect.y = position.y;
	SDL_Surface *s = SDL_GetWindowSurface(window);
	SDL_BlitSurface(texture, 0, s, &rect);
}

void Object::run()
{
	if (components & E_COMPONENTS::MOVEMENT)
	{
		movement();
	}
}

void Object::setPosition(const Vector2& v)
{
	position = v;
}

void Object::setRotation(const float r)
{
	rotation = r;
}

void Object::setScale(const Vector2& v)
{
	scale = v;
}

const Vector2& Object::getPosition() const
{
	return position;
}

const float Object::getRotation() const
{
	return rotation;
}

const Vector2& Object::getScale() const
{
	return scale;
}


