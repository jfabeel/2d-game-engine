/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CInput.h"

void CInput::handleKeypress(SDL_Event *event) 
{
	if (event->type == SDL_QUIT) {
		CApp::Instance()->Exit();
	}
	if (event->type == SDL_KEYDOWN) {
		if (event->key.keysym.sym == SDLK_p)
		{
			CMovement::Instance()->print();
		}
		if (event->key.keysym.sym == SDLK_RIGHT)
			CMovement::Instance()->moveRight();
		else if (event->key.keysym.sym == SDLK_UP)
			CMovement::Instance()->moveUp();
		if (event->key.keysym.sym == SDLK_LEFT)
			CMovement::Instance()->moveLeft();
		else if (event->key.keysym.sym == SDLK_DOWN)
			CMovement::Instance()->moveDown();
		switch (event->key.keysym.sym) {
			case SDLK_ESCAPE:
				CApp::Instance()->Exit();
				break;
			case SDLK_SPACE:
				CApp::Instance()->TogglePause();
                break;
        }
	}
	if (event->type == SDL_KEYUP) {
		if (event->key.keysym.sym == SDLK_RIGHT)
			CMovement::Instance()->setState(ON_GROUND);
		if (event->key.keysym.sym == SDLK_LEFT)
			CMovement::Instance()->setState(ON_GROUND);
		if (event->key.keysym.sym == SDLK_UP)
			CMovement::Instance()->setState(ON_GROUND);
		if (event->key.keysym.sym == SDLK_DOWN)
			CMovement::Instance()->setState(ON_GROUND);
#ifdef BETA
		if (event->key.keysym.sym == SDLK_f)
			CApp::Instance()->toggleFullscreen();
#endif
	}
}