/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CSfx.h"

void CSfx::fade(float a) 
{
	if(a < 1.0f)
	{ 
		if (!glIsEnabled(GL_BLEND)) glEnable(GL_BLEND);
		SDL_Delay(50);
        glPushMatrix();
        CRenderer::Instance()->drawRectangle(0, 0, CApp::Instance()->getWidth(), CApp::Instance()->getHeight(), 0.0f, 0.0f, 0.0f, a);
        glPopMatrix();
		SDL_GL_SwapBuffers();
		fade(a + 0.01f);
	}
}