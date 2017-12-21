/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CTimer.h"

void CTimer::GetTicks() {
	currentTicks = SDL_GetTicks();
}
void CTimer::Update() {
	if (SDL_GetTicks() - currentTicks < 1000/MAX_FPS) {
		SDL_Delay((int)(1000/MAX_FPS)-(SDL_GetTicks()-currentTicks));
	}
}