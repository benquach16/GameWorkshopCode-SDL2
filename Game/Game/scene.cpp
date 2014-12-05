#include "stdafx.h"
#include "scene.h"
#include "globals.h"

Scene::Scene()
{
	player = new Object(
		"Resources/Art/pacman.bmp",
		Vector2(100, 0),
		0.0f,
		Vector2(100, 100));

	new Object(
		"Resources/Art/pacman.bmp",
		Vector2(100, 300),
		0.0f,
		Vector2(100, 100));
}

Scene::~Scene()
{

}

void Scene::run()
{
	if (globals::handler->isKeyDown(SDLK_w))
	{
		//game stuff goes here
		Vector2 newPosition = player->getPosition();
		newPosition.y--;
		player->setPosition(newPosition);
	}
	if (globals::handler->isKeyDown(SDLK_s))
	{
		//game stuff goes here
		Vector2 newPosition = player->getPosition();
		newPosition.y++;
		player->setPosition(newPosition);
	}

	for (unsigned i = 0; i < Object::allObjects.size(); i++)
	{
		Object::allObjects[i]->run();
	}
}