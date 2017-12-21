/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifdef BETA
#ifndef C_MINIMAP
#define C_MINIMAP

#include <CRenderer.h>
#include <Tilemap.h>
#include <CApp.h>

class CMiniMap
{
private:
	GLfloat red;
	GLfloat blue;
	GLfloat green;
	GLfloat alpha;
public:
	void SetColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
	{
		red = r;
		blue = b;
		green = g;
		alpha = a;
	}
	void Update();
}

#endif

#endif