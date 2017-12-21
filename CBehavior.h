/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#ifndef _C_BEHAVIOR_
#define _C_BEHAVIOR_

#include "CAnimation.h"

class CBehavior {
protected:
	CAnimation *animation;
public:
	virtual void Update()=0;
	virtual void Trigger()=0;
	virtual void Init()=0;
};

#endif