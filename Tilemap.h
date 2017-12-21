/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef C_TILE_MAP
#define C_TILE_MAP

#include "Rectangle.h"
#include "CLayer.h"
#include "CCollisionLayer.h"
#include "Vector.h"
#include "CTilesheet.h"
#include "CMovement.h"
#include "CWarp.h"
#include "CQuadrantManager.h"

class CLayer;
class CCollisionLayer;
class CWarp;

class CTileMap {
private:
	Vector2D drawOffset;
	CLayer *backgroundLayer;
	CLayer *firstLayer;
	CLayer *secondLayer;
	CCollisionLayer *collisionLayer; 
	CWarp *warpLayer;
	
	int xTileCount;
	int yTileCount;
	int warpCount;
	CTilesheet *tilesheet;
public:
	void Update();
	void LoadFile(const char *filename);
	void LoadTilesheet(const char *filename, int tilesize);
	int getWorldCameraX() { return drawOffset.x; }
	int getWorldCameraY() { return drawOffset.y; }
	int getXCount() {return xTileCount;}
	int getYCount() {return yTileCount;}
    int getTileSize() { return tilesheet->getTileSize(); }
	Rectangle *CreateRect(int x, int y, int height, int width);
#ifdef BETA_2
	bool isSolid(int indx) { return collisionLayer->isRectangleSolid(indx); }
#endif
	int readInt(FILE *fp);
	void print() { std::cout << "World Camera X: " << getWorldCameraX() << " World Camera Y: " << getWorldCameraY() << std::endl; }
	
	static CTileMap *Instance() {
		static CTileMap inst;
		return &inst;
	}
};

#endif