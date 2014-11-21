#ifndef __EVENTHANDLER_H__
#define __EVENTHANDLER_H__

#include <SDL.h>

class EventHandler
{
public:
	EventHandler();
	~EventHandler();
	void getEvent();
	bool isKeyDown(SDL_Keycode key);
	
protected:
	bool keys[256];
};

#endif
