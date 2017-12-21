/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef C_STATE
#define C_STATE

#include "CPlayer.h"

class CState {
public:
	void setState(int state);
	void toggleAnimation(bool flag);
	static CState *Instance()
	{
		static CState inst;
		return &inst;
	}
};

#endif