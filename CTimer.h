/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#ifndef _C_TIMER_
#define _C_TIMER_
#include "defines.h"


class CTimer {
private:
	int currentTicks;
public:
	void GetTicks();
	void Update();
	
	static CTimer *Instance() {
		static CTimer inst;
		return &inst;
	}
};

#endif