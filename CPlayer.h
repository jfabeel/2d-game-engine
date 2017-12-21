/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#ifndef C_PLAYER
#define C_PLAYER

#include "CTextureManager.h"
#include "CAnimation.h"
#include "CRenderer.h"
#include "CMovement.h"
#include "CSprite.h"

class CPlayer {
private:
	CSprite *sprite;
	GLfloat width;
	GLfloat height;
	GLfloat collisionWidth;
	GLfloat collisionHeight;
    
    int ID;
public:
    void Init(const char *filename, int frame_count, int row_count, int frame_speed);
	void Update();
	void Draw();
	
	static CPlayer *Instance() 
	{
		static CPlayer inst;
		return &inst;
	}
	void changeState(int state) 
	{
		sprite->SetRow(state-1);
	}
	
	void toggleAnimation(bool flag) 
	{
		sprite->PauseAnimation(flag);
	}
	
	GLfloat getWidth() { return collisionWidth; }
	GLfloat getHeight() { return collisionHeight; }
};

#endif