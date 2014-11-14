#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "vector2.h"
#include <SDL.h>
#include <string>
#include <vector>

class Object
{
public:
	//this is a static vector
	//is a global vector of objects so we have a list of all objects created
	static std::vector<Object*> allObjects;
	//constructor
	Object(
		SDL_Window *window,
		const std::string filepath,
		const Vector2 &position,
		const float rotation,
		const Vector2 &scale);
	~Object(); 
	virtual void draw();
	virtual void run();
protected:
	int index;
	SDL_Window *window;
	std::string filepath;
	SDL_Surface *texture;
	Vector2 position;
	float rotation;
	Vector2 scale;
};


#endif
