/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CCollisionLayer.h"

CCollisionLayer::CCollisionLayer()
{
    xTileCount = 0;
    yTileCount = 0;
}

CCollisionLayer::CCollisionLayer(int tileCountx, int tileCounty)
{
	xTileCount = tileCountx;
	yTileCount = tileCounty;
    collision = new CCollision;
    
    rectangleColor.r = 1.0f;
    rectangleColor.g = 1.0f;
    rectangleColor.b = 1.0f;
    rectangleColor.alpha = 1.0f;
}

void CCollisionLayer::LoadLayer(FILE *fp)
{
    int index = 0;
	for (int y = 0; y < yTileCount; y++) {
		for (int x = 0; x < xTileCount; x++)  { 
			int number = CTileMap::Instance()->readInt(fp);
			if (number== 1)
			{
				solids.push_back(1);
				Rectangle *rect = new Rectangle((x*32), (y*32), 32, 32);
				rects.push_back(rect);
                index++;
#ifdef BETA_1
                CQuadrantManager::Instance()->getQuadrantAtPosition(x*32, y*32)->addID(index);
#endif
			}
		}
	}
}

void CCollisionLayer::Update(CTilesheet *tilesheet) 
{	
	for (int i = 0; i < rects.size(); i++)
	{
#ifdef BETA_1
        if (!CQuadrantManager::Instance()->getQuadrantAtPosition(CMovement::Instance()->getCollisionX()+CApp::Instance()->getWidth()/2, CMovement::Instance()->getCollisionY()+CApp::Instance()->getHeight()/2)->IncludesID(i+1))
        {
            return;
        }
#endif
#ifdef DEBUG_DRAW
		rects[i]->DebugDraw(rectangleColor);
#endif
		if (collision->isCollision(rects[i], CMovement::Instance()->getX()+CApp::Instance()->getWidth()/2, CMovement::Instance()->getY()+CApp::Instance()->getHeight()/2, CMovement::Instance()->getCollisionWidth(), CMovement::Instance()->getCollisionHeight()))
		{
			CMovement::Instance()->handleCollision();
			return;
		}
	}
}

bool CCollisionLayer::isRectangleSolid(int indx)
{
    {	
		if (solids[indx])
			return true;
		else 
			return false;
	}
}