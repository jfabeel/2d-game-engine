/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "Vector.h"
#include "Rectangle.h"

class CCollision {
public:
    bool isCollision(Rectangle *A, int x2, int y2, int width2, int height2);
	bool isCollision(Rectangle *A, Rectangle *B);
    bool isCollision(int x1, int y1, int width1, int height1, int x, int y, int width, int height);
	
	static CCollision *Instance() {
		static CCollision inst;
		return &inst;
	}
};
#endif