/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CWarp.h"

CWarp::CWarp(int count)
{
	warpCount = count;
}
void CWarp::LoadWarps(FILE *fp)
{
	for (int y = 0; y < CTileMap::Instance()->getYCount(); y++)
	{
		for (int x = 0; x < CTileMap::Instance()->getXCount(); x++)
		{
			int tileID = CTileMap::Instance()->readInt(fp);
			if (tileID != 0)
			{
				Warp warp;
				warp.x = x*32;
				warp.y = y*32;
				warp.width = 32;
				warp.height = 32;
				warp.GID = tileID;
				
				warps.push_back(warp);
			}
		}
	}
}
void CWarp::Update()
{
	for (int index = 0; index < warps.size(); index++)
	{
		if (CCollision::Instance()->isCollision(warps[index].x, warps[index].y, warps[index].width, warps[index].height, CMovement::Instance()->getX()+CApp::Instance()->getWidth()/2, CMovement::Instance()->getY()+CApp::Instance()->getHeight()/2, CPlayer::Instance()->getWidth(), CPlayer::Instance()->getHeight())) 
		{
			int ID = warps[index].GID;
			for (int i = 0; i < warps.size(); i++)
			{
				if (warps[i].GID == 0) 
					continue;
				if (warps[i].GID == ID && i != index)
				{
					CSfx::Instance()->fade(0);
					CMovement::Instance()->Warp(warps[i].x, warps[i].y+32);
                    return;
				}
			}
		}
	}
}