/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CPlayer.h"

void CPlayer::Init(const char *filename, int frame_count, int row_count, int frame_speed)
{
    sprite = new CSprite();
    sprite->SetImage(filename, frame_count, row_count, frame_speed);
    width = (sprite->getTextureWidth()/frame_count);
    height = (sprite->getTextureHeight()/row_count);
    
    collisionWidth = width-4;
    collisionHeight = height-9;
    
    ID = 0;
}

void CPlayer::Update() 
{
	CMovement::Instance()->Update();
    sprite->Update();
}

void CPlayer::Draw() 
{
	glPushMatrix();
	glTranslatef(CApp::Instance()->getWidth()/2, CApp::Instance()->getHeight()/2, 0.0);
    sprite->Render(CMovement::Instance()->getX()-3, CMovement::Instance()->getY()-9, width, height);
#ifdef TEXT_TEST
    CRenderer::Instance()->setColor(1.0f, 0.0f, 0.0f);
    CRenderer::Instance()->drawText(CMovement::Instance()->getX(), CMovement::Instance()->getY(), "Hello world");
#endif
#ifdef DEBUG_DRAW
    CMovement::Instance()->drawLeaderBox();
#endif
	glPopMatrix();
}