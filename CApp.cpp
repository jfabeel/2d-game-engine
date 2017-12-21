/*
 *  CApp.cpp
 *  SDL_TUTORIAL
 *
 *  Created by Jack on 9/26/10.
 *  Copyright 2010 Never Ending Software. All rights reserved.
 *
 */

//#define DEBUG


#include "CApp.h"
#include <SDL_ttf/SDL_ttf.h>
#include <string>

using namespace std;

static void initAttributes ()
{    
    int value;
    
    value = 16;
    SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE, value);
    
    value = 1;
    SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, value);
}

CApp::CApp() {
	srand(time(NULL));
	running = true;
	keyHold = false;
}
CApp::CApp(bool keyRepeat) {
	keyHold = keyRepeat;
	running = true;
}
bool CApp::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	
	keyHold = false;
	
	SDL_EnableKeyRepeat(70, 70);
	
	initAttributes ();
	const SDL_VideoInfo *video;
	video = SDL_GetVideoInfo();
    
	screenWidth = video->current_w;
	screenHeight = video->current_h;
    	
#ifdef DEBUG
	width = 640;
	height = 480;
#endif
#ifndef DEBUG 
    width = screenWidth;
    height = screenHeight;
#endif
    Uint32 flags = 0;
    
    flags = SDL_OPENGL;
#ifndef DEBUG
	flags |= SDL_FULLSCREEN;
#endif
    gScreen = SDL_SetVideoMode (width, height, 0, flags);
    if (gScreen == NULL) {
		
        fprintf (stderr, "Couldn't set 640x480 OpenGL video mode: %s\n",
                 SDL_GetError());
		SDL_Quit();
		exit(2);
	}
	
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#ifndef LUA
	CPlayer::Instance()->Init();
	CTileMap::Instance()->LoadTilesheet("tileset2.bmp", 32);
    CTileMap::Instance()->LoadFile("testmap4-real.txt");
#endif
        
#ifdef BETA_1
    CQuadrantManager::Instance()->CreateWorld(0, 0, CTileMap::Instance()->getXCount()*CTileMap::Instance()->getTileSize(), CTileMap::Instance()->getYCount() * CTileMap::Instance()->getTileSize());
#endif
    
	TTF_Init();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
#ifdef LUA
    CLua::Instance()->Init();
#endif

	return true;
}

void CApp::TogglePause() {
	if (paused == true) {
		paused = false;
		return;
	}
	if (paused == false) {
		paused = true;
		return;
	}
}

bool CApp::Loop() {
	if (paused) return true;
    CLua::Instance()->Update();
	CPlayer::Instance()->Update();
	return true;
}

void CApp::toggleFullscreen()
{
	fullscreen = !fullscreen;
	if (fullscreen)
	{
        initAttributes ();

        Uint32 flags = 0;
        
        flags = SDL_OPENGL;
        flags |= SDL_FULLSCREEN;

        gScreen = SDL_SetVideoMode (screenWidth, screenHeight, 0, flags);
        if (gScreen == NULL) {
            
            fprintf (stderr, "Couldn't set 640x480 OpenGL video mode: %s\n",
                     SDL_GetError());
            SDL_Quit();
            exit(2);
        }
        
        width = screenWidth;
        height = screenHeight;
        
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, screenWidth, screenHeight, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
	}
	if (!fullscreen)
	{
        initAttributes ();

        width = 640;
        height = 480;

        Uint32 flags = 0;
        
        flags = SDL_OPENGL;

        gScreen = SDL_SetVideoMode (width, height, 0, flags);
        if (gScreen == NULL) {
            
            fprintf (stderr, "Couldn't set 640x480 OpenGL video mode: %s\n",
                     SDL_GetError());
            SDL_Quit();
            exit(2);
        }
        
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glOrtho(0, width, height, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
	}
}

bool CApp::Exit() {
	running = false;
	return true;
}
bool CApp::Render() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	CTileMap::Instance()->Update();
	if (paused)
	{
		CRenderer::Instance()->setColor(0.0, 1.0, 0.0, 1.0);
        CRenderer::Instance()->drawRectangle(width/2-25, height/2-25, 100, 100, 1.0, 1.0, 1.0, 1.0);
		
	}
    glPopMatrix();
    glFlush();
	SDL_GL_SwapBuffers ();
	return true;
}
bool CApp::Cleanup() {
#ifdef LUA
    CLua::Instance()->Cleanup();
#endif
	SDL_Quit();
	return true;
}

bool CApp::UpdateEvents(SDL_Event *event) {
	while (SDL_PollEvent(event)) {
		CInput::Instance()->handleKeypress(event);
	}
	return true;
}

int CApp::Execute() {
	if (Init() == false) {
		return -1;
	}
	SDL_Event Event;
	while (running) {
		CTimer::Instance()->GetTicks();
		UpdateEvents(&Event);
		Loop();
		Render();
		CTimer::Instance()->Update();
	}
	Cleanup();
	return 0;
}