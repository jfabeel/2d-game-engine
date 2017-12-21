/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CLayer.h"

using namespace std;

CLayer::CLayer(int tileCountX, int tileCountY)
{
	xTileCount = tileCountX;
	yTileCount = tileCountY;	
}
void CLayer::Update(CTilesheet *tilesheet)
{
	for (int index = 0; index < tiles.size(); index++) 
	{
#ifndef SHOW_CULLING
		if (!CCollision::Instance()->isCollision(tiles[index].x, tiles[index].y, 32, 32, CTileMap::Instance()->getWorldCameraX() * -1, CTileMap::Instance()->getWorldCameraY() * -1, CApp::Instance()->getWidth()+tilesheet->getTileSize(), CApp::Instance()->getHeight()+tilesheet->getTileSize()))
		{
			continue;
		}
#endif
#ifdef SHOW_CULLING
		if (!CCollision::Instance()->isCollision(tiles[index].x, tiles[index].y, 672, 512, CTileMap::Instance()->getWorldCameraX() * -1, CTileMap::Instance()->getWorldCameraY() * -1, 672, 512))
		{
			continue;
		}	
#endif
		int desiredTile = tiles[index].GID;
		if (desiredTile == 0) continue;
        TextureCoordinates coordinate = getTextureCoordinatesForTile(desiredTile);
		CRenderer::Instance()->drawRectangle(tiles[index].x, tiles[index].y, tiles[index].width, tiles[index].height, tilesheet->getTilesheetID(), coordinate.s1, coordinate.t1, coordinate.s2, coordinate.t2); 
	}
}

void CLayer::LoadLayer(FILE *fp, CTilesheet *tilesheet) 
{
	for (int y = 0; y < yTileCount; y++) {
		for (int x = 0; x < xTileCount; x++) 
		{ 
			Tile tile;
			tile.x = x*32;
			tile.y = y*32;
			tile.width = 32;
			tile.height = 32;
			tile.GID = CTileMap::Instance()->readInt(fp);
			
			tiles.push_back(tile);
		}
	}
    
    for (int x = 0; x < tilesheet->getXTileCount()*tilesheet->getYTileCount(); x++)
    {
        cache.push_back(tilesheet->getTilesheetCoordinates(x));
    }
}
