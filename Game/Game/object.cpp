#include "stdafx.h"
#include "object.h"

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
	
}

Object::~Object()
{

}


