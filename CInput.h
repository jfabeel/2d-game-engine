/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#ifndef C_INPUT
#define C_INPUT

#include "SDL.h"
#include <iostream>
#include "CApp.h"
#include "CMovement.h"
#include "Tilemap.h"
#include "CSfx.h"

class CInput {
public:
	void handleKeypress(SDL_Event *event);
	static CInput *Instance() 
	{
		static CInput inst;
		return &inst;
	}
};

#endif