#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "vector2.h"
#include <SDL.h>
#include <string>

class Object
{
public:
	Object(
		const std::string filepath,
		const Vector2 &position,
		const float rotation,
		const Vector2 &scale);
	~Object(); 

protected:
	std::string filepath;
	SDL_Texture *texture;
	Vector2 position;
	float rotation;
	Vector2 scale;
};


#endif
