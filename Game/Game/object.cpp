#include "stdafx.h"
#include "object.h"
#include "globals.h"

std::vector<Object*> Object::allObjects;

Object::Object(
	const std::string filepath,
	const Vector2 &position,
	const float rotation,
	const Vector2 &scale) 
	:
	filepath(filepath),
	position(position),
	rotation(rotation),
	scale(scale)
{
	SDL_Surface *s = SDL_LoadBMP(filepath.c_str());

	texture = SDL_CreateTextureFromSurface(globals::renderer, s);

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
	rect.w = scale.x;
	rect.h = scale.y;
	SDL_RenderCopy(globals::renderer, texture, NULL,&rect);
}

void Object::run()
{
	if (components & E_COMPONENTS::MOVEMENT)
	{
		//movement();
	}
	collision();
}

#include <iostream>
void Object::collision()
{
	for (unsigned i = 0; i < allObjects.size(); i++)
	{
		if (allObjects[i]->getPosition().x < position.x + scale.x &&
			allObjects[i]->getPosition().x + allObjects[i]->getScale().x > position.x &&
			allObjects[i]->getPosition().y < position.y + scale.y &&
			allObjects[i]->getPosition().y + allObjects[i]->getScale().y > position.y)
		{
			if (this != allObjects[i])
			{

			
			}
		}
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


