/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#ifndef C_COLLISION_LAYER
#define C_COLLISION_LAYER

#include "defines.h"
#include "Rectangle.h"
#include "CCollision.h"
#include "CMovement.h"
#include "CTilesheet.h"
#include "CApp.h"
#include <vector>

using namespace std;

class CCollisionLayer {
private:
	int xTileCount;
	int yTileCount;
	CCollision *collision;
	std::vector <Rectangle*> rects;
	std::vector <bool> solids;
    
    Color rectangleColor;
public:    
	void Update(CTilesheet *tilesheet);
	CCollisionLayer();
	CCollisionLayer(int tileCountx, int tileCounty);
	void LoadLayer(FILE *fp);
    void Empty()
    {
        rects.empty();
        solids.empty();
        xTileCount = 0;
        yTileCount = 0;
    }
    bool isRectangleSolid(int indx);
};

#endif