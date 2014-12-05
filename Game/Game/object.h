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
	//components enum
	//store everything in bits
	enum E_COMPONENTS
	{
		MOVEMENT = 0x01,
		COLLIDEABLE = 0x02
	};
	//constructor
	Object(
		const std::string filepath,
		const Vector2 &position,
		const float rotation,
		const Vector2 &scale);
	~Object(); 
	virtual void draw();
	virtual void run();
	//virtual void movement();
	virtual void collision();

	void setPosition(const Vector2& v);
	void setRotation(float r);
	void setScale(const Vector2& v);

	const Vector2& getPosition() const;
	const float getRotation() const;
	const Vector2& getScale() const;
protected:
	int components;	//stores the component bits
	int index;
	std::string filepath;
	SDL_Texture *texture;
	Vector2 position;
	float rotation;
	Vector2 scale;
};


#endif
