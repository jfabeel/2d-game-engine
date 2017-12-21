/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#ifndef _C_MOVEMENT_
#define _C_MOVEMENT_

#include <iostream>
#include "Vector.h"
#include "CState.h"
#include "CCollision.h"
#include "Tilemap.h"
#include "CApp.h"
#include "structs.h"

class CCollision;

class CMovement {
private:
	Vector2D *position;
	Vector2D *velocity;
    Vector2D *previousPosition;
	Vector2D *drawOffset;
	Rectangle *leaderBox;
	int movementIncrement;
	int jumpTimer;
	State currentState;
	Direction currentDirection;
	int width;
	int height;
    Direction prohibitedDirection;
public:
	CMovement(int incr);
	CMovement(int incr, int x);
	void moveRight();
	void moveLeft();
	void Update();
    void drawLeaderBox() { 
        Color color;
        color.r = 1.0f;
        color.g = 0.0f;
        color.b = 1.0f;
        color.alpha = 1.0f;
        leaderBox->DebugDraw(color); 
    }
	Vector2D *getPosition() { return position; }
	void setState(State newState) { currentState = newState; }
	void setPosition(Vector2D *pos) { leaderBox->x = pos->x; leaderBox->y = pos->y;}
	int getX() { return leaderBox->x; }
	int getY() { return leaderBox->y; }
    int getCollisionWidth() { return leaderBox->w; }
    int getCollisionHeight() { return leaderBox->h; }
	void handleCollision();
	void moveUp();
	void moveDown();
	void print();
	void Warp(int x, int y);
	
	static CMovement *Instance() 
	{
		static CMovement inst(2);
		return &inst;
	}
};

#endif