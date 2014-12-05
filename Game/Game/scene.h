#ifndef __SCENE_H__
#define __SCENE_H__

#include "object.h"

class Scene
{
public:
	Scene();
	~Scene();

	void run();

protected:
	Object *player;
};

#endif
