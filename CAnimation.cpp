/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CAnimation.h"

CAnimation::CAnimation(GLfloat imageWidths, GLfloat imageHeights, GLfloat frameWidths, GLfloat frameHeights, GLfloat animationSpeeds, GLfloat currentRows) 
{
	imageWidth = imageWidths;
	imageHeight = imageHeights;
	frameWidth = frameWidths;
	frameHeight = frameHeights;
	animationSpeed = animationSpeeds;
	currentAnimationTime = 0.0f;
	
	animationKey = 0;
	nextFrameKey = 1;
	
	currentFrame = (animationKey)*(frameWidth/imageWidth);
	newFrame = (nextFrameKey)*(frameWidth/imageWidth);
	currentRow = currentRows;
	
	textureCoordinateX1 = currentFrame;
	textureCoordinateY1 = (currentRow) * (frameHeight/imageHeight);
	
	textureCoordinateX2 = newFrame;
	textureCoordinateY2 = (currentRow + 1) * (frameHeight/imageHeight);
}

CAnimation::CAnimation(GLfloat imageWidths, GLfloat imageHeights, GLfloat frameCountHorizontal, GLfloat frameCountVertical, GLfloat animationSpeeds, GLfloat currentRows, GLboolean pauseds)
{
	imageWidth = imageWidths;
	imageHeight = imageHeights;
	frameWidth = imageWidth/frameCountHorizontal;
	frameHeight = imageHeight/frameCountVertical;
	animationSpeed = animationSpeeds;
	currentAnimationTime = 0.0f;
	paused = pauseds;
	
	animationKey = 0;
	nextFrameKey = 1;
	
	currentFrame = (animationKey)*(frameWidth/imageWidth);
	newFrame = (nextFrameKey)*(frameWidth/imageWidth);
	currentRow = currentRows;
	
	textureCoordinateX1 = currentFrame;
	textureCoordinateY1 = (currentRow) * (frameHeight/imageHeight);
	
	textureCoordinateX2 = newFrame;
	textureCoordinateY2 = (currentRow + 1) * (frameHeight/imageHeight);
}

void CAnimation::Update() 
{
	if (paused) return;
	currentAnimationTime++;
	if (currentAnimationTime == animationSpeed) 
	{
		currentAnimationTime = 0;
		
		animationKey++;
		nextFrameKey++;
		
		currentFrame = (animationKey) * (frameWidth/imageWidth);
		newFrame = (nextFrameKey) * (frameWidth/imageWidth);
		
		if (newFrame > 1) 
		{
			animationKey = 0;
			nextFrameKey = 1;
			
			currentFrame = (animationKey) * (frameWidth/imageWidth);
			newFrame = (nextFrameKey) * (frameWidth/imageWidth);
		}
		
		textureCoordinateX1 = currentFrame;
		textureCoordinateY1 = (currentRow) * (frameHeight/imageHeight);
		
		textureCoordinateX2 = newFrame;
		textureCoordinateY2 = (currentRow + 1) * (frameHeight/imageHeight);
		
	}
}