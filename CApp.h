/*
 *  CApp.h
 *  SDL_TUTORIAL
 *
 *  Created by Jack on 9/26/10.
 *  Copyright 2010 Never Ending Software. All rights reserved.
 *
 */

#ifndef _C_APP_
#define _C_APP_

#include "SDL.h"
#include <time.h>
#include "CInput.h"
#include "Tilemap.h"
#include "CTimer.h"
#include <SDL_mixer/SDL_mixer.h>
#include <CSounds.h>
#include "CLua.h"

class CApp {
private:
	float fps;
	bool paused;
	SDL_Surface *gScreen;
	int width;
	int height;
    int screenHeight;
    int screenWidth;
	bool fullscreen;
public:
	bool running;
	bool keyHold;
	CApp();
	CApp(bool keyRepeat);
	static CApp *Instance() {
		static CApp inst;
		return &inst;
	}
	int Execute();
	bool Init();
	bool Loop();
	bool Render();
	bool Cleanup();
	bool Exit();
	bool UpdateEvents(SDL_Event *event);
	int getWidth() { return width; }
	int getHeight() { return height; }
	void TogglePause();
	SDL_Surface *getSurface() { return gScreen; }
	void toggleFullscreen();
};
#endif