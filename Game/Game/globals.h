#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <SDL.h>
#include "eventhandler.h"

namespace globals
{
	extern SDL_Renderer *renderer;
	extern EventHandler *handler;
}

#endif