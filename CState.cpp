/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CState.h"

void CState::setState(int state)
{
	CPlayer::Instance()->changeState(state);
}

void CState::toggleAnimation(bool flag)
{
	CPlayer::Instance()->toggleAnimation(flag);
}