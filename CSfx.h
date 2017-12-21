/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#ifndef C_SFX
#define C_SFX

#include "CRenderer.h"
#include "CApp.h"

class CSfx {
public:
	void fade(float a);
	static CSfx *Instance()
	{
		static CSfx inst;
		return &inst;
	}
};

#endif