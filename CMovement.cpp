/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/


#include "CMovement.h"

void CMovement::handleCollision() 
{    
    if (velocity->x > 0)
    {
        prohibitedDirection = RIGHT;
    }
    
    if (velocity->x < 0)
    {
        prohibitedDirection = LEFT;
    }
    
    if (velocity->y > 0)
    {
        prohibitedDirection = DOWN;
    }
    
    if (velocity->y < 0)
    {
        prohibitedDirection = UP;
    }
    
    CState::Instance()->toggleAnimation(false);
    
    setState(ON_GROUND);
    
	velocity->Zero();
}

void CMovement::Warp(int x, int y)
{
#ifdef BETA_2
    if (!CTileMap::Instance()->isSolid((x+CTileMap::Instance()->getTileSize())+y * (CTileMap::Instance()->getXCount() * CTileMap::Instance()->getTileSize())))
    {
        position->x = x+CTileMap::Instance()->getTileSize();
        position->y = y;
    }
    
    if (!CTileMap::Instance()->isSolid((x-CTileMap::Instance()->getTileSize())+y * (CTileMap::Instance()->getXCount() * CTileMap::Instance()->getTileSize())))
    {
        position->x = x-CTileMap::Instance()->getTileSize();
        position->y = y;
    }
    
    if (!CTileMap::Instance()->isSolid((y+CTileMap::Instance()->getTileSize())+x * (CTileMap::Instance()->getXCount() * CTileMap::Instance()->getTileSize())))
    {
        position->x = x;
        position->y = y + CTileMap::Instance()->getTileSize();
    }
    
    if (!CTileMap::Instance()->isSolid((y-CTileMap::Instance()->getTileSize())+x * (CTileMap::Instance()->getXCount() * CTileMap::Instance()->getTileSize())))
    {
        position->x = x;
        position->y = y-CTileMap::Instance()->getTileSize();
    }
#endif
    
#ifndef BETA_2

	leaderBox->x = x-CApp::Instance()->getWidth()/2;
	leaderBox->y = y-CApp::Instance()->getHeight()/2;
    
#endif
}

void CMovement::print()
{
	std::cout << "Position: " << position->x << ", " << position->y << std::endl;
}

void CMovement::moveUp()
{
    if (prohibitedDirection == UP)
    {
        return;
    }
    else
    {
        prohibitedDirection = NONE;
    }
    
    CState::Instance()->toggleAnimation(true);
	velocity->y = -2;
	currentState = MOVING_UP;
}
void CMovement::moveDown()
{
    if (prohibitedDirection == DOWN)
    {
        return;
    }
    else
    {
        prohibitedDirection = NONE;
    }
    CState::Instance()->toggleAnimation(true);
	velocity->y = 2;
	currentState = MOVING_DOWN;
}

void CMovement::Update()
{	
	if (currentState == MOVING_DOWN) 
	{
		currentState = MOVING;
		CState::Instance()->setState(DOWN);
	}
	if (currentState == MOVING_UP) 
	{	
		currentState = MOVING;
		CState::Instance()->setState(UP);
	}
	if (currentState == MOVING_RIGHT)
	{
		CState::Instance()->setState(RIGHT);
		currentState = MOVING;
	}
	if (currentState == MOVING_LEFT)
	{
		CState::Instance()->setState(LEFT);
		currentState = MOVING;
	}	
	if (currentState == ON_GROUND)
	{
		CState::Instance()->toggleAnimation(true);
		velocity->x = 0;
		velocity->y = 0;
		return;
	}
	if (currentState == MOVING) 
	{
		CState::Instance()->toggleAnimation(false);
		if (position->x+CApp::Instance()->getWidth()/2 < 0)
		{
			position->x = -CApp::Instance()->getWidth()/2;
		}
		if (position->y+CApp::Instance()->getHeight()/2 < 0)
		{
			position->y = -CApp::Instance()->getHeight()/2;
		}
        				
		leaderBox->x+=velocity->x;
		leaderBox->y+=velocity->y;
    }	
}

void CMovement::moveRight()
{
    if (prohibitedDirection == RIGHT)
    {
        return;
    }
    else
    {
        prohibitedDirection = NONE;
    }
    CState::Instance()->toggleAnimation(true);
	velocity->x = 2;
	currentState = MOVING_RIGHT;
}
void CMovement::moveLeft()
{
    if (prohibitedDirection == LEFT)
    {
        return;
    }
    else
    {
        prohibitedDirection = NONE;
    }
    CState::Instance()->toggleAnimation(true);
	velocity->x = -2;
	currentState = MOVING_LEFT;
}

CMovement::CMovement(int incr) 
{
	movementIncrement = incr;
	position = new Vector2D(CApp::Instance()->getWidth()/2, CApp::Instance()->getHeight()/2); 
	velocity = new Vector2D(0, 0);
	drawOffset = new Vector2D;
	leaderBox = new Rectangle(position->x+3, position->y+10, CPlayer::Instance()->getWidth(), CPlayer::Instance()->getHeight());
    previousPosition = position;
	currentState = ON_GROUND;
}
CMovement::CMovement(int incr, int x) 
{
	movementIncrement = incr;
	position = new Vector2D(x, 240);
	velocity = new Vector2D(0, 0);
	currentState = ON_GROUND;
	drawOffset = new Vector2D;
    previousPosition = position;
}