/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef _C_ANIMATION_
#define _C_ANIMATION_

#include "SDL_opengl.h"

#include <iostream>
#include "structs.h"


class CAnimation {
private:
	GLfloat currentFrame;
	GLfloat newFrame;
	GLfloat imageWidth;
	GLfloat imageHeight;
	GLfloat frameWidth;
	GLfloat frameHeight;
	
	GLint animationKey;
	GLint nextFrameKey;
	
	GLfloat animationSpeed;
	GLfloat currentAnimationTime;
	
	GLfloat textureCoordinateX1;
	GLfloat textureCoordinateY1;
	GLfloat textureCoordinateX2;
	GLfloat textureCoordinateY2;
	
	GLfloat currentRow;
	GLboolean paused;
public:
	void Update();
	void setRow(float row) { currentRow = row; }
	void toggleAnimation(GLboolean flag) { paused = flag; }
	CAnimation(GLfloat imageWidths, GLfloat imageHeights, GLfloat frameWidths, GLfloat frameHeights, GLfloat animationSpeeds, GLfloat currentRows); 
	CAnimation(GLfloat imageWidths, GLfloat imageHeights, GLfloat frameCountHorizontal, GLfloat frameCountVertical, GLfloat animationSpeeds, GLfloat currentRows, GLboolean pauseds);
	TextureCoordinates getTextureCoordinates() 
	{
		TextureCoordinates coords;
		coords.s1 = textureCoordinateX1;
		coords.t1 = textureCoordinateY1;
		coords.s2 = textureCoordinateX2;
		coords.t2 = textureCoordinateY2;
		
		return coords;
	}
};
#endif