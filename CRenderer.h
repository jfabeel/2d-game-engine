/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#ifndef _C_CRenderer
#define _C_CRenderer
#include <math.h>
#include <GLUT/GLUT.h>
#include "CTextureManager.h"
#include "SDL_opengl.h"
#include "defines.h"
#include "structs.h"


class CRenderer {
private:
	Color *current_color;
public:
    CRenderer();
    
	void drawRectangle(int x, int y, int width, int height, GLuint textureID, float texCoordX, float texCoordY, float texCoordX2, float texCoordY2);
	void drawRectangle(int x, int y, int width, int height, GLuint textureID);
	void drawRectangle(int x, int y, int width, int height);
	void drawRectangle(int x, int y, int width, int height, Color *colors[4]);
    void drawRectangle(int x, int y, int width, int height, float red, float blue, float green, float alpha);
	void drawPixel(int x, int y);
	void drawCircle(int x, int y, int radius);
	void setColor(float r, float g, float b);
	void drawText(int x, int y, const char *str);
	void setAlpha(float alpha);
	void setColor(float r, float g, float b, float alpha);
	void drawHollowRectangle(int x, int y, int width, int height);
    void drawHollowRectangle(int x, int y, int width, int height, float red, float blue, float green, float alpha);
    
    static CRenderer *Instance() {
		static CRenderer inst;
		return &inst;
	}
};

#endif